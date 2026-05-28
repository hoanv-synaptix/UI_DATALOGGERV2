#include "cmp_modbus_list.h"
#include "modbus_config_service.h"
#include "ctrl_screen.h"
#include "gui_guider.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Hằng số định dạng Giao diện (Style) --- */
#define LIST_ROW_HEIGHT     40           /* Chiều cao mỗi dòng */
#define LIST_ROW_GAP        2            /* Khoảng cách giữa các dòng */
#define LIST_START_Y        70           /* Bắt đầu vẽ từ tọa độ Y = 70 (chừa chỗ cho Header) */
#define LIST_ROW_WIDTH      612          /* Chiều ngang mỗi dòng */
#define LIST_TEXT_COLOR      0xCBD5E1    /* Màu chữ: Xám nhạt */
#define LIST_ROW_BG_COLOR    0x1E293B    /* Màu nền dòng: Xanh đen nhạt */
#define LIST_ROW_BG_OPA      120         /* Độ trong suốt nền dòng */
#define LIST_DEL_COLOR       0xEF4444    /* Màu viền nút Xóa: Đỏ */
#define LIST_EDIT_COLOR      0x3B82F6    /* Màu viền nút Sửa: Xanh dương */

/* Khung chứa các dòng thiết bị (container sinh tự động bởi GUI Guider) */
static lv_obj_t *s_list_container = NULL;

/* Mảng lưu con trỏ đến các dòng giao diện (để có thể xóa/giải phóng bộ nhớ sau này) */
static lv_obj_t *s_rows[MBS_MAX_COMMANDS];
static uint16_t s_row_count = 0;

/**
 * @brief Xử lý khi người dùng bấm nút Xóa (Thùng rác)
 */
static void delete_btn_cb(lv_event_t *e) {
    // Ép kiểu ngược từ con trỏ để lấy Index của dòng bị bấm
    uint32_t idx = (uint32_t)(uintptr_t)lv_event_get_user_data(e);
    ui_screen_controller_dispatch(view_factory_get(), UI_ACTION_DELETE_MODBUS_DEVICE, (uint16_t)idx);
}

/**
 * @brief Xử lý khi người dùng bấm nút Sửa (Cây bút)
 */
static void edit_btn_cb(lv_event_t *e) {
    uint32_t idx = (uint32_t)(uintptr_t)lv_event_get_user_data(e);
    uint16_t count = 0;
    const MBS_Command_t *list = modbus_config_get_list(&count);
    if (idx >= count) return;

    lv_ui *g = &guider_ui;
    char buf[16];

    /* Tải dữ liệu của dòng đó vào các ô Text Input của Form */
    snprintf(buf, sizeof(buf), "%d", list[idx].id);
    lv_textarea_set_text(g->scr_base_ta_master_device_slaveid, buf);

    snprintf(buf, sizeof(buf), "%d", list[idx].reg_addr);
    lv_textarea_set_text(g->scr_base_ta_master_device_address, buf);

    snprintf(buf, sizeof(buf), "%d", list[idx].reg_quantity);
    lv_textarea_set_text(g->scr_base_ta_master_device_quantity, buf);

    snprintf(buf, sizeof(buf), "%d", list[idx].reg_addr_remap);
    lv_textarea_set_text(g->scr_base_ta_master_device_register_mapping, buf);

    /* Chuyển đổi mã Function Code sang Index của hộp Dropdown */
    uint8_t func = list[idx].func;
    uint16_t dd_idx = 0;
    static const uint8_t func_map[] = {1, 2, 3, 4, 5, 6, 15, 16};
    for (uint16_t j = 0; j < sizeof(func_map)/sizeof(func_map[0]); j++) {
        if (func_map[j] == func) { dd_idx = j; break; }
    }
    lv_dropdown_set_selected(g->scr_base_ddlist_master_device_registers, dd_idx);

    /* Chuyển việc quản lý Xóa và chuyển Form cho Controller */
    ui_screen_controller_dispatch(view_factory_get(), UI_ACTION_EDIT_MODBUS_DEVICE, (uint16_t)idx);
}

