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
 * @LastEditTime : 2023-06-20 09:28:43
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/ui_wifi_set.c
 * @Description  : 
 * 
 * ******************************************
 */

#include "gui_guider.h"
#include "lvgl.h"
#include "ui_common.h"
#include <stdio.h>

#define LV_KEYBOARD_ENTER (22)
#define LV_KEYBOARD_OK    (39)

static void back_SettingPage(lv_ui *ui);

static void _cancel_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Button1");
        lv_ui *ui = lv_event_get_user_data(e);
        back_SettingPage(ui);
    }
}

static void _connect_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *ta = lv_keyboard_get_textarea(ui->wifi_keyboard);

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

static void kb_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *ta = lv_keyboard_get_textarea(ui->wifi_keyboard);

    printf("code = %d\n", code);
    if (code == LV_EVENT_CLICKED) {
        uint16_t btn = lv_keyboard_get_selected_btn(ui->wifi_keyboard);
        if (btn == LV_KEYBOARD_ENTER || btn == LV_KEYBOARD_OK) {
            printf("selected btn: %d\n", btn);
            const char *text = lv_textarea_get_text(ta);
            printf("get text: %s\n", text);
            // todo 连接wifi
        }
        else {
            const char *text = lv_textarea_get_text(ta);
            if (strlen(text) >= WIFI_PASSWORD_MIN_LEN) {
                lv_obj_set_style_bg_color(ui->wifi_ok_btn, lv_color_hex(0xF68F3B), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            else {
                lv_obj_set_style_bg_color(ui->wifi_ok_btn, lv_color_hex(0x654021), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
        }
    }
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

void ui_wifi_set(lv_ui *ui)
{
    ui->Wifi_Set = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->Wifi_Set, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui->Wifi_Set, lv_color_hex(0x000000), 0);  // 设置背景颜色

    _lv_creat_back_Setting_btn(ui);

    lv_obj_t *label;

    ui->wifi_keyboard = lv_keyboard_create(ui->Wifi_Set);
    lv_obj_set_size(ui->wifi_keyboard, 480, 240);
    lv_obj_set_pos(ui->wifi_keyboard, 0, 118);
    lv_obj_set_align(ui->wifi_keyboard, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui->wifi_keyboard, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);  /// Flags
    lv_obj_set_style_bg_color(ui->wifi_keyboard, lv_color_hex(0x201E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->wifi_keyboard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui->wifi_keyboard, lv_color_hex(0x423F3F), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->wifi_keyboard, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->wifi_keyboard, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->wifi_keyboard, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->wifi_keyboard, LV_TEXT_ALIGN_AUTO, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui->wifi_keyboard, kb_event_cb, LV_EVENT_CLICKED, ui);

    /*Create a text area. The keyboard will write here*/
    lv_obj_t *ta;
    ta = lv_textarea_create(ui->Wifi_Set);
    lv_textarea_set_placeholder_text(ta, "PassWord");
    lv_obj_set_size(ta, 420, 43);
    lv_obj_set_pos(ta, 30, 78);

    lv_keyboard_set_textarea(ui->wifi_keyboard, ta);

    ui->wifi_c_btn = lv_btn_create(ui->Wifi_Set);
    lv_obj_set_pos(ui->wifi_c_btn, 100, 158);
    lv_obj_set_size(ui->wifi_c_btn, 100, 36);
    lv_obj_add_flag(ui->wifi_c_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui->wifi_c_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    lv_obj_add_event_cb(ui->wifi_c_btn, _cancel_btn_event_cb, LV_EVENT_CLICKED, NULL);

    // style set
    lv_obj_set_style_bg_color(ui->wifi_c_btn, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->wifi_c_btn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui->wifi_c_btn, lv_color_hex(0xB5AFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui->wifi_c_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->wifi_c_btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui->wifi_c_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->wifi_c_btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->wifi_c_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(ui->wifi_c_btn);
    lv_obj_set_style_text_font(label, &HanSansCN_20, 0);
    if (ui->wifi_select.remember == 0)
        lv_label_set_text(label, "取消");
    else
        lv_label_set_text(label, "忘记");
    lv_obj_center(label);

    ui->wifi_ok_btn = lv_btn_create(ui->Wifi_Set);
    lv_obj_add_event_cb(ui->wifi_ok_btn, _connect_btn_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_set_align(ui->wifi_ok_btn, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui->wifi_ok_btn, 108, -61);
    lv_obj_set_size(ui->wifi_ok_btn, 100, 36);
    lv_obj_add_flag(ui->wifi_ok_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui->wifi_ok_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

    lv_obj_add_flag(ui->wifi_ok_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui->wifi_ok_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    //lv_color_hex(0x654021) 无法连接的颜色，只有输入密码大于8位，则使用lv_color_hex(0xF68F3B)
    lv_obj_set_style_bg_color(ui->wifi_ok_btn, lv_color_hex(0x654021), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->wifi_ok_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->wifi_ok_btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->wifi_ok_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(ui->wifi_ok_btn);
    lv_obj_set_style_text_font(label, &HanSansCN_20, 0);
    lv_label_set_text(label, "连接");
    lv_obj_center(label);

    lv_obj_t *wifi_name = lv_label_create(ui->Wifi_Set);
    lv_obj_set_pos(wifi_name, 0, -213);
    lv_obj_set_size(wifi_name, 200, 24);
    lv_obj_set_align(wifi_name, LV_ALIGN_CENTER);
    lv_label_set_text(wifi_name, ui->wifi_select.ssid);
    lv_obj_set_style_text_color(wifi_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(wifi_name, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(wifi_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(wifi_name, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
}