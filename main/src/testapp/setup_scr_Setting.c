/*
 * @Company: HOPE
 * @Author: RunningCode
 * @Date: 2023-04-21 17:27:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-26 14:15:14
 * @Description:
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\setup_scr_Setting.c
 */

#include "gui_guider.h"
#include "lvgl.h"
#include "ui_common.h"
#include <stdio.h>

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

typedef struct
{
    bool lock_st;         // 是否加密
    char wifi_name[32];   // wifi名称
    char connect_st[18];  // 连接状态
    int16_t wifi_dbm;     // wifi 信号强度
} st_wifi;

st_wifi st_wifi_item[] = {
    {.lock_st = true, .wifi_name = "vsdfgvdfg", .connect_st = "connect", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "tesdfgdfgst2", .connect_st = "error", .wifi_dbm = 2},
    {.lock_st = false, .wifi_name = "rqwerweq", .connect_st = "error", .wifi_dbm = 3},
    {.lock_st = true, .wifi_name = "tesfsdft4", .connect_st = "error", .wifi_dbm = 3},
    {.lock_st = false, .wifi_name = "dasdasdas", .connect_st = "error", .wifi_dbm = 2},
    {.lock_st = true, .wifi_name = "dasdasdas", .connect_st = "error", .wifi_dbm = 2},
    {.lock_st = true, .wifi_name = "wifiname", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "gsdfgsfd", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = false, .wifi_name = "fsdggssrf", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "huonfgdnfg", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "rqwerweq", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = false, .wifi_name = "tesfsdft4", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "dasdasdas", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = false, .wifi_name = "dasdasdas", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = false, .wifi_name = "wifiname", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = false, .wifi_name = "gsdfgsfd", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "fsdggssrf", .connect_st = "error", .wifi_dbm = 1},
    {.lock_st = true, .wifi_name = "huonfgdnfg", .connect_st = "connecting", .wifi_dbm = 1},
};

char about_info[][32] = {
    "产品型号：",
    "软件版本：",
    "固件版本：",
    "SN    号：",
    "IP  地址：",
    "MAC 地址：",
};

static lv_timer_t *qr_timer = NULL;
static int get_qr_count = 0;


static void _lv_wifi_click_event_cb(lv_event_t *e);
static lv_obj_t *_wifi_list_add_item(lv_ui *ui, lv_obj_t *wifi_list, st_wifi *scan_ap, const char *link_ssid);

static void back_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);         // 获取产生事件的对象
    lv_ui *ui = lv_event_get_user_data(e);          // 获取用户数据
    if (lv_menu_back_btn_is_root(ui->menu, obj)) {  // 根菜单的返回键

        lv_obj_t *act_scr = lv_scr_act();
        lv_disp_t *d = lv_obj_get_disp(act_scr);
        if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
            lv_obj_clean(act_scr);
            printf("exit settings\n");
            if (ui->HomePage_del == true)
                setup_scr_HomePage(ui);
            lv_scr_load_anim(ui->HomePage, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
            ui->Setting_del = true;
        }
    }
}

static void _menu_event_cb(lv_event_t *e)
{
    lv_obj_t *menu = lv_event_get_target(e);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    uint32_t index = lv_obj_get_index(menu);
    printf("_menu_event_cb: %d\n", index);
}

static void _setting_clicked_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    uint32_t index = lv_obj_get_index(obj);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    printf("menu clicked: %d\n", index);
    if (index == 1) {
        lv_timer_reset(qr_timer);
        lv_timer_resume(qr_timer);
    }

    switch (index) {
        case SETTING_MENU_WIFI_PAGE: {
#if WEATHER_OPEN_WIFI_SCAN_TIMER
            if (wifi_scan_timer != NULL) {
                lv_timer_resume(wifi_scan_timer);
            }
#endif
            // os_printf("wifi scan start\n");
            // bk_wifi_scan_start(NULL);
            break;
        }
        case SETTING_MENU_BAND_PAGE: {
            // send_event_simple_msg(messageType_MSGCODE_GET_QRCODE_REQ);
            printf("SETTING_MENU_BAND_PAGE\n");
            if (qr_timer) {
                lv_timer_resume(qr_timer);  //启动定时器定时器
                lv_timer_reset(qr_timer);   //复位回调周期的时间
            }
            break;
        }
        case SETTING_MENU_MAIN_PAGE: {
            printf("SETTING_MENU_MAIN_PAGE\n");
            // send_event_simple_msg(messageType_MSGCODE_POP_TOTAL_DEVICE_ACTION_REQ);
            break;
        }
        default:
            break;
    }
}

