//
// Created by txfly on 2022/3/16.
//

#include "number.h"

static void input_handler(lv_event_t *e);

static void button_handler(lv_event_t *e);

static void calendar_handler(lv_event_t *e);


lv_obj_t *ta_number;
lv_obj_t *ta_date;
lv_obj_t *ta_time;
lv_obj_t *calendar;

void init_number(lv_obj_t *parent) {
    static lv_coord_t col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    /*Create a container with grid*/
    lv_obj_t *cont = lv_obj_create(parent);
    lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
    lv_obj_set_size(cont, lv_pct(100), lv_pct(100));
    lv_obj_center(cont);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);
    // serial number
    lv_obj_t *label = lv_label_create(cont);
    lv_label_set_text(label, "Serial number");
    /*Create the text area*/
    ta_number = lv_textarea_create(cont);
    lv_obj_add_event_cb(ta_number, input_handler, LV_EVENT_ALL, NULL);
    lv_textarea_set_accepted_chars(ta_number, "0123456789:");
    lv_textarea_set_max_length(ta_number, 32);
    lv_textarea_set_one_line(ta_number, true);
    lv_textarea_set_text(ta_number, "");

    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(ta_number, LV_GRID_ALIGN_START, 1, 2,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
    // static ip
    label = lv_label_create(cont);
    lv_label_set_text(label, "Date");
    ta_date = lv_textarea_create(cont);
    lv_obj_add_event_cb(ta_date, input_handler, LV_EVENT_ALL, NULL);
    lv_textarea_set_accepted_chars(ta_date, "0123456789/");
    lv_textarea_set_max_length(ta_date, 10);
    lv_textarea_set_one_line(ta_date, true);
    lv_textarea_set_text(ta_date, "");
    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(ta_date, LV_GRID_ALIGN_START, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 1);

    label = lv_label_create(cont);
    lv_label_set_text(label, "Time");
    ta_time = lv_textarea_create(cont);
    lv_obj_add_event_cb(ta_time, input_handler, LV_EVENT_ALL, NULL);
    lv_textarea_set_accepted_chars(ta_time, "0123456789:");
    lv_textarea_set_max_length(ta_time, 10);
    lv_textarea_set_one_line(ta_time, true);
    lv_textarea_set_text(ta_time, "");
    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(ta_time, LV_GRID_ALIGN_START, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 2, 1);


    lv_obj_t *btn_save = lv_btn_create(cont);
    lv_obj_add_event_cb(btn_save, button_handler, LV_EVENT_ALL, NULL);
    label = lv_label_create(btn_save);
    lv_label_set_text(label, "Save");
    lv_obj_center(label);
    lv_group_focus_obj(btn_save);
    lv_obj_set_grid_cell(btn_save, LV_GRID_ALIGN_START, 1, 1,
                         LV_GRID_ALIGN_CENTER, 4, 1);

}