/**
 * @brief Xóa toàn bộ các Object LVGL của bảng để vẽ lại từ đầu.
 * Nếu không giải phóng, ứng dụng sẽ bị tràn RAM (Memory Leak).
 */
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
    lv_obj_set_style_text_font(lbl, &lv_font_Roboto_Bold_13, LV_PART_MAIN);
    lv_obj_set_style_text_align(lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_pad_top(lbl, 13, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(lbl, 0, LV_PART_MAIN);
    return lbl;
}

void cmp_modbus_list_init(void) {
    modbus_config_init();
    s_list_container = NULL;
    s_row_count = 0;
    memset(s_rows, 0, sizeof(s_rows));
}

void cmp_modbus_list_render(void) {
    lv_ui *g = &guider_ui;

    /* Xác định Vùng cuộn (Scrollable container) của bảng */
    s_list_container = g->scr_base_cont_69;
    if (!s_list_container || !lv_obj_is_valid(s_list_container)) return;

    /* Bật tính năng cuộn dọc (Scroll) */
    lv_obj_set_scrollbar_mode(s_list_container, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_clear_flag(s_list_container, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);

    /* Dọn dẹp bảng cũ trước khi vẽ bảng mới */
    clear_rows();

    uint16_t count = 0;
    const MBS_Command_t *list = modbus_config_get_list(&count);
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

        /* Cột: STT (Số thứ tự) */
        snprintf(buf, sizeof(buf), "%d", i + 1);
        create_cell_label(row, 18, 36, buf);

        /* Cột: SLAVE ID */
        snprintf(buf, sizeof(buf), "%d", list[i].id);
        create_cell_label(row, 65, 80, buf);

        /* Cột: LOẠI THANH GHI (Dịch từ Function Code) */
        create_cell_label(row, 152, 120, modbus_config_func_name(list[i].func));

        /* Cột: THANH GHI MAP MỚI */
        snprintf(buf, sizeof(buf), "%d", list[i].reg_addr_remap);
        create_cell_label(row, 287, 130, buf);

        /* Cột: SỐ LƯỢNG */
        snprintf(buf, sizeof(buf), "%d", list[i].reg_quantity);
        create_cell_label(row, 434, 80, buf);

        /* Cột: THAO TÁC - Tạo nút bấm Sửa (Edit) và Xóa (Delete) */
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

}

void cmp_modbus_list_handle_apply(view_factory_t *ui) {
    if (!ui) return;

    lv_ui *g = &guider_ui;

    /* Trích xuất Slave ID từ Ô nhập liệu */
    const char *slave_str = lv_textarea_get_text(g->scr_base_ta_master_device_slaveid);
    uint8_t slave_id = (uint8_t)atoi(slave_str ? slave_str : "0");

    /* Trích xuất Địa chỉ thanh ghi (Address) */
    const char *addr_str = lv_textarea_get_text(g->scr_base_ta_master_device_address);
    uint16_t reg_addr = (uint16_t)atoi(addr_str ? addr_str : "0");

    /* Trích xuất Số lượng (Quantity) */
    const char *qty_str = lv_textarea_get_text(g->scr_base_ta_master_device_quantity);
    uint16_t reg_qty = (uint16_t)atoi(qty_str ? qty_str : "0");

    /* Trích xuất Function Code từ hộp Dropdown */
    uint16_t dd_sel = lv_dropdown_get_selected(g->scr_base_ddlist_master_device_registers);
    uint8_t func = modbus_config_dd_index_to_func(dd_sel);

    /* Trích xuất Địa chỉ Remap (Map lại sang thanh ghi khác nếu trùng) */
    const char *remap_str = lv_textarea_get_text(g->scr_base_ta_master_device_register_mapping);
    uint16_t remap_addr = (uint16_t)atoi(remap_str ? remap_str : "0");

    /* Kiểm tra tính hợp lệ: Báo đỏ nếu sai định dạng */
    if (slave_id < 1 || slave_id > 247) {
        lv_obj_set_style_border_color(g->scr_base_ta_master_device_slaveid, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);
        lv_obj_set_style_border_width(g->scr_base_ta_master_device_slaveid, 2, LV_PART_MAIN);
        return;
    } else {
        lv_obj_set_style_border_width(g->scr_base_ta_master_device_slaveid, 0, LV_PART_MAIN);
    }

    if (reg_qty < 1 || reg_qty > 125) {
        lv_obj_set_style_border_color(g->scr_base_ta_master_device_quantity, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);
        lv_obj_set_style_border_width(g->scr_base_ta_master_device_quantity, 2, LV_PART_MAIN);
        return;
    } else {
        lv_obj_set_style_border_width(g->scr_base_ta_master_device_quantity, 0, LV_PART_MAIN);
    }

    if (func > 0) {
        modbus_config_add_cmd(slave_id, func, reg_addr, reg_qty, remap_addr);
    }

    /* Xóa trắng nội dung cũ trong các ô nhập để chuẩn bị cho lần nhập tiếp theo */
    lv_textarea_set_text(g->scr_base_ta_master_device_slaveid, "");
    lv_textarea_set_text(g->scr_base_ta_master_device_address, "");
    lv_textarea_set_text(g->scr_base_ta_master_device_quantity, "");
    lv_textarea_set_text(g->scr_base_ta_master_device_register_mapping, "");
    lv_dropdown_set_selected(g->scr_base_ddlist_master_device_registers, 0);

}
