//
// Created by txfly on 2022/3/16.
//

#include "firmware.h"

static void handle_update();

static void handle_fresh();

void init_update_ui();

lv_obj_t *parent;
lv_obj_t *btn_fresh;
lv_obj_t *btn_update;
lv_obj_t *btn_reboot;
lv_obj_t *main_layout;
lv_obj_t *update_layout;


static void msg_event_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_event_get_current_target(e);
    LV_LOG_USER("Button %s clicked, index %d", lv_msgbox_get_active_btn_text(obj), lv_msgbox_get_active_btn(obj));
    if (lv_msgbox_get_active_btn(obj) == 0) {
        handle_update();
    }
    lv_msgbox_close_async(obj);
}

static void button_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_t *sender = lv_event_get_target(e);
        if (sender == btn_fresh) {
            LV_LOG_USER("Clicked, fresh");
            handle_fresh();
        } else if (sender == btn_update) {
            LV_LOG_USER("Clicked, update");
            static const char *btns[] = {"OK", "CANCEL", NULL};
            lv_obj_t *msg = lv_msgbox_create(NULL, "Update", "Are you sure you want to update firmware 222.x?", btns, true);
            lv_obj_add_event_cb(msg, msg_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
            lv_obj_center(msg);
        }if (sender == btn_reboot) {
            LV_LOG_USER("Clicked, reboot");
            lv_obj_add_flag(update_layout, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_layout, LV_OBJ_FLAG_HIDDEN);

        }
    } else if (code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

static void handle_fresh() {

}


static void handle_update() {
    lv_obj_add_flag(main_layout, LV_OBJ_FLAG_HIDDEN);
    if(update_layout== NULL){
        init_update_ui();
    }
    lv_obj_clear_flag(update_layout, LV_OBJ_FLAG_HIDDEN);
}



static void lw_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
//        if(currentButton == NULL) return;
//        lv_obj_move_background(currentButton);
//        lv_obj_scroll_to_view(currentButton, LV_ANIM_ON);
    }
}


void init_firmware(lv_obj_t *parent_) {
    parent = parent_;
    main_layout = lv_obj_create(parent);
    lv_obj_set_size(main_layout, lv_pct(100), lv_pct(100));
    lv_obj_center(main_layout);
    lv_obj_set_flex_flow(main_layout, LV_FLEX_FLOW_COLUMN);

    lv_obj_t *lw = lv_list_create(main_layout);
    lv_obj_set_size(lw, lv_pct(100), lv_pct(60));

    lv_obj_align(lw, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_flex_flow(lw, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_grow(lw, 1);
    for (int i = 0; i < 20; ++i) {
        lv_obj_t *btn = lv_list_add_btn(lw, NULL, "TMS-DCS-1.0.0-2.22.03.16.x");
        lv_obj_add_event_cb(btn, lw_handler, LV_EVENT_ALL, NULL);
        lv_group_remove_obj(btn);
    }

    lv_obj_t *row = lv_obj_create(main_layout);
    lv_obj_set_flex_align(row, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_size(row, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_center(row);
    lv_obj_set_flex_flow(row, LV_FLEX_FLOW_ROW);

    btn_fresh = lv_btn_create(row);
    lv_obj_add_event_cb(btn_fresh, button_handler, LV_EVENT_ALL, NULL);
    lv_obj_t *label = lv_label_create(btn_fresh);
    lv_label_set_text(label, "Fresh");
    lv_obj_center(label);

    btn_update = lv_btn_create(row);
    lv_obj_add_event_cb(btn_update, button_handler, LV_EVENT_ALL, NULL);
    label = lv_label_create(btn_update);
    lv_label_set_text(label, "Update");
    lv_obj_center(label);
    lv_group_focus_obj(btn_fresh);
}

void init_update_ui() {
    update_layout = lv_obj_create(parent);
    lv_obj_set_size(update_layout, lv_pct(100), lv_pct(100));
    lv_obj_center(update_layout);
    lv_obj_set_flex_flow(update_layout, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(update_layout, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * slider = lv_slider_create(update_layout);
    lv_obj_set_width(slider, lv_pct(80));
    lv_obj_center(slider);
    lv_slider_set_mode(slider, LV_SLIDER_MODE_SYMMETRICAL);
     lv_obj_clear_flag(slider, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /*Create a label below the slider*/
    lv_obj_t * slider_label = lv_label_create(update_layout);
    lv_obj_set_style_pad_top(slider_label, 16, 0);
    lv_obj_set_style_pad_bottom(slider_label, 32, 0);
    lv_label_set_text(slider_label, "0%");
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    btn_reboot = lv_btn_create(update_layout);

    lv_obj_add_event_cb(btn_reboot, button_handler, LV_EVENT_ALL, NULL);
    lv_obj_t * label = lv_label_create(btn_reboot);
    lv_label_set_text(label, "Reboot");
    lv_obj_center(label);
    lv_obj_add_state(btn_reboot, LV_STATE_DISABLED);

    lv_group_focus_obj(btn_reboot);

//    static lv_style_t style ;
//    lv_style_init(&style);
//    lv_style_set_pad_column(&style, 10);
//    lv_obj_add_style(update_layout, &style, 0);




}

static void slider_event_cb(lv_event_t * e)
{
//    lv_obj_t * slider = lv_event_get_target(e);
//    char buf[8];
//    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
//    lv_label_set_text(slider_label, buf);
//    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

}