#include "ui_modbus_list.h"
#include "ui_modbus_backend.h"
#include "ui_screen_controller.h"
#include "ui_platform_port.h"
#include "gui_guider.h"
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Style Constants (matching the generated UI theme) --- */
#define LIST_ROW_HEIGHT     40
#define LIST_ROW_GAP        2
#define LIST_START_Y        70   /* Below the header row (cont_70) */
#define LIST_ROW_WIDTH      612
#define LIST_TEXT_COLOR      0xCBD5E1  /* Light gray */
#define LIST_ROW_BG_COLOR    0x1E293B  /* Dark blue-gray */
#define LIST_ROW_BG_OPA      120
#define LIST_DEL_COLOR       0xEF4444  /* Red for delete */
#define LIST_EDIT_COLOR      0x3B82F6  /* Blue for edit */

/* Container where dynamic rows will be added (cont_69 inside cont_68) */
static lv_obj_t *s_list_container = NULL;

/* Track dynamically created row objects so we can clean them up */
static lv_obj_t *s_rows[MBS_MAX_COMMANDS];
static uint16_t s_row_count = 0;

static void delete_btn_cb(lv_event_t *e) {
    uint32_t idx = (uint32_t)(uintptr_t)lv_event_get_user_data(e);
    ui_modbus_backend_remove_cmd((uint16_t)idx);
    ui_modbus_list_render();
}

static void edit_btn_cb(lv_event_t *e) {
    uint32_t idx = (uint32_t)(uintptr_t)lv_event_get_user_data(e);
    uint16_t count = 0;
    const mbs_command_t *list = ui_modbus_backend_get_list(&count);
    if (idx >= count) return;

    lv_ui *g = &guider_ui;
    char buf[16];

    /* Pre-fill form fields with selected command data */
    snprintf(buf, sizeof(buf), "%d", list[idx].id);
    lv_textarea_set_text(g->scr_base_ta_master_device_slaveid, buf);

    snprintf(buf, sizeof(buf), "%d", list[idx].reg_addr);
    lv_textarea_set_text(g->scr_base_ta_master_device_address, buf);

    snprintf(buf, sizeof(buf), "%d", list[idx].reg_quantity);
    lv_textarea_set_text(g->scr_base_ta_master_device_quantity, buf);

    /* Map function code back to dropdown index */
    uint8_t func = list[idx].func;
    uint16_t dd_idx = 0;
    static const uint8_t func_map[] = {1, 2, 3, 4, 5, 6, 15, 16};
    for (uint16_t j = 0; j < sizeof(func_map)/sizeof(func_map[0]); j++) {
        if (func_map[j] == func) { dd_idx = j; break; }
    }
    lv_dropdown_set_selected(g->scr_base_ddlist_master_device_registers, dd_idx);

    /* Remove the old entry (the Apply will re-add it with potentially updated values) */
    ui_modbus_backend_remove_cmd((uint16_t)idx);

    /* Navigate to the device config screen */
    ui_screen_controller_dispatch(ui_context_get(), UI_ACTION_SHOW_MODBUS_DEVICE_CONFIG, 0);
}

static void clear_rows(void) {
    for (uint16_t i = 0; i < s_row_count; i++) {
        if (s_rows[i] && lv_obj_is_valid(s_rows[i])) {
            lv_obj_delete(s_rows[i]);
        }
        s_rows[i] = NULL;
    }
    s_row_count = 0;
}

