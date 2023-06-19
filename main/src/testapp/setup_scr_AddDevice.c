/*
 * @Company: HOPE
 * @Author: RunningCode
 * @Date: 2023-04-21 17:27:27
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-25 17:27:39
 * @Description:
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\setup_scr_AddDevice.c
 */
#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "ui_common.h"

static char cDown_cnt = COUNTDOWN_CNT_60S;
static lv_timer_t  * sec_counter_timer = NULL;

static void _lv_creat_add_device_page(lv_ui *ui);
static void _lv_creat_add_device_failed(lv_ui *ui);



static void _countdown_timer_callback(lv_timer_t * t)
{

    lv_ui *ui = (lv_ui *)t->user_data;;
    char time[12] = {0};

    memset(time, 0, sizeof(time));
    cDown_cnt--;
    printf("cdown %d\r\n", cDown_cnt);
    snprintf(time, sizeof(time), "%ds", cDown_cnt);
    lv_label_set_text(ui->Countdown_lable, time);
    if (cDown_cnt < 0) {
        cDown_cnt = COUNTDOWN_CNT_60S;

        printf("enter failed cont\r\n");
        // 隐藏添加设备界面
        lv_obj_add_flag(ui->add_cont, LV_OBJ_FLAG_HIDDEN);
        // 显示添加失败界面
        lv_obj_clear_flag(ui->failed_cont, LV_OBJ_FLAG_HIDDEN);
        snprintf(time, sizeof(time), "%ds", cDown_cnt);
        lv_label_set_text(ui->Countdown_lable, time);
        lv_timer_pause(sec_counter_timer);
    }
}


static void back_HomePage(lv_ui *ui)
{
    lv_obj_t *act_scr = lv_scr_act();
    lv_disp_t *d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
    {
        lv_obj_clean(act_scr);
        if (ui->HomePage_del == true)
            setup_scr_HomePage(ui);
        lv_scr_load_anim(ui->HomePage, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
        ui->AddDevice_del = true;

        if(sec_counter_timer != NULL) {
            lv_timer_del(sec_counter_timer);
            sec_counter_timer = NULL;
        }
    }
}

static void back_HomePage_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    back_HomePage(ui);
}


static void goto_success_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    // 隐藏添加设备界面
    lv_obj_add_flag(ui->add_cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->failed_cont, LV_OBJ_FLAG_HIDDEN);
    // 显示添加成功界面
    lv_obj_clear_flag(ui->successed_cont, LV_OBJ_FLAG_HIDDEN);
    cDown_cnt = COUNTDOWN_CNT_60S;
    lv_timer_pause(sec_counter_timer);

    lv_label_set_text(ui->succeed_lable, "四键开关");
}

static void goto_failed_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    // 隐藏添加设备界面
    lv_obj_add_flag(ui->add_cont, LV_OBJ_FLAG_HIDDEN);
    // 显示添加设备界面
    lv_obj_clear_flag(ui->failed_cont, LV_OBJ_FLAG_HIDDEN);

    cDown_cnt = COUNTDOWN_CNT_60S;
    lv_timer_pause(sec_counter_timer);
}

static void add_again_event_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    // 隐藏添加设备失败界面
    lv_obj_add_flag(ui->failed_cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->successed_cont, LV_OBJ_FLAG_HIDDEN);
    // 显示添加设备界面
    lv_obj_clear_flag(ui->add_cont, LV_OBJ_FLAG_HIDDEN);

    cDown_cnt = COUNTDOWN_CNT_60S;
    
    lv_timer_resume(sec_counter_timer);
}


static void set_add_device_btn_style(lv_obj_t *btn, int w, int h)
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

