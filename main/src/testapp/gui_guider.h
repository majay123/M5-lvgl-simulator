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
 * @Date         : 2023-05-26 14:05:40
 * @LastEditors  : MCD
 * @LastEditTime : 2023-07-17 13:21:27
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/gui_guider.h
 * @Description  : 
 * 
 * ******************************************
 */

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

#define LCD_WIDTH  480
#define LCD_HEIGHT 480

#define HOPEPAGE_USE_PIC	(0)
#define COUNTDOWN_CNT_60S (60)    // s
#define WIFI_PASSWORD_MIN_LEN (8)    // s
#define GET_QRCODE_TIMEOUT       (1)
#define GET_QRCODE_MAX_COUNT     (5)
#define SETTING_UI_SHOW_BARCODE (1)
#define LV_USE_MY_FONT          (1)

typedef enum {
    ABOUT_INFO_PRODUCT_MODEL,
    ABOUT_INFO_SOFTWARE_VERSION,
    ABOUT_INFO_FIRMWARE_VERSION,
    ABOUT_INFO_SN_NUMBER,
    ABOUT_INFO_IP_ADDRESS,
    ABOUT_INFO_MAC_ADDRES,
} about_info_type_e;

typedef struct _sta_scan_res
{
	uint8_t bssid[6];    /**< The BSSID of AP */
	char ssid[32];     /**< The SSID of AP */
	char on_channel;   /**< Indicate whether the channel in DS IE is valid 2.4G channel */
	char channel;      /**< The channel of AP */
	uint16_t beacon_int; /**< Beacon interval of AP */
	uint16_t caps;       /**< Capability IE of AP */
	int level;         /**< RSSI of the received frame */
	int security;      /**< Encryption algorithm of AP */
	uint8_t tsf[8];      /**< TSF value in beacon or probe response */
	uint32_t ie_len;     /**< IE length of beacon or probe response */
	/* Followed by ie_len of IE data */
    uint8_t remember;
}sta_scan_res_t;

typedef struct
{
    lv_obj_t *HomePage;    //主界面和列表界面
    bool HomePage_del;
    lv_obj_t *tabview;     //表单
    lv_obj_t *MainPage;    //主页 显示天气等信息
    lv_obj_t *DevicePage;  //设备列表页面
    lv_obj_t *DeviceList;  //设备列表控件
    lv_obj_t *Apps_entry;  //APP入口

    lv_obj_t *Setting;
    lv_obj_t *wifi_list;
    lv_obj_t *devices_list;
    lv_obj_t *qr;
    lv_obj_t *menu;
    lv_obj_t *tip_lable;
    lv_obj_t *reset_btn;
    bool Setting_del;

    lv_obj_t *AddDevice;
    lv_obj_t *Countdown_lable;
    lv_obj_t *succeed_lable;
    lv_obj_t *add_cont;
    lv_obj_t *successed_cont;
    lv_obj_t *failed_cont;
    bool AddDevice_del;

    lv_obj_t *Wifi_Set;
    lv_obj_t *wifi_c_btn;
    lv_obj_t *wifi_ok_btn;
    lv_obj_t *wifi_keyboard;
    bool Wifi_Set_del;
    sta_scan_res_t wifi_select;
} lv_ui;

typedef enum {
    SETTING_MENU_WIFI_PAGE = 0,
    SETTING_MENU_BAND_PAGE,
    SETTING_MENU_MAIN_PAGE,
    SETTING_MENU_SYS_UPDATE_PAGE,
    SETTING_MENU_ABOUT_PAGE,
} setting_menu_page_e;

extern lv_font_t *my_font;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_HomePage(lv_ui *ui);
void setup_scr_Setting(lv_ui *ui);
void setup_scr_AddDevice(lv_ui *ui);
void ui_wifi_set(lv_ui *ui);
// void setup_scr_Startup_on(lv_ui *ui);

LV_IMG_DECLARE(bg);
LV_FONT_DECLARE(HanSansCN_20);
LV_IMG_DECLARE(light_knob);
LV_IMG_DECLARE(curtain_knob);
LV_IMG_DECLARE(curtain_slider);
LV_IMG_DECLARE(w_sunny);
LV_IMG_DECLARE(ic_wifi1);
LV_IMG_DECLARE(ic_wifi2);
LV_IMG_DECLARE(ic_wifi3);
LV_IMG_DECLARE(ic_lock);
LV_IMG_DECLARE(startup_pic);
LV_IMG_DECLARE(scene_off);
LV_IMG_DECLARE(scene_on);


#ifdef __cplusplus
}
#endif
#endif