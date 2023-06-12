/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 * 
 * 
 * ************Copyright 2023 MCD************
 * 
 * @version      : 
 * @Company      : HOPE
 * @Author       : MCD
 * @Date         : 2023-06-05 10:15:01
 * @LastEditors  : MCD
 * @LastEditTime : 2023-06-10 15:05:34
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/ui_wifi_set.c
 * @Description  : 
 * 
 * ******************************************
 */

#include "gui_guider.h"
#include "lvgl.h"
#include "ui_common.h"
#include <stdio.h>

#define LV_KEYBOARD_ENTER   (22)
#define LV_KEYBOARD_OK      (39)

static void _btn1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Button1");
    }
}

static void _btn2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_user_data(e);
    lv_obj_t *ta = lv_keyboard_get_textarea(kb);

    if (code == LV_EVENT_CLICKED) {
        const char *text = lv_textarea_get_text(ta);
        printf("get text: %s\n", text);
    }
}

static void back_SettingPage(lv_ui *ui)
{
    lv_obj_t *act_scr = lv_scr_act();
    lv_disp_t *d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        lv_obj_clean(act_scr);
        if (ui->Setting_del == true)
            setup_scr_Setting(ui);
        lv_scr_load_anim(ui->Setting, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
        ui->Wifi_Set_del = true;
    }
}

static void back_Setting_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    back_SettingPage(ui);
}

static void _lv_creat_back_Setting_btn(lv_ui *ui)
{
    // 手动绘制
    lv_obj_t *back_btn = lv_obj_create(ui->Wifi_Set);
    lv_obj_set_pos(back_btn, 0, 0);
    lv_obj_set_size(back_btn, 60, 60);
    ui_init_cont(back_btn, LV_OPA_TRANSP);
    lv_obj_add_flag(back_btn, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(back_btn, back_Setting_event_cb, LV_EVENT_CLICKED, ui);

    LV_IMG_DECLARE(ic_back);
    lv_obj_t *img_btn = lv_img_create(back_btn);
    lv_img_set_src(img_btn, &ic_back);
    lv_obj_set_pos(img_btn, 29, 16);
}

static void kb_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_user_data(e);
    lv_obj_t *ta = lv_keyboard_get_textarea(kb);


    if(code == LV_EVENT_CLICKED) {
        uint16_t btn = lv_keyboard_get_selected_btn(kb);
        if(btn == LV_KEYBOARD_ENTER || btn == LV_KEYBOARD_OK) {
            printf("selected btn: %d\n", btn);
            const char *text = lv_textarea_get_text(ta);
            printf("get text: %s\n", text);
        }
    }
}

void ui_wifi_set(lv_ui *ui)
{
    ui->Wifi_Set = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->Wifi_Set, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui->Wifi_Set, lv_color_hex(0x000000), 0);  // 设置背景颜色

    _lv_creat_back_Setting_btn(ui);

    lv_obj_t *label;

    lv_obj_t *kb = lv_keyboard_create(ui->Wifi_Set);
    lv_obj_set_size(kb, 480, 240);
    lv_obj_set_pos(kb, 0, 118);
    lv_obj_set_align(kb, LV_ALIGN_CENTER);
    lv_obj_clear_flag(kb, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
    lv_obj_set_style_bg_color(kb, lv_color_hex(0x201E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(kb, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(kb, lv_color_hex(0x423F3F), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(kb, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(kb, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(kb, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(kb, LV_TEXT_ALIGN_AUTO, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(kb, kb_event_cb, LV_EVENT_CLICKED, kb);

    /*Create a text area. The keyboard will write here*/
    lv_obj_t *ta;
    ta = lv_textarea_create(ui->Wifi_Set);
    lv_textarea_set_placeholder_text(ta, "PassWord");
    lv_obj_set_size(ta, 420, 43);
    lv_obj_set_pos(ta, 30, 78);

    lv_keyboard_set_textarea(kb, ta);
    

    lv_obj_t *btn1 = lv_btn_create(ui->Wifi_Set);
    lv_obj_set_pos(btn1, 107, 158);
    lv_obj_set_size(btn1, 100, 36);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    lv_obj_add_event_cb(btn1, _btn1_event_handler, LV_EVENT_CLICKED, NULL);

    // style set
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(btn1, lv_color_hex(0xB5AFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(btn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(btn1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Cancel");
    lv_obj_center(label);

    lv_obj_t *btn2 = lv_btn_create(ui->Wifi_Set);
    lv_obj_add_event_cb(btn2, _btn2_event_handler, LV_EVENT_CLICKED, kb);
    lv_obj_set_align(btn2, LV_ALIGN_CENTER);
    lv_obj_set_pos(btn2, 108, -61);
    lv_obj_set_size(btn2, 100, 36);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CLICKABLE);  /// Flags
    lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_bg_color(btn2, lv_color_hex(0xF68F3B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Sure");
    lv_obj_center(label);
}