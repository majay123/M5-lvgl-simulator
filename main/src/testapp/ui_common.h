/*
 * @Company: Hope
 * @Author: RunningCode
 * @Date: 2023-04-20 10:59:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-25 10:37:05
 * @Description: 
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\ui_common.h
 */

#include "gui_guider.h"

void ui_init_cont(lv_obj_t *parent, lv_opa_t value);
void ui_init_device(lv_obj_t *device);
void ui_init_menu_cont(lv_obj_t *cont,lv_opa_t value, lv_coord_t x, lv_coord_t y);
void set_common_btn_style(lv_obj_t *btn, int w, int h);
void ui_lv_msgbox_warning_create(const char *warning_tip, uint8_t timeout_s);
void ui_lv_msgbox_sure_create(const char *warning_tip, lv_event_cb_t event_cb, void *user_data);