/**********************************************************************
 *Functional description:创建返回按钮
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-15           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_back_HomePage_btn(lv_ui *ui)
{
    // 手动绘制
    // static lv_point_t back_icon_point[] = {{15, 0}, {0, 13}, {15, 26}};
    // lv_obj_t *back_btn = lv_obj_create(ui->AddDevice);
    // lv_obj_set_pos(back_btn, 0, 0);
    // lv_obj_set_size(back_btn, 55, 55);
    // lv_obj_set_style_pad_all(back_btn, 0, 0);
    // lv_obj_set_style_border_width(back_btn, 0, 0);
    // lv_obj_set_scrollbar_mode(back_btn, LV_SCROLLBAR_MODE_OFF);
    // lv_obj_set_style_bg_opa(back_btn, LV_OPA_TRANSP, 0);
    // lv_obj_add_flag(back_btn, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(back_btn, back_HomePage_event_cb, LV_EVENT_CLICKED, ui);

    // lv_obj_t *back_icon = lv_line_create(back_btn);
    // lv_obj_set_pos(back_icon, 29, 16);
    // lv_obj_set_size(back_icon, 15, 26);

    // lv_line_set_points(back_icon, back_icon_point, 3);
    // lv_obj_set_scrollbar_mode(back_icon, LV_SCROLLBAR_MODE_OFF);
    // lv_obj_set_style_bg_opa(back_icon, LV_OPA_TRANSP, 0);
    // lv_obj_set_style_line_color(back_icon, lv_color_hex(0xFFFFFF), 0);
    // lv_obj_set_style_line_width(back_icon, 3, 0);
    // lv_obj_set_style_line_rounded(back_icon, true, 0);

    lv_obj_t *back_btn = lv_obj_create(ui->AddDevice);
    lv_obj_set_pos(back_btn, 0, 0);
    lv_obj_set_size(back_btn, 60, 60);
    ui_init_cont(back_btn, LV_OPA_TRANSP);
    lv_obj_add_flag(back_btn, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(back_btn, back_HomePage_event_cb, LV_EVENT_CLICKED, ui);

    LV_IMG_DECLARE(ic_back);
    lv_obj_t *img_btn = lv_img_create(back_btn);
    lv_img_set_src(img_btn, &ic_back);
    lv_obj_set_pos(img_btn, 29, 16);
}

/**********************************************************************
 *Functional description:添加设备成功
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-15           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_add_device_successed(lv_ui *ui)
{
    ui->successed_cont = lv_obj_create(ui->AddDevice);
    lv_obj_set_pos(ui->successed_cont, 0, 60);
    lv_obj_set_size(ui->successed_cont, LCD_WIDTH, LCD_HEIGHT - 60);
    ui_init_cont(ui->successed_cont, LV_OPA_TRANSP);


    LV_IMG_DECLARE(ic_succeed);
    lv_obj_t *succeed_icon = lv_img_create(ui->successed_cont);
    lv_img_set_src(succeed_icon, &ic_succeed);
    lv_obj_set_pos(succeed_icon, 204, 10);
    lv_obj_set_size(succeed_icon, 72, 72);
    
    ui->succeed_lable = lv_label_create(ui->successed_cont);
    lv_obj_set_pos(ui->succeed_lable, 60, 160);
    lv_obj_set_size(ui->succeed_lable, 160, 48);
    lv_obj_set_style_text_color(ui->succeed_lable, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(ui->succeed_lable, &HanSansCN_20, 0);
    lv_label_set_text(ui->succeed_lable, "");

    lv_obj_t *btn_add_ok = lv_btn_create(ui->successed_cont);
    lv_obj_add_event_cb(btn_add_ok, add_again_event_cb, LV_EVENT_CLICKED, ui);
    set_add_device_btn_style(btn_add_ok, 160, 48);
    lv_obj_set_pos(btn_add_ok, 156, 332);
    lv_obj_t *lab_add_ok = lv_label_create(btn_add_ok);
    lv_obj_set_style_text_font(lab_add_ok, &HanSansCN_20, 0);
    lv_label_set_text(lab_add_ok, "完成");
    lv_obj_align(lab_add_ok, LV_ALIGN_CENTER, 0, 0);
    
}



/**********************************************************************
 *Functional description:添加设备失败
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-15           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_add_device_failed(lv_ui *ui)
{
    ui->failed_cont = lv_obj_create(ui->AddDevice);
    lv_obj_set_pos(ui->failed_cont, 0, 60);
    lv_obj_set_size(ui->failed_cont, LCD_WIDTH, LCD_HEIGHT - 60);
    ui_init_cont(ui->failed_cont, LV_OPA_TRANSP);

    LV_IMG_DECLARE(ic_failed);
    lv_obj_t *failed_icon = lv_img_create(ui->failed_cont);
    lv_img_set_src(failed_icon, &ic_failed);
    lv_obj_set_pos(failed_icon, 204, 10);
    lv_obj_set_size(failed_icon, 72, 72);
    lv_obj_t *failed_lable = lv_label_create(ui->failed_cont);
    lv_obj_set_pos(failed_lable, 60, 160);
    lv_obj_set_size(failed_lable, 360, 48);
    lv_obj_set_style_text_color(failed_lable, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(failed_lable, &HanSansCN_20, 0);
    lv_label_set_text(failed_lable, "未发现设备，请检查待配对设备是否进入配网状态。");

    lv_obj_t *btn_add_f = lv_btn_create(ui->failed_cont);
    lv_obj_add_event_cb(btn_add_f, add_again_event_cb, LV_EVENT_CLICKED, ui);
    set_add_device_btn_style(btn_add_f, 160, 48);
    lv_obj_set_pos(btn_add_f, 156, 332);
    lv_obj_t *lab_add_f = lv_label_create(btn_add_f);
    lv_obj_set_style_text_font(lab_add_f, &HanSansCN_20, 0);
    lv_label_set_text(lab_add_f, "返回");
    lv_obj_align(lab_add_f, LV_ALIGN_CENTER, 0, 0);
}

/**********************************************************************
 *Functional description:旋转图片
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-25           V1.0           RunningCode             Create
 ***********************************************************************/
