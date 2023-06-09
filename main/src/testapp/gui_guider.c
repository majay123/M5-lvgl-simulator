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
 * @LastEditTime : 2023-06-05 10:20:05
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
    setup_scr_HomePage(ui);
    lv_scr_load(ui->HomePage);
}