static lv_obj_t *create_cell_label(lv_obj_t *parent, lv_coord_t x, lv_coord_t w,
                                    const char *text) {
    lv_obj_t *lbl = lv_label_create(parent);
    lv_obj_set_pos(lbl, x, 0);
    lv_obj_set_size(lbl, w, LIST_ROW_HEIGHT);
    lv_label_set_text(lbl, text);
    lv_label_set_long_mode(lbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(lbl, lv_color_hex(LIST_TEXT_COLOR), LV_PART_MAIN);
    lv_obj_set_style_text_font(lbl, &lv_font_Roboto_Bold_12, LV_PART_MAIN);
    lv_obj_set_style_text_align(lbl, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN);
    lv_obj_set_style_pad_top(lbl, 13, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(lbl, 0, LV_PART_MAIN);
    return lbl;
}

void ui_modbus_list_init(void) {
    ui_modbus_backend_init();
    s_list_container = NULL;
    s_row_count = 0;
    memset(s_rows, 0, sizeof(s_rows));
}

void ui_modbus_list_render(void) {
    lv_ui *g = &guider_ui;

    /* cont_69 is the scrollable area inside the viewlist panel */
    s_list_container = g->scr_base_cont_69;
    if (!s_list_container || !lv_obj_is_valid(s_list_container)) return;

    /* Enable vertical scrolling for the list container */
    lv_obj_set_scrollbar_mode(s_list_container, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_clear_flag(s_list_container, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);

    /* Remove old dynamic rows */
    clear_rows();

    uint16_t count = 0;
    const mbs_command_t *list = ui_modbus_backend_get_list(&count);
    char buf[32];

    for (uint16_t i = 0; i < count && i < MBS_MAX_COMMANDS; i++) {
        lv_obj_t *row = lv_obj_create(s_list_container);
        lv_obj_set_pos(row, 0, LIST_START_Y + i * (LIST_ROW_HEIGHT + LIST_ROW_GAP));
        lv_obj_set_size(row, LIST_ROW_WIDTH, LIST_ROW_HEIGHT);
        lv_obj_set_scrollbar_mode(row, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_radius(row, 0, LV_PART_MAIN);
        lv_obj_set_style_bg_opa(row, LIST_ROW_BG_OPA, LV_PART_MAIN);
        lv_obj_set_style_bg_color(row, lv_color_hex(LIST_ROW_BG_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_width(row, 0, LV_PART_MAIN);
        lv_obj_set_style_pad_all(row, 0, LV_PART_MAIN);

        /* Column: STT */
        snprintf(buf, sizeof(buf), "%d", i + 1);
        create_cell_label(row, 14, 36, buf);

        /* Column: SLAVE ID */
        snprintf(buf, sizeof(buf), "%d", list[i].id);
        create_cell_label(row, 70, 85, buf);

        /* Column: REGISTER TYPE */
        create_cell_label(row, 170, 170, ui_modbus_backend_func_name(list[i].func));

        /* Column: QUANTITY */
        snprintf(buf, sizeof(buf), "%d", list[i].reg_quantity);
        create_cell_label(row, 380, 103, buf);

        /* Column: ACTION - Edit & Delete icon buttons */
        lv_obj_t *edit_btn = lv_button_create(row);
        lv_obj_set_pos(edit_btn, 524, 5);
        lv_obj_set_size(edit_btn, 34, 30);
        lv_obj_set_style_bg_opa(edit_btn, 0, LV_PART_MAIN);
        lv_obj_set_style_border_width(edit_btn, 1, LV_PART_MAIN);
        lv_obj_set_style_border_color(edit_btn, lv_color_hex(LIST_EDIT_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_opa(edit_btn, 180, LV_PART_MAIN);
        lv_obj_set_style_radius(edit_btn, 6, LV_PART_MAIN);
        lv_obj_set_style_shadow_width(edit_btn, 0, LV_PART_MAIN);
        lv_obj_set_style_bg_opa(edit_btn, 80, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(edit_btn, lv_color_hex(LIST_EDIT_COLOR), LV_PART_MAIN | LV_STATE_PRESSED);

        lv_obj_t *edit_lbl = lv_label_create(edit_btn);
        lv_label_set_text(edit_lbl, LV_SYMBOL_EDIT);
        lv_obj_center(edit_lbl);
        lv_obj_set_style_text_color(edit_lbl, lv_color_hex(LIST_EDIT_COLOR), LV_PART_MAIN);
        lv_obj_set_style_text_font(edit_lbl, &lv_font_montserratMedium_16, LV_PART_MAIN);
        lv_obj_add_event_cb(edit_btn, edit_btn_cb, LV_EVENT_SHORT_CLICKED, (void *)(uintptr_t)i);

        lv_obj_t *del_btn = lv_button_create(row);
        lv_obj_set_pos(del_btn, 564, 5);
        lv_obj_set_size(del_btn, 34, 30);
        lv_obj_set_style_bg_opa(del_btn, 0, LV_PART_MAIN);
        lv_obj_set_style_border_width(del_btn, 1, LV_PART_MAIN);
        lv_obj_set_style_border_color(del_btn, lv_color_hex(LIST_DEL_COLOR), LV_PART_MAIN);
        lv_obj_set_style_border_opa(del_btn, 180, LV_PART_MAIN);
        lv_obj_set_style_radius(del_btn, 6, LV_PART_MAIN);
        lv_obj_set_style_shadow_width(del_btn, 0, LV_PART_MAIN);
        lv_obj_set_style_bg_opa(del_btn, 80, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(del_btn, lv_color_hex(LIST_DEL_COLOR), LV_PART_MAIN | LV_STATE_PRESSED);

        lv_obj_t *del_lbl = lv_label_create(del_btn);
        lv_label_set_text(del_lbl, LV_SYMBOL_TRASH);
        lv_obj_center(del_lbl);
        lv_obj_set_style_text_color(del_lbl, lv_color_hex(LIST_DEL_COLOR), LV_PART_MAIN);
        lv_obj_set_style_text_font(del_lbl, &lv_font_montserratMedium_16, LV_PART_MAIN);
        lv_obj_add_event_cb(del_btn, delete_btn_cb, LV_EVENT_SHORT_CLICKED, (void *)(uintptr_t)i);

        s_rows[s_row_count++] = row;
    }

    /* Submit JSON output via Platform Port */
    char *json = ui_modbus_backend_to_json();
    if (json) {
        ui_platform_port_submit_json(UI_PLATFORM_TOPIC_MODBUS_CONFIG, json);
        cJSON_free(json);
    }
}

void ui_modbus_list_handle_apply(ui_context_t *ui) {
    if (!ui) return;

    lv_ui *g = &guider_ui;

    /* Read Slave ID from textarea */
    const char *slave_str = lv_textarea_get_text(g->scr_base_ta_master_device_slaveid);
    uint8_t slave_id = (uint8_t)atoi(slave_str ? slave_str : "0");

    /* Read register address from textarea */
    const char *addr_str = lv_textarea_get_text(g->scr_base_ta_master_device_address);
    uint16_t reg_addr = (uint16_t)atoi(addr_str ? addr_str : "0");

    /* Read quantity from textarea */
    const char *qty_str = lv_textarea_get_text(g->scr_base_ta_master_device_quantity);
    uint16_t reg_qty = (uint16_t)atoi(qty_str ? qty_str : "0");

    /* Read function code from dropdown */
    uint16_t dd_sel = lv_dropdown_get_selected(g->scr_base_ddlist_master_device_registers);
    uint8_t func = ui_modbus_backend_dd_index_to_func(dd_sel);

    /* Add to backend */
    if (slave_id > 0 && reg_qty > 0 && func > 0) {
        ui_modbus_backend_add_cmd(slave_id, func, reg_addr, reg_qty);
    }

    /* Clear form fields for next entry */
    lv_textarea_set_text(g->scr_base_ta_master_device_slaveid, "");
    lv_textarea_set_text(g->scr_base_ta_master_device_address, "");
    lv_textarea_set_text(g->scr_base_ta_master_device_quantity, "");
    lv_dropdown_set_selected(g->scr_base_ddlist_master_device_registers, 0);
}
