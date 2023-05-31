//
// Created by txfly on 2022/3/16.
//

#include "ui.h"
#include "lvgl.h"
#include "firmware.h"
#include "network.h"
#include "number.h"

lv_obj_t *tab_firmware;
lv_obj_t *tab_network;
lv_obj_t *tab_number;

void init_ui() {
    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 64);
    // lv_obj_set_size(tv, LV_SIZE_CONTENT ,LV_SIZE_CONTENT);
    tab_firmware = lv_tabview_add_tab(tv, "Firmware");
    tab_network = lv_tabview_add_tab(tv, "Network");
    tab_number = lv_tabview_add_tab(tv, "SerialNumber");

    lv_obj_t *tabs = lv_tabview_get_tab_btns(tv);
    lv_obj_set_style_pad_left(tabs, LV_HOR_RES / 2, 0);

    lv_obj_t *label_title = lv_label_create(tabs);
    //lv_obj_add_style(label_title, &style_title, 0);
    lv_label_set_text(label_title, "TMS Setting Panel");
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, -LV_HOR_RES / 2 + 25, 10);

    lv_obj_t *label_version = lv_label_create(tabs);
    lv_label_set_text(label_version, "V1.0.0-2022.03.15");
    lv_obj_set_style_text_opa(label_version, LV_OPA_50, 0);
    //lv_obj_add_style(label_title, &style_text_muted, 0);
    lv_obj_align_to(label_version, label_title, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    init_firmware(tab_firmware);
    init_network(tab_network);
    init_number(tab_number);


}