static void set_angle(void *img, int32_t v)
{
    lv_img_set_angle(img, v);
}

/**********************************************************************
 *Functional description:添加设备中
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-15           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_add_device_page(lv_ui *ui)
{
    char time[12] = {0};

    ui->add_cont = lv_obj_create(ui->AddDevice);
    lv_obj_set_pos(ui->add_cont, 0, 60);
    lv_obj_set_size(ui->add_cont, LCD_WIDTH, 420);
    ui_init_cont(ui->add_cont, LV_OPA_TRANSP);

    lv_obj_t *findDevice_lable = lv_label_create(ui->add_cont);
    lv_obj_set_pos(findDevice_lable, 160, 40);
    lv_obj_set_size(findDevice_lable, 170, 30);
    lv_obj_set_style_text_color(findDevice_lable, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(findDevice_lable, &HanSansCN_20, 0);
    lv_label_set_text(findDevice_lable, "正在发现设备");

    ui->Countdown_lable = lv_label_create(ui->add_cont);
    lv_obj_set_pos(ui->Countdown_lable, 290, 40);
    lv_obj_set_size(ui->Countdown_lable, 170, 30);
    lv_obj_set_style_text_color(ui->Countdown_lable, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(ui->Countdown_lable, &HanSansCN_20, 0);
    memset(time, 0, sizeof(time));
    snprintf(time, sizeof(time), "%ds", cDown_cnt);
    lv_label_set_text(ui->Countdown_lable, time);
    // todo 发送发现设备指令

    // todo 创建60s定时器  超时就失败
    sec_counter_timer = lv_timer_create(_countdown_timer_callback, 1000, ui);
    lv_timer_resume(sec_counter_timer); //启动定时器定时器

    // todo 创建一个spinner
    LV_IMG_DECLARE(ic_loading);
    lv_obj_t *img_spinner = lv_img_create(ui->add_cont);
    lv_obj_set_pos(img_spinner, 218, 160);
    lv_img_set_src(img_spinner, &ic_loading);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, img_spinner);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_values(&a, 0, 3600);
    lv_anim_set_time(&a, 6000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    lv_obj_add_flag(img_spinner, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img_spinner, goto_success_event_cb, LV_EVENT_CLICKED, ui);
}
static void _lv_creat_readd_btn(lv_ui *ui)
{
    lv_obj_t *btn_add_again = lv_btn_create(ui->AddDevice);

    set_add_device_btn_style(btn_add_again, 160, 48);
    lv_obj_set_pos(btn_add_again, 156, 350);
    // lv_obj_set_size(btn_add_again, 160, 48);
    // lv_obj_set_style_bg_opa(btn_add_again, LV_OPA_20, 0);
    // lv_obj_set_style_border_width(btn_add_again, 0, 0);
    // lv_obj_set_style_radius(btn_add_again, 10, 0);
    // lv_obj_set_style_shadow_width(btn_add_again, 0, 0);
    // lv_obj_set_scrollbar_mode(btn_add_again, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_event_cb(btn_add_again, add_again_event_cb, LV_EVENT_CLICKED, ui);

    lv_obj_t *lab_add_again = lv_label_create(btn_add_again);
    lv_label_set_text(lab_add_again, "Add Again");
    lv_obj_align(lab_add_again, LV_ALIGN_CENTER, 0, 0);
}

void setup_scr_AddDevice(lv_ui *ui)
{
    // Write codes AddDevice
    ui->AddDevice = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ui->AddDevice, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for style_AddDevice_main_main_default
    static lv_style_t style_AddDevice_main_main_default;
    if (style_AddDevice_main_main_default.prop_cnt > 1)
        lv_style_reset(&style_AddDevice_main_main_default);
    else
        lv_style_init(&style_AddDevice_main_main_default);
    lv_style_set_bg_img_src(&style_AddDevice_main_main_default, &bg);
    lv_style_set_bg_opa(&style_AddDevice_main_main_default, 255);
    lv_obj_add_style(ui->AddDevice, &style_AddDevice_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 返回主页按钮
    _lv_creat_back_HomePage_btn(ui);
    // 添加设备中
    _lv_creat_add_device_page(ui);
    // 添加设备成功
    _lv_creat_add_device_successed(ui);
    // 添加设备失败
    _lv_creat_add_device_failed(ui);
    lv_obj_add_flag(ui->failed_cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->successed_cont, LV_OBJ_FLAG_HIDDEN);
    // _lv_creat_readd_btn(ui);
    // 监听事件，收到设备添加成功，或者设备添加失败的消息
}