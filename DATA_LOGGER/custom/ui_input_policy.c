#include "ui_input_policy.h"

static lv_style_t s_field_disabled;
static lv_style_t s_label_disabled;
static lv_style_t s_overlay_style;
static bool s_style_init = false;

static lv_obj_t *s_wifi_overlay = NULL;
static lv_obj_t *s_eth_overlay = NULL;

static void init_styles(void)
{
    if (s_style_init) return;

    lv_style_init(&s_field_disabled);
    lv_style_set_bg_opa(&s_field_disabled, LV_OPA_50);
    lv_style_set_bg_color(&s_field_disabled, lv_color_hex(0x5b6573));
    lv_style_set_text_opa(&s_field_disabled, LV_OPA_60);
    lv_style_set_border_opa(&s_field_disabled, LV_OPA_50);

    lv_style_init(&s_label_disabled);
    lv_style_set_text_opa(&s_label_disabled, LV_OPA_40);

    lv_style_init(&s_overlay_style);
    /* Overlay chỉ dùng để chặn input, không được tự tạo thêm một mảng màu riêng. */
    lv_style_set_bg_opa(&s_overlay_style, LV_OPA_TRANSP);
    lv_style_set_border_width(&s_overlay_style, 0);
    lv_style_set_radius(&s_overlay_style, 0);
    lv_style_set_shadow_width(&s_overlay_style, 0);
    lv_style_set_outline_width(&s_overlay_style, 0);
    lv_style_set_pad_all(&s_overlay_style, 0);

    s_style_init = true;
}

static void set_disabled_visual(lv_obj_t *obj, bool disabled, bool is_label)
{
    if (!obj) return;
    init_styles();

    if (disabled) {
        lv_obj_add_state(obj, LV_STATE_DISABLED);
        lv_obj_add_style(obj, is_label ? &s_label_disabled : &s_field_disabled, LV_PART_MAIN | LV_STATE_DISABLED);
        if (!is_label) {
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
        }
    } else {
        lv_obj_clear_state(obj, LV_STATE_DISABLED);
        lv_obj_remove_style(obj, is_label ? &s_label_disabled : &s_field_disabled, LV_PART_MAIN | LV_STATE_DISABLED);
        if (!is_label) {
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE);
        }
    }
}

static lv_obj_t *create_overlay(lv_obj_t *parent)
{
    lv_obj_t *overlay;

    if (!parent) return NULL;
    init_styles();

    overlay = lv_obj_create(parent);
    lv_obj_remove_style_all(overlay);
    lv_obj_add_style(overlay, &s_overlay_style, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(overlay, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(overlay, LV_OBJ_FLAG_HIDDEN);
    return overlay;
}

static void ensure_overlays(lv_ui *ui)
{
    if (!ui) return;
    if (!s_wifi_overlay || !lv_obj_is_valid(s_wifi_overlay)) s_wifi_overlay = create_overlay(ui->scr_base_cont_wifi);
    if (!s_eth_overlay || !lv_obj_is_valid(s_eth_overlay)) s_eth_overlay = create_overlay(ui->scr_base_cont_ethernet);
}

static void place_overlay(lv_obj_t *overlay, lv_obj_t *parent, lv_obj_t *first, lv_obj_t *last)
{
    lv_area_t p;
    lv_area_t a1;
    lv_area_t a2;
    lv_coord_t x1;
    lv_coord_t y1;
    lv_coord_t x2;
    lv_coord_t y2;

    if (!overlay || !parent || !first || !last) return;
    if (!lv_obj_is_valid(overlay) || !lv_obj_is_valid(parent)) return;
    if (!lv_obj_is_valid(first) || !lv_obj_is_valid(last)) return;

    lv_obj_update_layout(parent);
    lv_obj_get_coords(parent, &p);
    lv_obj_get_coords(first, &a1);
    lv_obj_get_coords(last, &a2);

    x1 = LV_MIN(a1.x1, a2.x1) - p.x1 - 8;
    y1 = LV_MIN(a1.y1, a2.y1) - p.y1 - 6;
    x2 = LV_MAX(a1.x2, a2.x2) - p.x1 + 8;
    y2 = LV_MAX(a1.y2, a2.y2) - p.y1 + 6;

    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;

    lv_obj_set_pos(overlay, x1, y1);
    lv_obj_set_size(overlay, x2 - x1, y2 - y1);
    lv_obj_move_foreground(overlay);
}

void ui_input_policy_bind(lv_ui *ui)
{
    ensure_overlays(ui);
}

void ui_input_policy_unbind(void)
{
    s_wifi_overlay = NULL;
    s_eth_overlay = NULL;
}

bool ui_input_policy_is_enabled(lv_ui *ui, lv_obj_t *input_obj)
{
    if (!ui || !input_obj || !lv_obj_is_valid(input_obj)) return false;

    if (input_obj == ui->scr_base_ta_wifi_ip) {
        return !ui->scr_base_ddlist_wifi_mode || lv_dropdown_get_selected(ui->scr_base_ddlist_wifi_mode) != 0U;
    }

    if (input_obj == ui->scr_base_ta_ethernet_ip ||
        input_obj == ui->scr_base_ta_ethernet_subnet ||
        input_obj == ui->scr_base_ta_ethernet_gateway) {
        return !ui->scr_base_ddlist_ethernet_mode || lv_dropdown_get_selected(ui->scr_base_ddlist_ethernet_mode) != 0U;
    }

    return !lv_obj_has_state(input_obj, LV_STATE_DISABLED);
}

void ui_input_policy_apply(lv_ui *ui, const ui_runtime_state_t *state)
{
    bool wifi_disabled;
    bool eth_disabled;

    if (!ui || !state) return;

    ensure_overlays(ui);
    wifi_disabled = state->wifi_mode == UI_IP_MODE_DHCP;
    eth_disabled = state->ethernet_mode == UI_IP_MODE_DHCP;

    set_disabled_visual(ui->scr_base_ta_wifi_ip, wifi_disabled, false);
    set_disabled_visual(ui->scr_base_label_112, wifi_disabled, true);

    set_disabled_visual(ui->scr_base_ta_ethernet_ip, eth_disabled, false);
    set_disabled_visual(ui->scr_base_ta_ethernet_subnet, eth_disabled, false);
    set_disabled_visual(ui->scr_base_ta_ethernet_gateway, eth_disabled, false);
    set_disabled_visual(ui->scr_base_label_114, eth_disabled, true);
    set_disabled_visual(ui->scr_base_label_115, eth_disabled, true);
    set_disabled_visual(ui->scr_base_label_116, eth_disabled, true);

    if (s_wifi_overlay && lv_obj_is_valid(s_wifi_overlay)) {
        place_overlay(s_wifi_overlay, ui->scr_base_cont_wifi, ui->scr_base_label_112, ui->scr_base_ta_wifi_ip);
        if (wifi_disabled) lv_obj_clear_flag(s_wifi_overlay, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(s_wifi_overlay, LV_OBJ_FLAG_HIDDEN);
    }

    if (s_eth_overlay && lv_obj_is_valid(s_eth_overlay)) {
        place_overlay(s_eth_overlay, ui->scr_base_cont_ethernet, ui->scr_base_label_114, ui->scr_base_ta_ethernet_gateway);
        if (eth_disabled) lv_obj_clear_flag(s_eth_overlay, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(s_eth_overlay, LV_OBJ_FLAG_HIDDEN);
    }
}