static lv_obj_t *create_text(lv_obj_t *parent, const char *txt)
{
    lv_obj_t *obj = lv_menu_cont_create(parent);  // 创建菜单cont容器对象
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_size(obj, LV_PCT(100), 70);
    lv_obj_t *label = NULL;

    if (txt) {
        label = lv_label_create(obj);                                  // 创建label
        lv_obj_set_style_text_font(label, &HanSansCN_20, 0);
        lv_label_set_text(label, txt);                                 // 设置label显示内容
        lv_obj_set_style_text_color(label, lv_color_hex(0xffffff), 0);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);  // 循环滚动模式
        lv_obj_set_flex_grow(label, 1);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_set_style_pad_left(label, 24, 0);
    }
    return obj;
}

static void switch_handler(lv_event_t *e)
{
    // todo wifi enable or disable
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        if (lv_obj_has_state(obj, LV_STATE_CHECKED)) {
            printf("enable wifi\n");
            for (size_t i = 0; i < ARRAY_SIZE(st_wifi_item); i++) {
                lv_obj_t *wifi_item = lv_obj_create(ui->wifi_list);
                lv_obj_set_pos(wifi_item, 0, 0);
                lv_obj_set_style_pad_all(wifi_item, 0, 0);
                lv_obj_set_style_border_width(wifi_item, 0, 0);
                // LV_STATE_CHECKED
                lv_obj_add_flag(wifi_item, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_FOCUSED);
                lv_obj_set_size(wifi_item, 300, 40);
                lv_obj_set_style_bg_opa(wifi_item, LV_OPA_COVER, 0);

                // wifi name
                lv_obj_t *wifi_name = lv_label_create(wifi_item);
                lv_label_set_text(wifi_name, st_wifi_item[i].wifi_name);
                lv_obj_set_pos(wifi_name, 10, 0);
                lv_obj_set_size(wifi_name, 100, 20);
                lv_obj_set_style_opa(wifi_name, LV_OPA_COVER, 0);
                lv_obj_set_style_text_color(wifi_name, lv_color_hex(0xffffff), 0);

                // wifi st
                lv_obj_t *wifi_st = lv_label_create(wifi_item);
                lv_label_set_text(wifi_st, st_wifi_item[i].connect_st);
                lv_obj_set_pos(wifi_st, 10, 20);
                lv_obj_set_size(wifi_st, 100, 20);
                lv_obj_set_style_opa(wifi_st, LV_OPA_COVER, 0);
                lv_obj_set_style_text_color(wifi_st, lv_color_hex(0xffffff), 0);

                // wifi dbm
                lv_obj_t *wifi_dbm = lv_img_create(wifi_item);
                if (st_wifi_item[i].wifi_dbm == 1) {
                    LV_IMG_DECLARE(ic_wifi1);
                    lv_img_set_src(wifi_dbm, &ic_wifi1);
                }
                else if (st_wifi_item[i].wifi_dbm == 2) {
                    LV_IMG_DECLARE(ic_wifi2);
                    lv_img_set_src(wifi_dbm, &ic_wifi2);
                }
                else if (st_wifi_item[i].wifi_dbm == 3) {
                    LV_IMG_DECLARE(ic_wifi3);
                    lv_img_set_src(wifi_dbm, &ic_wifi3);
                }
                lv_obj_set_pos(wifi_dbm, 250, 5);

                // wifi password
                if (st_wifi_item[i].lock_st) {
                    lv_obj_t *wifi_lock = lv_img_create(wifi_item);
                    LV_IMG_DECLARE(ic_lock);
                    lv_img_set_src(wifi_lock, &ic_lock);
                    lv_obj_set_pos(wifi_lock, 275, 9);
                }
                lv_obj_add_event_cb(wifi_item, _lv_wifi_click_event_cb, LV_EVENT_CLICKED, ui);
            }
        }
        else {
            lv_obj_clean(ui->wifi_list);
            printf("disable wifi\n");
        }
    }
}

static void _lv_qr_click_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    static int click_i = 0;
    char buf[128] = {0};

    // printf("qr click event: %d\n", lv_event_get_code(e));
    // snprintf(buf, sizeof(buf), "qr click event: %d", click_i++);
    // lv_qrcode_update(ui->qr, buf, strlen(buf));
    lv_obj_clear_flag(ui->tip_lable, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->qr, LV_OBJ_FLAG_HIDDEN);
}

static void _lv_tip_click_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    static int click_i = 0;
    char buf[128] = {0};

    printf("qr click event: %d\n", lv_event_get_code(e));
    snprintf(buf, sizeof(buf), "qr click event: %d", click_i++);
    lv_qrcode_update(ui->qr, buf, strlen(buf));
    lv_obj_add_flag(ui->tip_lable, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui->qr, LV_OBJ_FLAG_HIDDEN);
}

static void event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_current_target(e);
    LV_UNUSED(obj);
    LV_LOG_USER("Button %s clicked", lv_msgbox_get_active_btn_text(obj));
    if (lv_msgbox_get_active_btn_text(obj) == "确认") {
        printf("delete select devices\n");
    }
    else if (lv_msgbox_get_active_btn_text(obj) == "取消") {
        lv_obj_t *btn = lv_event_get_target(e);
        lv_obj_t *mbox = lv_obj_get_parent(btn);
        lv_msgbox_close(mbox);
    }
}

