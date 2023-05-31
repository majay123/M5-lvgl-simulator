/*
 * @Company: Hope
 * @Author: RunningCode
 * @Date: 2023-04-20 10:59:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-25 10:35:55
 * @Description: 
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\ui_common.c
 */

#include "ui_common.h"

void ui_init_cont(lv_obj_t *cont,lv_opa_t value)
{
    lv_obj_set_style_radius(cont, 0, 0);
    lv_obj_set_style_pad_all(cont, 0, 0);
    lv_obj_set_style_bg_opa(cont, value, 0);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
}

void ui_init_device(lv_obj_t *device)
{
    //LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(device, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_set_style_bg_opa(device, LV_OPA_TRANSP, 0);
	lv_obj_add_flag(device, LV_OBJ_FLAG_CHECKABLE);
	lv_obj_set_pos(device, 0, 0);
	lv_obj_set_style_pad_all(device, 0, 0);
	lv_obj_set_style_border_width(device, 0, 0);
}

void ui_init_menu_cont(lv_obj_t *cont,lv_opa_t value, lv_coord_t x, lv_coord_t y)
{
    ui_init_cont(cont, value);
    lv_obj_set_size(cont, 300, 480);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x000000), 0);
}




