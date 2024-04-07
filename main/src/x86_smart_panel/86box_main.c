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
 * ************Copyright 2024 MCD************
 * 
 * @version      : 
 * @Company      : HOPE
 * @Author       : MCD
 * @Date         : 2024-04-01 16:37:11
 * @LastEditors  : MCD
 * @LastEditTime : 2024-04-01 17:07:23
 * @FilePath     : /M5-lvgl-simulator/main/src/x86_smart_panel/86box_main.c
 * @Description  : 
 * 
 * ******************************************
 */

// #include "bk_private/legacy_init.h"
// #include <components/shell_task.h>
// #include <components/system.h>
// #include <os/os.h>

// #include "cli.h"
// #include "driver/drv_tp.h"
// #include "img_utility.h"
// #include "lcd_act.h"
// #include "lv_vendor.h"
#include "lvgl.h"
// #include "media_app.h"
#include "page_load_ctrol.h"
// #include "wanson_asr.h"


int x86_setup(void)
{
	hor_page_load_main();

    return 0;
}