static void _delete_devices_event_cb(lv_event_t *e)
{
    static const char *btns[] = {"取消", "确认", ""};
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    // lv_obj_t * obj = lv_event_get_target(e);
    printf("delete devices event: %d\n", lv_event_get_code(e));

    lv_obj_t *mbox1 = lv_msgbox_create(NULL, "提示", "确认是否要删除设备？", btns, false);
    lv_obj_set_style_text_font(mbox1, &HanSansCN_20, 0);
    lv_obj_add_event_cb(mbox1, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox1);
}

static void _device_item_event_cb(lv_event_t *e)
{
    // printf("this device is checked\n");
    lv_obj_t *obj = lv_event_get_target(e);
    printf("devices list index: %d\n", lv_obj_get_index(obj));
    lv_obj_t *checkbox = lv_obj_get_child(obj, 1);
    if (lv_obj_has_state(checkbox, LV_STATE_CHECKED)) {
        printf("this device is not checked\n");
        lv_obj_clear_state(checkbox, LV_STATE_CHECKED);
    }
    else {
        printf("this device is checked\n");
        lv_obj_add_state(checkbox, LV_STATE_CHECKED);
    }
}

static void _devices_checkbox_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *dev_item = lv_obj_get_parent(obj);
    // lv_obj_t * dev_item =lv_event_get_user_data(e);
    printf("checkbox sta: %d\n", lv_obj_get_index(dev_item));
    if (lv_obj_has_state(obj, LV_STATE_CHECKED)) {
        printf("this device is checked\n");
    }
    else {
        printf("this device is not checked\n");
    }
}


static void _update_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_current_target(e);
    // os_printf("Button %s clicked", lv_msgbox_get_active_btn_text(obj));
    if (lv_msgbox_get_active_btn_text(obj) == "确认") {
        // todo update
        printf("========== update now\n");
        lv_obj_t *btn = lv_event_get_target(e);
        lv_obj_t *mbox = lv_obj_get_parent(btn);
        lv_msgbox_close(mbox);
        ui_lv_msgbox_warning_create("设备正在升级，请勿断电，升级过程中设备将会黑屏。", 5);
    }
    else if (lv_msgbox_get_active_btn_text(obj) == "取消") {
        lv_obj_t *btn = lv_event_get_target(e);
        lv_obj_t *mbox = lv_obj_get_parent(btn);
        lv_msgbox_close(mbox);
    }
}

static void _ota_btn_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_ui *ui = lv_event_get_user_data(e);

    printf("ota button event: %d\n", lv_event_get_code(e));
    ui_lv_msgbox_sure_create("发现新版本，是否确认升级？", _update_event_cb, ui);
}

static void _qrcode_timer_callback(lv_timer_t *t)
{
    printf("qrcode get\n");
    get_qr_count++;
    if (get_qr_count > GET_QRCODE_MAX_COUNT) {
        printf("qrcode get failed, out of count\n");
        lv_timer_pause(qr_timer);
        get_qr_count = 0;
        lv_ui *ui = t->user_data;
        lv_obj_clear_flag(ui->tip_lable, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui->tip_lable, "网络超时，请检查网络。");
        lv_obj_add_flag(ui->qr, LV_OBJ_FLAG_HIDDEN);
    }
    // else
    // send_event_simple_msg(messageType_MSGCODE_GET_QRCODE_REQ);
}