static void input_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *ta = lv_event_get_target(e);
    lv_indev_type_t type = lv_indev_get_type(lv_indev_get_act());

    if (code == LV_EVENT_FOCUSED && type == LV_INDEV_TYPE_POINTER) {

        if (ta == ta_date) {
            if (calendar == NULL) {
                lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                calendar = lv_calendar_create(lv_layer_top());
                lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_50, 0);
                lv_obj_set_style_bg_color(lv_layer_top(), lv_palette_main(LV_PALETTE_GREY), 0);
                lv_obj_set_size(calendar, 300, 330);
                lv_calendar_set_showed_date(calendar, 1990, 01);
                lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 30);
                lv_obj_add_event_cb(calendar, calendar_handler, LV_EVENT_ALL, ta);
                lv_calendar_header_dropdown_create(calendar);
            }
        } else if (ta == ta_time) {
            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_50, 0);
            lv_obj_set_style_bg_color(lv_layer_top(), lv_palette_main(LV_PALETTE_GREY), 0);
            static lv_coord_t col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
            static lv_coord_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
            /*Create a container with grid*/
            lv_obj_t *cont = lv_obj_create(lv_layer_top());
            lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
            lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
            lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_center(cont);
            lv_obj_set_layout(cont, LV_LAYOUT_GRID);
            lv_obj_set_style_pad_column(cont, 4,0);
            lv_obj_t *roller_h = lv_roller_create(cont);

            lv_roller_set_options(roller_h,
                                  "January\n"
                                  "February\n"
                                  "March\n"
                                  "April\n"
                                  "May\n"
                                  "June\n"
                                  "July\n"
                                  "August\n"
                                  "September\n"
                                  "October\n"
                                  "November\n"
                                  "December",
                                  LV_ROLLER_MODE_INFINITE);

            lv_roller_set_visible_row_count(roller_h, 4);
            lv_obj_t *roller_m = lv_roller_create(cont);
            lv_roller_set_options(roller_m,
                                  "January\n"
                                  "February\n"
                                  "March\n"
                                  "April\n"
                                  "May\n"
                                  "June\n"
                                  "July\n"
                                  "August\n"
                                  "September\n"
                                  "October\n"
                                  "November\n"
                                  "December",
                                  LV_ROLLER_MODE_INFINITE);

            lv_roller_set_visible_row_count(roller_m, 4);
            lv_obj_t *roller_s = lv_roller_create(cont);
            lv_roller_set_options(roller_s,
                                  "January\n"
                                  "February\n"
                                  "March\n"
                                  "April\n"
                                  "May\n"
                                  "June\n"
                                  "July\n"
                                  "August\n"
                                  "September\n"
                                  "October\n"
                                  "November\n"
                                  "December",
                                  LV_ROLLER_MODE_INFINITE);
            lv_roller_set_visible_row_count(roller_s, 4);

            static lv_coord_t col_dsc1[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
            static lv_coord_t row_dsc1[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
            /*Create a container with grid*/
            lv_obj_t *cont1 = lv_obj_create(cont);
            lv_obj_set_style_grid_column_dsc_array(cont1, col_dsc1, 0);
            lv_obj_set_style_grid_row_dsc_array(cont1, row_dsc1, 0);
            lv_obj_set_size(cont1, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_layout(cont1, LV_LAYOUT_GRID);
            lv_obj_set_style_pad_all(cont1, 4, 0);
            lv_obj_set_style_border_width(cont1, 0,0);

            lv_obj_t *btn_cancel = lv_btn_create(cont1);
            lv_obj_add_event_cb(btn_cancel, button_handler, LV_EVENT_ALL, NULL);
            lv_obj_t *label = lv_label_create(btn_cancel);
            lv_label_set_text(label, "CANCEL");
            lv_obj_center(label);

//            lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

            lv_obj_t *btn_ok = lv_btn_create(cont1);
            lv_obj_add_event_cb(btn_ok, button_handler, LV_EVENT_ALL, NULL);
            label = lv_label_create(btn_ok);
            lv_label_set_text(label, "OK");
            lv_obj_center(label);


            lv_obj_set_grid_cell(roller_h, LV_GRID_ALIGN_STRETCH, 0, 1,
                                 LV_GRID_ALIGN_CENTER, 0, 1);
            lv_obj_set_grid_cell(roller_m, LV_GRID_ALIGN_START, 1, 1,
                                 LV_GRID_ALIGN_STRETCH, 0, 1);
            lv_obj_set_grid_cell(roller_s, LV_GRID_ALIGN_START, 2, 1,
                                 LV_GRID_ALIGN_STRETCH, 0, 1);
//            lv_obj_set_grid_cell(btn_cancel, LV_GRID_ALIGN_START, 2, 1,
//                                 LV_GRID_ALIGN_STRETCH, 1, 1);
            lv_obj_set_grid_cell(cont1, LV_GRID_ALIGN_END, 0, 3,
                                 LV_GRID_ALIGN_CENTER, 1, 1);

            lv_obj_set_grid_cell(btn_cancel, LV_GRID_ALIGN_STRETCH, 0, 1,
                                 LV_GRID_ALIGN_CENTER, 0, 1);
            lv_obj_set_grid_cell(btn_ok, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);

        }
    }
}

static void button_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        lv_obj_t *sender = lv_event_get_target(e);

    } else if (code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

void calendar_handler(lv_event_t *e) {

}
