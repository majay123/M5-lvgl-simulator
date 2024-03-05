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
 * @LastEditTime : 2023-09-04 14:23:38
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

lv_font_t *my_font = NULL;


static void _all_homepage_drew_finished(lv_event_t *e)
{
    lv_obj_t *startup_img = (lv_obj_t *)lv_event_get_user_data(e);
    printf("drew finished\n");
    lv_obj_remove_event_cb(startup_img, _all_homepage_drew_finished);
}


void setup_scr_Startup_on(lv_ui *ui)
{
    lv_obj_t *startup_img = lv_img_create(lv_scr_act());
    printf("load starup img\n");
    lv_img_set_src(startup_img, &startup_pic);
    printf("load starup img\n");
    lv_obj_set_pos(startup_img, 0, 0);
    lv_obj_set_size(startup_img, 480, 480);

    lv_obj_add_event_cb(startup_img, _all_homepage_drew_finished, LV_EVENT_DRAW_MAIN_END, startup_img);

    lv_obj_t *act_scr = lv_scr_act();
    lv_disp_t *d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        setup_scr_Setting_new(ui);
        lv_scr_load_anim(ui->Setting, LV_SCR_LOAD_ANIM_NONE, 0, 1000 * 4, true);
    }
}

static void lv_load_my_font(const char *file_path)
{
    my_font = lv_font_load(file_path);
    if(my_font == NULL) {
        printf("Couldn't load font\n");
    }
    else {
        printf("Font loaded\n");
    }
    // fopen("/Users/mcd/Desktop/Hope_Work/output.font", "r");
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
    // lv_load_my_font("/Users/mcd/Desktop/Hope_Work/HanSansCN.font");
    // lv_load_my_font("/Users/mcd/Desktop/Hope_Work/font.bin");
    ui->oldmode_enable = true; 
    setup_scr_HomePage(ui);
    lv_scr_load(ui->HomePage);
    // setup_scr_Startup_on(ui);
}
