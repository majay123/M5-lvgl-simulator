/*
 * @Company: Hope
 * @Author: RunningCode
 * @Date: 2023-04-20 10:59:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-26 14:05:40
 * @Description: 
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\gui_guider.h
 */
/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#define  LCD_WIDTH 480
#define  LCD_HEIGHT 480

typedef struct
{
	lv_obj_t *HomePage;     //主界面和列表界面
	bool HomePage_del;
	lv_obj_t *tabview;      //表单
	lv_obj_t *MainPage;     //主页 显示天气等信息
	lv_obj_t *DevicePage;   //设备列表页面
	lv_obj_t *DeviceList;   //设备列表控件
	lv_obj_t *Apps_entry;   //APP入口

	lv_obj_t *Setting;
	bool Setting_del;
	lv_obj_t *menu;

	lv_obj_t *AddDevice;
	lv_obj_t *add_cont;
	lv_obj_t *successed_cont;
	lv_obj_t *failed_cont;
	bool AddDevice_del;

}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_HomePage(lv_ui *ui);
void setup_scr_Setting(lv_ui *ui);
void setup_scr_AddDevice(lv_ui *ui);
LV_IMG_DECLARE(bg);
LV_FONT_DECLARE(HanSansCN_20);

#ifdef __cplusplus
}
#endif
#endif