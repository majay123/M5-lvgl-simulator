//
// Created by txfly on 2022/3/16.
//

#include "network.h"

static void button_handler(lv_event_t *e);

static void toggle_handler(lv_event_t *e);

static void input_handler(lv_event_t *e);


static void handle_save();

lv_obj_t *label_ip;
lv_obj_t *label_gateway;
lv_obj_t *tb_ip;
lv_obj_t *tb_gateway;

void init_network(lv_obj_t *parent) {
    static lv_coord_t col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    /*Create a container with grid*/
    lv_obj_t *cont = lv_obj_create(parent);
    lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
    lv_obj_set_size(cont, lv_pct(100), lv_pct(100));
    lv_obj_center(cont);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);
    // mac
    lv_obj_t *label = lv_label_create(cont);
    lv_label_set_text(label, "MAC Address");

    /*Create the text area*/
    lv_obj_t *ta_mac = lv_textarea_create(cont);
    lv_obj_add_event_cb(ta_mac, input_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_textarea_set_accepted_chars(ta_mac, "0123456789:");
    lv_textarea_set_max_length(ta_mac, 32);
    lv_textarea_set_one_line(ta_mac, true);
    lv_textarea_set_text(ta_mac, "");

    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(ta_mac, LV_GRID_ALIGN_START, 1, 2,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
    // static ip
    label = lv_label_create(cont);
    lv_label_set_text(label, "Static ip");
    lv_obj_t *sw = lv_switch_create(cont);
    lv_obj_add_event_cb(sw, toggle_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(sw, LV_GRID_ALIGN_START, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 1);

    // ip address
    label_ip = lv_label_create(cont);
    lv_label_set_text(label_ip, "ip");

    /*Create the text area*/
    tb_ip = lv_textarea_create(cont);
    lv_obj_add_event_cb(tb_ip, input_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_textarea_set_accepted_chars(tb_ip, "0123456789.");
    lv_textarea_set_max_length(tb_ip, 15);
    lv_textarea_set_one_line(tb_ip, true);
    lv_textarea_set_text(tb_ip, "");

    lv_obj_set_grid_cell(label_ip, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(tb_ip, LV_GRID_ALIGN_START, 1, 2,
                         LV_GRID_ALIGN_STRETCH, 2, 1);

    // ip gateway
    label_gateway = lv_label_create(cont);
    lv_label_set_text(label_gateway, "Gateway");

    /*Create the text area*/
    tb_gateway = lv_textarea_create(cont);
    lv_obj_add_event_cb(tb_gateway, input_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_textarea_set_accepted_chars(tb_gateway, "0123456789.");
    lv_textarea_set_max_length(tb_gateway, 15);
    lv_textarea_set_one_line(tb_gateway, true);
    lv_textarea_set_text(tb_gateway, "");

    lv_obj_set_grid_cell(label_gateway, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 3, 1);
    lv_obj_set_grid_cell(tb_gateway, LV_GRID_ALIGN_START, 1, 2,
                         LV_GRID_ALIGN_STRETCH, 3, 1);
    lv_obj_t *btn_save = lv_btn_create(cont);
    lv_obj_add_event_cb(btn_save, button_handler, LV_EVENT_ALL, NULL);
    label = lv_label_create(btn_save);
    lv_label_set_text(label, "Save");
    lv_obj_center(label);
    lv_group_focus_obj(btn_save);
    lv_obj_set_grid_cell(btn_save, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_CENTER, 4, 1);
    lv_event_send(sw, LV_EVENT_VALUE_CHANGED, NULL);


//    /*Create a keyboard*/
//    kb = lv_keyboard_create(lv_scr_act());
//    lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
//    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);
//    lv_keyboard_set_textarea(kb, ta_mac);

}

static void msg_event_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_event_get_current_target(e);
    LV_LOG_USER("Button %s clicked, index %d", lv_msgbox_get_active_btn_text(obj), lv_msgbox_get_active_btn(obj));
    if (lv_msgbox_get_active_btn(obj) == 0) {
        handle_save();
    }
    lv_msgbox_close_async(obj);
}



void button_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_t *sender = lv_event_get_target(e);
        static const char *btns[] = {"OK", "CANCEL", NULL};
        lv_obj_t *msg = lv_msgbox_create(NULL, "Save", "Are you sure you want to save this configuration? It will take effect after restarting the system.", btns, true);
        lv_obj_add_event_cb(msg, msg_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
        lv_obj_center(msg);

    } else if (code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

static void toggle_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("State: %s\n", lv_obj_has_state(obj, LV_STATE_CHECKED) ? "On" : "Off");
        if (lv_obj_has_state(obj, LV_STATE_CHECKED)) {
            lv_obj_clear_flag(label_ip, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(label_gateway, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(tb_ip, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(tb_gateway, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(label_ip, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(label_gateway, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(tb_ip, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(tb_gateway, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

static void input_handler(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    const char *txt = lv_textarea_get_text(ta);
    if (txt[0] >= '0' && txt[0] <= '9' &&
        txt[1] >= '0' && txt[1] <= '9' &&
        txt[2] != ':') {
        lv_textarea_set_cursor_pos(ta, 2);
        lv_textarea_add_char(ta, ':');
    }
}

static void handle_save() {

}