static lv_obj_t *_lv_creat_about_page(lv_ui *ui, lv_obj_t *title_section)
{
    char buf[128 * 2] = {0};
    lv_obj_t *about_page = lv_menu_page_create(ui->menu, NULL);                                                // 创建菜单界面
    lv_obj_set_style_pad_hor(about_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    lv_obj_t *cont = create_text(title_section, "关于");                                                       // 创建Mechanics菜单子项
    lv_menu_set_load_page_event(ui->menu, cont, about_page);
    lv_obj_add_event_cb(cont, _setting_clicked_event_cb, LV_EVENT_CLICKED, ui);

    lv_menu_separator_create(about_page);                    // ui->menu separator
    lv_obj_t *section = lv_menu_section_create(about_page);  // Create a ui->menu section object

    lv_obj_t *about_cont = lv_obj_create(section);
    ui_init_menu_cont(about_cont, LV_OPA_COVER, 0, 60);

    lv_obj_t *about_list = lv_obj_create(about_cont);
    lv_obj_set_pos(about_list, 0, 50);
    lv_obj_set_size(about_list, 300, 400);
    lv_obj_set_flex_flow(about_list, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_layout(about_list, LV_LAYOUT_FLEX);
    lv_obj_set_style_bg_opa(about_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(about_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_border_width(about_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(about_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(about_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(about_list, lv_color_hex(0x000000), 0);

    for (size_t i = 0; i < sizeof(about_info) / sizeof(about_info[0]); i++) {
        memset(buf, 0, sizeof(buf));

        lv_obj_t *about_item = lv_obj_create(about_list);
        lv_obj_set_scrollbar_mode(about_item, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_pos(about_item, 0, 0);
        lv_obj_set_style_pad_all(about_item, 0, 0);
        lv_obj_set_style_border_width(about_item, 0, 0);
        lv_obj_set_size(about_item, 300, 50);
        lv_obj_set_style_bg_opa(about_item, 0, 0);

        lv_obj_t *about_name = lv_label_create(about_item);
        lv_obj_set_style_text_font(about_name, &HanSansCN_20, 0);
        lv_obj_set_pos(about_name, 15, 4);
        lv_obj_set_size(about_name, 280, 24);
        lv_obj_set_style_opa(about_name, LV_OPA_COVER, 0);
        lv_obj_set_style_text_color(about_name, lv_color_hex(0xffffff), 0);
        switch (i) {
            case ABOUT_INFO_PRODUCT_MODEL: {
                sprintf(buf, "%s%s", about_info[i], "HOPE_M5");
                break;
            }
            case ABOUT_INFO_SOFTWARE_VERSION: {
                sprintf(buf, "%s%s", about_info[i], "1.0.1.230624");
                break;
            }
            case ABOUT_INFO_FIRMWARE_VERSION: {
                sprintf(buf, "%s%s", about_info[i], "Debug_Hope_M5");
                break;
            }
            case ABOUT_INFO_SN_NUMBER: {
                sprintf(buf, "%s  %s", about_info[i], "test1122334455");
                break;
            }
            case ABOUT_INFO_IP_ADDRESS: {
                sprintf(buf, "%s  %s", about_info[i], "182.168.1.2");
                break;
            }
            case ABOUT_INFO_MAC_ADDRES: {
                sprintf(buf, "%s%s", about_info[i], "68:ad:e7:f9:33:3b");
                break;
            }
        }
        // sprintf(buf, "%s", about_info[i]);
        lv_label_set_text(about_name, buf);
    }

    return about_page;
}

static void _lv_creat_ota_page(lv_ui *ui, lv_obj_t *title_section)
{
    lv_obj_t *ota_page = lv_menu_page_create(ui->menu, NULL);                                                // 创建菜单界面
    lv_obj_set_style_pad_hor(ota_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    lv_obj_t *cont = create_text(title_section, "系统升级");                                                 // 创建Mechanics菜单子项
    lv_menu_set_load_page_event(ui->menu, cont, ota_page);
    lv_obj_add_event_cb(cont, _setting_clicked_event_cb, LV_EVENT_CLICKED, ui);

    lv_menu_separator_create(ota_page);                    // ui->menu separator
    lv_obj_t *section = lv_menu_section_create(ota_page);  // Create a ui->menu section

    lv_obj_t *ota_cont = lv_obj_create(section);
    ui_init_menu_cont(ota_cont, LV_OPA_COVER, 0, 60);

    lv_obj_t *ota_btn = lv_btn_create(ota_cont);
    lv_obj_add_event_cb(ota_btn, _ota_btn_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_set_pos(ota_btn, 108, 220);
    lv_obj_set_size(ota_btn, 100, 36);
    lv_obj_add_flag(ota_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ota_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

    lv_obj_add_flag(ota_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ota_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    lv_obj_set_style_bg_color(ota_btn, lv_color_hex(0xF68F3B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ota_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ota_btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ota_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *label = lv_label_create(ota_btn);
    lv_obj_set_style_text_font(label, &HanSansCN_20, 0);
    lv_label_set_text(label, "检测更新");
    lv_obj_center(label);
}

static void _lv_creat_delete_dev_page(lv_ui *ui, lv_obj_t *title_section)
{
    printf("Creating device list page\n");
    lv_obj_t *delete_dev_page = lv_menu_page_create(ui->menu, NULL);                                                // 创建菜单界面
    lv_obj_set_style_pad_hor(delete_dev_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    // 标题
    lv_obj_t *cont = create_text(title_section, "解绑设备");       // 创建Mechanics菜单子项
    lv_menu_set_load_page_event(ui->menu, cont, delete_dev_page);  // 加载cont到menu,设置跳转界面wifi_page
    lv_obj_add_event_cb(cont, _setting_clicked_event_cb, LV_EVENT_CLICKED, ui);
    lv_menu_separator_create(delete_dev_page);                     // ui->menu separator
    lv_obj_t *section = lv_menu_section_create(delete_dev_page);   // Create a ui->menu section object

    lv_obj_t *delete_cont = lv_obj_create(section);
    ui_init_menu_cont(delete_cont, LV_OPA_COVER, 0, 60);

    ui->devices_list = lv_obj_create(delete_cont);
    lv_obj_set_pos(ui->devices_list, 0, 50);
    lv_obj_set_size(ui->devices_list, 300, 350);
    lv_obj_set_flex_flow(ui->devices_list, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_layout(ui->devices_list, LV_LAYOUT_FLEX);
    lv_obj_set_style_bg_opa(ui->devices_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui->devices_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_border_width(ui->devices_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->devices_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->devices_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->devices_list, lv_color_hex(0x000000), 0);

    lv_obj_t *delete_btn = lv_btn_create(delete_cont);
    // // lv_obj_add_event_cb(delete_btn, _connect_btn_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_set_pos(delete_btn, 85, 413);
    lv_obj_add_flag(delete_btn, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(delete_btn, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    set_common_btn_style(delete_btn, 135, 40);
    lv_obj_t *label = lv_label_create(delete_btn);
    lv_obj_set_style_text_font(label, &HanSansCN_20, 0);
    lv_label_set_text(label, "删除设备");
    lv_obj_center(label);
    lv_obj_add_event_cb(delete_btn, _delete_devices_event_cb, LV_EVENT_CLICKED, ui);

    // todo 获取设备列表
    // 一键开关，窗帘，调光灯，调色温灯为一个类型
    for (size_t i = 0; i < 30; i++) {
        int j = 0;
        lv_obj_t *device_item = lv_obj_create(ui->devices_list);
        lv_obj_set_pos(device_item, 0, 0);
        lv_obj_set_scrollbar_mode(device_item, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_pad_all(device_item, 0, 0);
        lv_obj_set_style_border_width(device_item, 0, 0);
        lv_obj_set_size(device_item, 300, 20 * 3);
        lv_obj_set_style_bg_opa(device_item, 0, 0);
        lv_obj_add_flag(device_item, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_event_cb(device_item, _device_item_event_cb, LV_EVENT_CLICKED, ui);

        lv_obj_t *device_name = lv_label_create(device_item);
        lv_label_set_text(device_name, "智能灯开关");
        lv_obj_set_pos(device_name, 10, 2);
        lv_obj_set_size(device_name, 100, 20 * 3 - 2);
        lv_obj_set_style_opa(device_name, LV_OPA_COVER, 0);
        lv_label_set_long_mode(device_name, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_color(device_name, lv_color_hex(0xffffff), 0);

        lv_obj_t *cb = lv_checkbox_create(device_item);
        lv_obj_set_pos(cb, 250, 2);
        lv_obj_set_scrollbar_mode(cb, LV_SCROLLBAR_MODE_OFF);
        lv_checkbox_set_text(cb, "");
        lv_obj_set_style_radius(cb, 0, LV_PART_INDICATOR);
        lv_obj_set_style_border_width(cb, 2, LV_PART_INDICATOR);
        lv_obj_set_style_border_color(cb, lv_color_hex(0xffffff), LV_PART_INDICATOR);
        lv_obj_set_style_bg_color(cb, lv_color_hex(0x000000), LV_PART_INDICATOR);
        lv_obj_set_style_bg_color(cb, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_event_cb(cb, _devices_checkbox_cb, LV_EVENT_VALUE_CHANGED, ui);

        if ((i % 2) == 0) {
            for (j = 0; j < 2; j++) {
                lv_obj_t *subdevice_name = lv_label_create(device_name);
                lv_label_set_text(subdevice_name, "开关一");
                lv_obj_set_pos(subdevice_name, 20, 20 * (j + 1));
                lv_obj_set_size(subdevice_name, 100, 20);
                lv_obj_set_style_opa(subdevice_name, LV_OPA_COVER, 0);
                lv_obj_set_style_text_color(subdevice_name, lv_color_hex(0x999999), 0);
            }
        }
    }

    // 二键开关，三键开关，四按键开关
}

/**********************************************************************
 *Functional description:主页设置
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-22           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_set_mainpage_page(lv_ui *ui, lv_obj_t *title_section)
{
    lv_obj_t *set_mainpage_page = lv_menu_page_create(ui->menu, NULL);                                                // 创建菜单界面
    lv_obj_set_style_pad_hor(set_mainpage_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    // 标题
    lv_obj_t *cont = create_text(title_section, "主页配置");         // 创建Mechanics菜单子项
    lv_menu_set_load_page_event(ui->menu, cont, set_mainpage_page);  // 加载cont到menu,设置跳转界面wifi_page

    lv_menu_separator_create(set_mainpage_page);                     // ui->menu separator
    lv_obj_t *section = lv_menu_section_create(set_mainpage_page);   // Create a ui->menu section object
    lv_obj_add_event_cb(cont, _setting_clicked_event_cb, LV_EVENT_CLICKED, ui);

    lv_obj_t *mainpage_cont = lv_obj_create(section);
    ui_init_menu_cont(mainpage_cont, LV_OPA_COVER, 0, 60);

    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    ui->qr = lv_qrcode_create(mainpage_cont, 150, fg_color, bg_color);

    /*Set data*/
    // todo 二维码信息
    const char *data = "https://lvgl.io";
    lv_qrcode_update(ui->qr, data, strlen(data));
    lv_obj_center(ui->qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(ui->qr, bg_color, 0);
    lv_obj_set_style_border_width(ui->qr, 5, 0);
    lv_obj_add_flag(ui->qr, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->qr, _lv_qr_click_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_add_flag(ui->qr, LV_OBJ_FLAG_HIDDEN);

    ui->tip_lable = lv_label_create(mainpage_cont);
    lv_label_set_text(ui->tip_lable, "设备准备中...");
    lv_obj_set_pos(ui->tip_lable, 0, 220);
    lv_obj_set_size(ui->tip_lable, 300, 25);
    lv_obj_set_style_text_color(ui->tip_lable, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(ui->tip_lable, &HanSansCN_20, 0);
    lv_obj_add_flag(ui->tip_lable, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->tip_lable, _lv_tip_click_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_set_style_text_align(ui->tip_lable, LV_TEXT_ALIGN_CENTER, 0);
    // lv_obj_add_flag(ui->tip_lable, LV_OBJ_FLAG_HIDDEN);
}

static void msgbox_del(lv_timer_t * tmr)
{
    lv_msgbox_close(tmr->user_data);
}

static void _lv_wifi_click_event_cb(lv_event_t *e)
{
    // st_wifi *item_wifi = (st_wifi *)lv_event_get_user_data(e);
    // printf("wifi_name: %s\n", item_wifi->wifi_name);
    // printf("connect_st: %s\n", item_wifi->connect_st);
    // printf("wifi_dbm: %d\n", item_wifi->wifi_dbm);
    // printf("lock_st: %d\n", item_wifi->lock_st);
    printf("goto wifi setting\n");
    lv_obj_t *wifi_tag = lv_event_get_target(e);
    lv_ui *ui = lv_event_get_user_data(e);
    uint32_t index = lv_obj_get_index(wifi_tag);
    // ui->wifi_selected = index;

    printf("wifi_tag: %d, %s\n", index, st_wifi_item[index].wifi_name);

    lv_obj_t *obj = lv_msgbox_create(NULL, "提示", "连接失败，请检查密码是否正确。", NULL, false);
    lv_obj_set_style_text_font(obj, &HanSansCN_20, 0);
    lv_obj_center(obj);

    lv_timer_t * msgbox_tmr = lv_timer_create(msgbox_del, 1000 * 2, obj);
    lv_timer_set_repeat_count(msgbox_tmr, 1);
#if 0
    memcpy(ui->wifi_select.ssid, st_wifi_item[index].wifi_name, strlen(st_wifi_item[index].wifi_name));
    lv_obj_t *act_scr = lv_scr_act();
    lv_disp_t *d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        lv_obj_clean(act_scr);
        if (ui->Wifi_Set_del == true)
            ui_wifi_set(ui);
        lv_scr_load_anim(ui->Wifi_Set, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
        ui->Setting_del = true;
    }
#endif
}
static lv_obj_t *_wifi_list_add_item(lv_ui *ui, lv_obj_t *wifi_list, st_wifi *scan_ap, const char *link_ssid)
{
    lv_obj_t *wifi_item = lv_obj_create(wifi_list);

    if (wifi_item == NULL) {
        return NULL;
    }

    lv_obj_set_size(wifi_item, 300, 50);
    lv_obj_set_style_bg_opa(wifi_item, LV_OPA_COVER, 0);
    lv_obj_set_style_pad_all(wifi_item, 0, 0);
    lv_obj_set_style_border_width(wifi_item, 0, 0);
    lv_obj_add_flag(wifi_item, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_FOCUSED);

    lv_obj_t *wifi_name = lv_label_create(wifi_item);
    lv_label_set_text(wifi_name, (const char *)scan_ap->wifi_name);
    lv_label_set_long_mode(wifi_name, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_pos(wifi_name, 10, 2);
    lv_obj_set_size(wifi_name, 200, 24);
    lv_obj_set_style_opa(wifi_name, LV_OPA_COVER, 0);
    lv_obj_set_style_text_color(wifi_name, lv_color_hex(0xffffff), 0);

    // wifi st
    lv_obj_t *wifi_st = lv_label_create(wifi_item);
    if (strcmp(scan_ap->wifi_name, link_ssid) == 0)
        lv_label_set_text(wifi_st, "已连接");
    else
        lv_label_set_text(wifi_st, "未连接");
    lv_obj_set_pos(wifi_st, 10, 26);
    lv_obj_set_size(wifi_st, 100, 24);
    lv_obj_set_style_opa(wifi_st, LV_OPA_COVER, 0);
    lv_obj_set_style_text_color(wifi_st, lv_color_hex(0xffffff), 0);
    // wifi dbm
    lv_obj_t *wifi_dbm = lv_img_create(wifi_item);
    if (scan_ap->wifi_dbm == 1) {
        lv_img_set_src(wifi_dbm, &ic_wifi3);
    }
    else if (scan_ap->wifi_dbm == 2) {
        lv_img_set_src(wifi_dbm, &ic_wifi2);
    }
    else {
        lv_img_set_src(wifi_dbm, &ic_wifi1);
    }
    lv_obj_set_pos(wifi_dbm, 250, 5);

    // wifi password
    if (scan_ap->lock_st != false) {
        lv_obj_t *wifi_lock = lv_img_create(wifi_item);
        lv_img_set_src(wifi_lock, &ic_lock);
        lv_obj_set_pos(wifi_lock, 275, 9);
    }

    lv_obj_add_event_cb(wifi_item, _lv_wifi_click_event_cb, LV_EVENT_CLICKED, ui);

    return wifi_item;
}

/**********************************************************************
 *Functional description:创建wifi界面
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-18           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_wifi_page(lv_ui *ui, lv_obj_t *title_section)
{
    printf("Creating wifi page\n");
    lv_obj_t *wifi_page = lv_menu_page_create(ui->menu, NULL);                                                // 创建菜单界面
    lv_obj_set_style_pad_hor(wifi_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    // 标题
    lv_obj_t *cont = create_text(title_section, "WIFI设置");  // 创建Mechanics菜单子项
    lv_menu_set_load_page_event(ui->menu, cont, wifi_page);   // 加载cont到menu,设置跳转界面wifi_page
    // lv_obj_add_event_cb(cont, _setting_wifi_clicked_event_cb, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(cont, _setting_clicked_event_cb, LV_EVENT_CLICKED, ui);

    lv_menu_separator_create(wifi_page);                    // ui->menu separator
    lv_obj_t *section = lv_menu_section_create(wifi_page);  // Create a ui->menu section object
    // todo wifi界面内容
    // todo 获取wifi列表

    lv_obj_t *wifi_cont = lv_obj_create(section);
    ui_init_menu_cont(wifi_cont, LV_OPA_COVER, 0, 60);

    lv_obj_t *wifi_lable = lv_label_create(wifi_cont);
    lv_label_set_text(wifi_lable, "Wi-Fi");
    lv_obj_set_pos(wifi_lable, 20, 50);
    lv_obj_set_size(wifi_lable, 100, 25);
    lv_obj_set_style_text_color(wifi_lable, lv_color_hex(0xffffff), 0);

    // todo 获取wifi开关状态
    lv_obj_t *wifi_switch = lv_switch_create(wifi_cont);
    lv_obj_set_style_bg_color(wifi_switch, lv_color_hex(0xF68F3B), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_state(wifi_switch, LV_STATE_CHECKED);
    lv_obj_set_pos(wifi_switch, 240, 50);
    lv_obj_add_event_cb(wifi_switch, switch_handler, LV_EVENT_VALUE_CHANGED, ui);

    ui->wifi_list = lv_obj_create(wifi_cont);
    lv_obj_set_pos(ui->wifi_list, 0, 90);
    lv_obj_set_size(ui->wifi_list, 300, 390);
    lv_obj_set_flex_flow(ui->wifi_list, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_layout(ui->wifi_list, LV_LAYOUT_FLEX);
    lv_obj_set_style_bg_opa(ui->wifi_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui->wifi_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_border_width(ui->wifi_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->wifi_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->wifi_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->wifi_list, lv_color_hex(0x000000), 0);

    // test wifi item
    for (size_t i = 0; i < ARRAY_SIZE(st_wifi_item); i++) {
#if 0
        wifi_item = lv_obj_create(ui->wifi_list);
        lv_obj_set_style_pad_all(wifi_item, 0, 0);
        lv_obj_set_style_border_width(wifi_item, 0, 0);
        // LV_STATE_CHECKED
        lv_obj_add_flag(wifi_item, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(wifi_item, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_FOCUSED);
        lv_obj_set_size(wifi_item, 300, 50);
        lv_obj_set_style_bg_opa(wifi_item, LV_OPA_COVER, 0);

        // wifi name
        lv_obj_t *wifi_name = lv_label_create(wifi_item);
        lv_label_set_text(wifi_name, st_wifi_item[i].wifi_name);
        lv_obj_set_pos(wifi_name, 10, 2);
        lv_obj_set_size(wifi_name, 200, 24);
        lv_obj_set_style_opa(wifi_name, LV_OPA_COVER, 0);
        lv_obj_set_style_text_color(wifi_name, lv_color_hex(0xffffff), 0);

        // wifi st
        lv_obj_t *wifi_st = lv_label_create(wifi_item);
        lv_label_set_text(wifi_st, st_wifi_item[i].connect_st);
        lv_obj_set_pos(wifi_st, 10, 26);
        lv_obj_set_size(wifi_st, 100, 24);
        lv_obj_set_style_opa(wifi_st, LV_OPA_COVER, 0);
        lv_obj_set_style_text_color(wifi_st, lv_color_hex(0xffffff), 0);

        // wifi dbm
        lv_obj_t *wifi_dbm = lv_img_create(wifi_item);
        if (st_wifi_item[i].wifi_dbm == 1) {
            LV_IMG_DECLARE(ic_wifi1);
            lv_img_set_src(wifi_dbm, &ic_wifi1);
        }
        else if (st_wifi_item[i].wifi_dbm == 2) {
            LV_IMG_DECLARE(ic_wifi2);
            lv_img_set_src(wifi_dbm, &ic_wifi2);
        }
        else if (st_wifi_item[i].wifi_dbm == 3) {
            LV_IMG_DECLARE(ic_wifi3);
            lv_img_set_src(wifi_dbm, &ic_wifi3);
        }
        lv_obj_set_pos(wifi_dbm, 250, 5);

        // wifi password
        if (st_wifi_item[i].lock_st) {
            lv_obj_t *wifi_lock = lv_img_create(wifi_item);
            LV_IMG_DECLARE(ic_lock);
            lv_img_set_src(wifi_lock, &ic_lock);
            lv_obj_set_pos(wifi_lock, 275, 9);
        }
        lv_obj_add_event_cb(wifi_item, _lv_wifi_click_event_cb, LV_EVENT_CLICKED, ui);
#else
        _wifi_list_add_item(ui, ui->wifi_list, &st_wifi_item[i], "vsdfgvdfg");
#endif
    }
}

/**********************************************************************
 *Functional description:创建设置菜单
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-18           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_create_setting_menu(lv_ui *ui)
{
    ui->menu = lv_menu_create(ui->Setting);                                   // 创建菜单对象
    lv_obj_set_style_bg_color(ui->menu, lv_color_hex(0x000000), 0);           // 设置背景颜色
    lv_menu_set_mode_root_back_btn(ui->menu, LV_MENU_ROOT_BACK_BTN_ENABLED);  // 使能根菜单返回键
    lv_obj_set_size(ui->menu, 480, 480);                                      // 设置大小
    lv_obj_center(ui->menu);                                                  // 居中显示
    lv_obj_set_style_text_font(ui->menu, &HanSansCN_20, 0);

    // lv_obj_t *ok_lable = lv_label_create(ui->menu);
    // lv_label_set_text(ok_lable, "完成");
    // lv_obj_set_pos(ok_lable, 300, 0);
    // lv_obj_set_size(ok_lable, 60, 20);
    // lv_obj_set_style_text_color(ok_lable, lv_color_hex(0xffffff), 0);

    lv_obj_t *root_page = lv_menu_page_create(ui->menu, "设置");
    lv_obj_set_style_text_font(root_page, &HanSansCN_20, 0);
    lv_obj_set_style_pad_hor(root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(ui->menu), 0), 0);  // 设置水平PAD间距
    lv_obj_t *title_section = lv_menu_item_create(root_page);                                                 // 创建标题
    lv_menu_set_sidebar_page(ui->menu, root_page);                                                            // 设置菜单sidebar风格显示
    // todo 创建好所有标题，和wifi界面，进入的时候，先显示。后续点击再跳转到相应的界面

    // todo 创建wifi界面
    _lv_creat_wifi_page(ui, title_section);

    // todo 创建主页配置界面--可以先不加载，点击之后再加载？
    _lv_creat_set_mainpage_page(ui, title_section);

    // todo 创建解绑设备界面
    _lv_creat_delete_dev_page(ui, title_section);

    // todo 创建OTA升级界面
    _lv_creat_ota_page(ui, title_section);

    // todo 关于界面
    _lv_creat_about_page(ui, title_section);

    // 发送点击事件 让首次进入界面直接到wifi
    lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(ui->menu), 0), 0), LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui->menu, back_event_handler, LV_EVENT_CLICKED, ui);  // 添加返回键点击事件
    lv_obj_add_event_cb(ui->menu, _menu_event_cb, LV_EVENT_VALUE_CHANGED, ui);

    if (qr_timer != NULL) {
        lv_timer_del(qr_timer);
        qr_timer = NULL;
    }
    qr_timer = lv_timer_create(_qrcode_timer_callback, 1000 * GET_QRCODE_TIMEOUT, ui);
    if(qr_timer != NULL){
        lv_timer_pause(qr_timer);
    }
}

/**********************************************************************
 *Functional description:设置界面
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-18           V1.0           RunningCode             Create
 ***********************************************************************/
void setup_scr_Setting(lv_ui *ui)
{
    // Write codes APP
    ui->Setting = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ui->Setting, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for style_app_main_main_default
    static lv_style_t style_setting_main_main_default;
    if (style_setting_main_main_default.prop_cnt > 1)
        lv_style_reset(&style_setting_main_main_default);
    else
        lv_style_init(&style_setting_main_main_default);
    lv_style_set_bg_opa(&style_setting_main_main_default, LV_OPA_TRANSP);
    lv_obj_add_style(ui->Setting, &style_setting_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);



    _lv_create_setting_menu(ui);
}