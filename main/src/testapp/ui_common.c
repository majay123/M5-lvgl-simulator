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

/**
 * @brief Set the common obj style object, 方块按钮形状
 * 
 * @param btn 
 * @param w 
 * @param h 
 */
void set_common_btn_style(lv_obj_t *btn, int w, int h)
{
	if(btn == NULL) {
		printf("obj device is null!\r\n");
		return;
	}
	
	lv_obj_set_size(btn, w, h);
	lv_obj_set_style_radius(btn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(btn, lv_color_hex(0xB5AFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(btn, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_shadow_opa(btn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
}



