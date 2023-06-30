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
 * @Date         : 2023-05-15 13:16:14
 * @LastEditors  : MCD
 * @LastEditTime : 2023-06-28 11:05:38
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/gui_guider.c
 * @Description  : 
 * 
 * ******************************************
 */

/*
 * @Author: lcr linchuran@nbhope.cn
 * @Date: 2023-04-20 10:59:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-15 13:16:02
 * @FilePath: \lvgl\main\src\testapp\gui_guider.c
 * @Description:
 */
/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "gui_guider.h"
#include "lvgl.h"
#include <stdio.h>


void setup_scr_Startup_on(lv_ui *ui)
{
    lv_obj_t * startup_img = lv_img_create(lv_scr_act());
    lv_img_set_src(startup_img, &bg);
    lv_obj_set_pos(startup_img, 0, 0);
    lv_obj_set_size(startup_img, 480, 480);

    lv_obj_t *act_scr = lv_scr_act();
	lv_disp_t *d = lv_obj_get_disp(act_scr);
	if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
	{
		setup_scr_HomePage(ui);
        lv_scr_load_anim(ui->HomePage, LV_SCR_LOAD_ANIM_NONE, 0, 1000 * 4, true);
	}
}

void init_scr_del_flag(lv_ui *ui)
{
    ui->HomePage_del = true;
    ui->Setting_del = true;
    ui->AddDevice_del = true;
    ui->Wifi_Set_del = true;
}

void setup_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);
    // setup_scr_HomePage(ui);
    // lv_scr_load(ui->HomePage);
    setup_scr_Startup_on(ui);
}
