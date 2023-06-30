/*
 * @Company: Hope
 * @Author: RunningCode
 * @Date: 2023-04-21 11:03:02
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-05-25 10:20:38
 * @Description:
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\main\src\testapp\setup_scr_HomePage.c
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "ui_common.h"

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// 模拟数据
typedef struct
{
	bool dev_st;
	bool dev_online;
	int16_t dev_type;
	int32_t dev_id;
	char dev_name[18];
} st_device;

st_device device_item[] = {
	{.dev_st = true, .dev_online = true, .dev_type = 1, .dev_name = "bt1", .dev_id = 15},
	{.dev_st = true, .dev_online = true, .dev_type = 1, .dev_name = "bt21", .dev_id = 16},
	{.dev_st = true, .dev_online = true, .dev_type = 2, .dev_name = "curtain1", .dev_id = 17},
	{.dev_st = true, .dev_online = true, .dev_type = 1, .dev_name = "bt3", .dev_id = 18},
	{.dev_st = true, .dev_online = true, .dev_type = 2, .dev_name = "curtain2", .dev_id = 19},
	{.dev_st = true, .dev_online = true, .dev_type = 4, .dev_name = "dimming", .dev_id = 20},
	{.dev_st = true, .dev_online = true, .dev_type = 1, .dev_name = "btn5", .dev_id = 21},
	{.dev_st = true, .dev_online = true, .dev_type = 3, .dev_name = "scene1", .dev_id = 22},
	{.dev_st = true, .dev_online = true, .dev_type = 3, .dev_name = "go home", .dev_id = 23},
	{.dev_st = true, .dev_online = true, .dev_type = 5, .dev_name = "color1", .dev_id = 24},
	{.dev_st = true, .dev_online = true, .dev_type = 2, .dev_name = "curtain3", .dev_id = 25},
	{.dev_st = true, .dev_online = true, .dev_type = 5, .dev_name = "color2", .dev_id = 26},
	{.dev_st = true, .dev_online = true, .dev_type = 3, .dev_name = "scene2", .dev_id = 27},

};


static void set_main_page_device_card_style(lv_obj_t *device, int w, int h)
{
	if(device == NULL) {
		printf("obj device is null!\r\n");
		return;
	}
	
	lv_obj_set_size(device, w, h);
    // lv_obj_add_flag(switch_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  /// Flags
    // lv_obj_clear_flag(switch_btn, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
	lv_obj_set_style_radius(device, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(device, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(device, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(device, lv_color_hex(0xB5AFAF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(device, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(device, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(device, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

/**********************************************************************
 *Functional description:开关 设备点击事件
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
static void Device_switch_click_event_cb(lv_event_t *e)
{
	lv_obj_t *obj = lv_event_get_target(e);

	uint32_t idx = lv_obj_get_index(obj);
	lv_obj_t *light_icon = lv_event_get_user_data(e);
	printf("stat:%d\n", lv_obj_get_state(light_icon));
	if (LV_STATE_DEFAULT == lv_obj_get_state(light_icon))
	{
		lv_imgbtn_set_state(light_icon, LV_IMGBTN_STATE_CHECKED_RELEASED);
		// todo 发送开关消息
	}
	else if (LV_STATE_CHECKED == lv_obj_get_state(light_icon))
	{
		lv_imgbtn_set_state(light_icon, LV_IMGBTN_STATE_RELEASED);
		// todo 发送开关消息
	}
	// guider_ui.MainPage
	uint16_t page_index = lv_tabview_get_tab_act(guider_ui.tabview);
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	printf("page index = %d\n", page_index);
}

static void Device_switch_value_event_cb(lv_event_t *e)
{
	lv_obj_t *obj = lv_event_get_target(e);
	lv_obj_t *light_icon = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(light_icon);
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	// todo 发送开关消息

}

/**********************************************************************
 *Functional description:开关设备解析
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
void Device_switch(lv_obj_t *DeviceList, int16_t device_num)
{
	printf("device_num:%d; dev_id:%d ; name:%s\n", device_num, device_item[device_num].dev_id, device_item[device_num].dev_name);
	lv_obj_t *switch_btn = lv_obj_create(DeviceList);
	ui_init_device(switch_btn);

#if HOPEPAGE_USE_PIC
	lv_obj_t *bg = lv_img_create(switch_btn);
	LV_IMG_DECLARE(device_bg);
	lv_img_set_src(bg, &device_bg);
#else
    set_main_page_device_card_style(switch_btn, 215, 140);
#endif

    // 开关是switch 的状态，有打开和关闭
	LV_IMG_DECLARE(light_on);
	LV_IMG_DECLARE(light_off);
	lv_obj_t *light_icon = lv_imgbtn_create(switch_btn);
	lv_obj_set_pos(light_icon, 24, 41);
	lv_obj_set_size(light_icon, 58, 58);
	lv_imgbtn_set_src(light_icon, LV_IMGBTN_STATE_RELEASED, NULL, &light_on, NULL);
	lv_imgbtn_set_src(light_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &light_off, NULL);
	lv_obj_add_flag(light_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_obj_add_event_cb(light_icon, Device_switch_value_event_cb, LV_EVENT_VALUE_CHANGED, switch_btn);
	lv_obj_add_event_cb(switch_btn, Device_switch_click_event_cb, LV_EVENT_CLICKED, light_icon);

	lv_obj_t *switch_name = lv_label_create(switch_btn);
	lv_label_set_text(switch_name, device_item[device_num].dev_name);
	lv_obj_set_pos(switch_name, 100, 60);
	lv_obj_set_size(switch_name, 100, 25);
	lv_obj_set_style_text_color(switch_name, lv_color_hex(0xffffff), 0);
}

static void Device_scene_click_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *obj = lv_event_get_target(e);
	uint32_t idx = lv_obj_get_index(obj);
	lv_obj_t *scene_icon = lv_event_get_user_data(e);
	LV_IMG_DECLARE(scene_on);
	LV_IMG_DECLARE(scene_off);

	lv_img_set_src(scene_icon, &scene_on);
	// todo 执行情景
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);

	// todo 延时绘制或者做个定时器
	// rtos_delay_milliseconds
	lv_img_set_src(scene_icon, &scene_off);
}

/**********************************************************************
 *Functional description:情景按钮
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
void Device_scene(lv_obj_t *DeviceList, int16_t device_num)
{
	printf("device_num:%d; dev_id:%d ; name:%s\n", device_num, device_item[device_num].dev_id, device_item[device_num].dev_name);
	lv_obj_t *scene_btn = lv_obj_create(DeviceList);
	ui_init_device(scene_btn);

	LV_IMG_DECLARE(device_bg);
	lv_obj_t *bg = lv_img_create(scene_btn);
	lv_img_set_src(bg, &device_bg);

	// 情景默认状态
	LV_IMG_DECLARE(scene_off);
	lv_obj_t *scene_icon = lv_img_create(scene_btn);
	lv_img_set_src(scene_icon, &scene_off);
	lv_obj_set_pos(scene_icon, 24, 41);
	lv_obj_add_event_cb(scene_btn, Device_scene_click_event_cb, LV_EVENT_CLICKED, scene_icon);

	lv_obj_t *scene_name = lv_label_create(scene_btn);
	lv_label_set_text(scene_name, device_item[device_num].dev_name);
	lv_obj_set_pos(scene_name, 100, 60);
	lv_obj_set_size(scene_name, 100, 25);
	lv_obj_set_style_text_color(scene_name, lv_color_hex(0xffffff), 0);
}

/**********************************************************************
 *Functional description:调光灯设备滑动
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
static void dimming_light_value_change_event_cb(lv_event_t *e)
{
	lv_obj_t *dimming_light = lv_event_get_target(e);
	lv_obj_t *dimming_light_value = lv_event_get_user_data(e);
	lv_label_set_text_fmt(dimming_light_value, "%d%%", lv_slider_get_value(dimming_light));
}

static void dimming_light_released_event_cb(lv_event_t *e)
{
	lv_obj_t *dimming_light = lv_event_get_target(e);
	lv_obj_t *obj = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(obj);
	printf("dimming:%d; ", lv_slider_get_value(dimming_light));
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	// todo 发送灯光亮度的具体参数
}

/**********************************************************************
 *Functional description:调光灯设备解析
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
void Device_dimming_light(lv_obj_t *DeviceList, int16_t device_num)
{
	lv_obj_t *dimming_light = lv_obj_create(DeviceList);
	ui_init_device(dimming_light);

	// LV_IMG_DECLARE(big_device_bg);
	// lv_obj_t *bg = lv_img_create(dimming_light);
	// lv_img_set_src(bg, &big_device_bg);
	set_main_page_device_card_style(dimming_light, 440, 140);

	LV_IMG_DECLARE(light_off);
	lv_obj_t *light_icon = lv_img_create(dimming_light);
	lv_img_set_src(light_icon, &light_off);
	lv_img_set_zoom(light_icon, 190);
	lv_obj_set_pos(light_icon, 21, 58);

	lv_obj_t *dimming_light_name = lv_label_create(dimming_light);
	lv_label_set_text(dimming_light_name, device_item[device_num].dev_name);
	lv_obj_set_pos(dimming_light_name, 30, 30);
	lv_obj_set_size(dimming_light_name, 100, 25);
	lv_obj_set_style_text_color(dimming_light_name, lv_color_hex(0xffffff), 0);

	// 调光亮度
	lv_obj_t *dimming_light_slider = lv_slider_create(dimming_light);
	lv_obj_t *dimming_light_value = lv_label_create(dimming_light_slider);
	lv_label_set_text(dimming_light_value, "78%");
	// todo 格式化显示获取到的百分比
	// lv_label_set_text_fmt(dimming_light_value, "%d%%",lv_slider_get_value(obj));
	lv_obj_set_pos(dimming_light_value, 40, 20);
	lv_obj_set_size(dimming_light_value, 100, 25);
	lv_obj_set_style_text_color(dimming_light_value, lv_color_hex(0x333333), 0);

	lv_obj_set_pos(dimming_light_slider, 170, 42);
	lv_obj_set_size(dimming_light_slider, 240, 56);
	lv_obj_set_style_radius(dimming_light_slider, 4, 0);
	lv_obj_set_style_bg_color(dimming_light_slider, lv_color_hex(0x87878b), 0);
	lv_obj_set_style_bg_opa(dimming_light_slider, LV_OPA_60, 0);
	lv_obj_set_style_radius(dimming_light_slider, 4, LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(dimming_light_slider, lv_color_hex(0xf8dcc4), LV_PART_INDICATOR);
	lv_obj_set_style_bg_opa(dimming_light_slider, 0, LV_PART_KNOB);
	lv_obj_add_event_cb(dimming_light_slider, dimming_light_value_change_event_cb, LV_EVENT_VALUE_CHANGED, dimming_light_value);
	lv_obj_add_event_cb(dimming_light_slider, dimming_light_released_event_cb, LV_EVENT_VALUE_CHANGED, dimming_light);
	// 初始值
	lv_slider_set_value(dimming_light_slider, 78, LV_ANIM_OFF);
}

/**********************************************************************
 *Functional description:色温调节
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-06           V1.0           RunningCode             Create
 ***********************************************************************/
static void color_light_color_value_change_event_cb(lv_event_t *e)
{
	lv_obj_t *color_light = lv_event_get_target(e);
	lv_obj_t *color_light_color_value = lv_event_get_user_data(e);
	lv_label_set_text_fmt(color_light_color_value, "%dK", lv_slider_get_value(color_light));
}

static void color_light_color_released_event_cb(lv_event_t *e)
{
	lv_obj_t *color_light = lv_event_get_target(e);
	lv_obj_t *obj = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(obj);
	printf("color :%d", lv_slider_get_value(color_light));
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	// todo 发送灯光色温的具体参数
}

/**********************************************************************
 *Functional description:亮度调节
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-06           V1.0           RunningCode             Create
 ***********************************************************************/
static void color_light_temp_value_change_event_cb(lv_event_t *e)
{
	lv_obj_t *color_light = lv_event_get_target(e);
	lv_obj_t *color_light_temp_value = lv_event_get_user_data(e);
	lv_label_set_text_fmt(color_light_temp_value, "%d%%", lv_slider_get_value(color_light));
}

static void color_light_temp_released_event_cb(lv_event_t *e)
{
	lv_obj_t *color_light = lv_event_get_target(e);
	lv_obj_t *obj = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(obj);
	printf("temp:%d", lv_slider_get_value(color_light));
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	// todo 发送灯光亮度的具体参数
}

static void Color_light_click_event_cb(lv_event_t *e)
{
	// lv_obj_t *obj = lv_event_get_target(e);
	// uint32_t idx = lv_obj_get_index(obj);
	lv_obj_t *color_light = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(color_light);
	uint32_t c_cnt = lv_obj_get_child_cnt(color_light);
	lv_obj_t *light_icon = lv_obj_get_child(color_light, 1);
	printf("get obj index :%d, c_cnt: %d\n", idx, c_cnt);
	printf("stat:%d\n", lv_obj_get_state(light_icon));
	if ((LV_STATE_FOCUSED | LV_STATE_CHECKED) == lv_obj_get_state(light_icon))
	{
		// 设置成按下状态
		lv_imgbtn_set_state(light_icon, LV_IMGBTN_STATE_CHECKED_RELEASED);
		// todo 发送开关消息
		printf("light off\n");
		// ui_ctrl_color_light_st(idx, false);
	}
	else if (LV_STATE_FOCUSED == lv_obj_get_state(light_icon))
	{
		lv_imgbtn_set_state(light_icon, LV_IMGBTN_STATE_RELEASED);
		printf("light on\n");
		// todo 发送开关消息
		// ui_ctrl_color_light_st(idx, true);
	}
}

/**********************************************************************
 *Functional description:调色温灯
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
void Device_color_light(lv_obj_t *DeviceList, int16_t device_num)
{
	lv_obj_t *color_light = lv_obj_create(DeviceList);
	ui_init_device(color_light);

	LV_IMG_DECLARE(big_device_bg);
	lv_obj_t *bg = lv_img_create(color_light);
	lv_img_set_src(bg, &big_device_bg);

	LV_IMG_DECLARE(light_on);
	LV_IMG_DECLARE(light_off);

	lv_obj_t *light_icon = lv_imgbtn_create(color_light);
	// lv_obj_t *light_icon = lv_img_create(color_light);
	// lv_img_set_src(light_icon, &light_on);
	// lv_img_set_zoom(light_icon, 190);
	// lv_obj_set_pos(light_icon, 31, 68);
	lv_obj_set_size(light_icon, 58, 58);
	lv_obj_set_pos(light_icon, 27, 63);
	lv_imgbtn_set_src(light_icon, LV_IMGBTN_STATE_RELEASED, NULL, &light_on, NULL);
	lv_imgbtn_set_src(light_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &light_off, NULL);
	lv_obj_add_flag(light_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_obj_add_event_cb(light_icon, Color_light_click_event_cb, LV_EVENT_VALUE_CHANGED, color_light);

	lv_obj_t *color_light_name = lv_label_create(color_light);
	lv_label_set_text(color_light_name, device_item[device_num].dev_name);
	lv_obj_set_pos(color_light_name, 50, 40);
	lv_obj_set_size(color_light_name, 100, 25);
	lv_obj_set_style_text_color(color_light_name, lv_color_hex(0xffffff), 0);

	// 调光色温
	lv_obj_t *color_light_color_slider = lv_slider_create(color_light);
	lv_obj_t *color_light_color_value = lv_label_create(color_light_color_slider);
	lv_label_set_text(color_light_color_value, "5000K");
	// todo 格式化显示获取到的百分比
	// lv_label_set_text_fmt(dimming_light_value, "%d%%",lv_slider_get_value(obj));
	lv_obj_set_pos(color_light_color_value, 10, 8);
	lv_obj_set_size(color_light_color_value, 100, 25);
	lv_obj_set_style_text_color(color_light_color_value, lv_color_hex(0x333333), 0);

	lv_obj_set_pos(color_light_color_slider, 170, 29);
	lv_obj_set_size(color_light_color_slider, 240, 32);
	lv_obj_set_style_radius(color_light_color_slider, 4, 0);
	lv_obj_set_style_bg_color(color_light_color_slider, lv_color_hex(0xf89333), 0);
	lv_obj_set_style_bg_grad_color(color_light_color_slider, lv_color_hex(0xfffcfa), 0);
	lv_obj_set_style_bg_grad_dir(color_light_color_slider, LV_GRAD_DIR_HOR, 0);
	lv_obj_set_style_bg_opa(color_light_color_slider, LV_OPA_COVER, 0);

	lv_obj_set_style_radius(color_light_color_slider, 4, LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(color_light_color_slider, lv_color_hex(0xf89333), LV_PART_INDICATOR);
	lv_obj_set_style_bg_grad_color(color_light_color_slider, lv_color_hex(0xfffcfa), LV_PART_INDICATOR);
	lv_obj_set_style_bg_grad_dir(color_light_color_slider, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
	// todo LV_PART_KNOB 待设置图片
	// LV_IMG_DECLARE(light_knob);
	lv_obj_set_style_bg_img_src(color_light_color_slider, &light_knob, LV_PART_KNOB);
	lv_obj_set_style_bg_opa(color_light_color_slider, LV_OPA_0, LV_PART_KNOB);
	lv_obj_set_style_bg_color(color_light_color_slider, lv_color_hex(0xfdeddd), LV_PART_KNOB);
	// 色温范围
	lv_slider_set_range(color_light_color_slider, 3000, 6400);
	lv_obj_add_event_cb(color_light_color_slider, color_light_color_value_change_event_cb, LV_EVENT_VALUE_CHANGED, color_light_color_value);
	lv_obj_add_event_cb(color_light_color_slider, color_light_color_released_event_cb, LV_EVENT_VALUE_CHANGED, color_light);
	// 初始值
	lv_slider_set_value(color_light_color_slider, 5000, LV_ANIM_OFF);

	// 调光亮度
	lv_obj_t *color_light_temp_slider = lv_slider_create(color_light);
	lv_obj_t *color_light_temp_value = lv_label_create(color_light_temp_slider);
	lv_label_set_text(color_light_temp_value, "50%");
	// todo 格式化显示获取到的百分比
	// lv_label_set_text_fmt(dimming_light_value, "%d%%",lv_slider_get_value(obj));
	lv_obj_set_pos(color_light_temp_value, 10, 8);
	lv_obj_set_size(color_light_temp_value, 100, 25);
	lv_obj_set_style_text_color(color_light_temp_value, lv_color_hex(0x333333), 0);

	lv_obj_set_pos(color_light_temp_slider, 170, 87);
	lv_obj_set_size(color_light_temp_slider, 240, 32);
	lv_obj_set_style_radius(color_light_temp_slider, 4, 0);
	lv_obj_set_style_bg_color(color_light_temp_slider, lv_color_hex(0x87878b), 0);
	lv_obj_set_style_bg_opa(color_light_temp_slider, LV_OPA_60, 0);
	lv_obj_set_style_radius(color_light_temp_slider, 4, LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(color_light_temp_slider, lv_color_hex(0xf8dcc4), LV_PART_INDICATOR);
	lv_obj_set_style_bg_opa(color_light_temp_slider, 0, LV_PART_KNOB);
	lv_obj_add_event_cb(color_light_temp_slider, color_light_temp_value_change_event_cb, LV_EVENT_VALUE_CHANGED, color_light_temp_value);
	lv_obj_add_event_cb(color_light_temp_slider, color_light_temp_released_event_cb, LV_EVENT_RELEASED, color_light);
	// 初始值
	lv_slider_set_value(color_light_temp_slider, 50, LV_ANIM_OFF);
}

/**********************************************************************
 *Functional description:窗帘位置改动
 *Input parameter:
 *Return:
 *Other description:滑动时，仅仅作为效果，只有在抬起时，才发送消息
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
static void curtain_position_change_event_cb(lv_event_t *e)
{
	lv_obj_t *curtain = lv_event_get_target(e);
	lv_obj_t *curtain_position = lv_event_get_user_data(e);
	lv_label_set_text_fmt(curtain_position, "%d%%", lv_slider_get_value(curtain));
}

static void curtain_position_released_event_cb(lv_event_t *e)
{
	lv_obj_t *curtain = lv_event_get_target(e);
	lv_obj_t *obj = lv_event_get_user_data(e);
	uint32_t idx = lv_obj_get_index(obj);
	printf("position:%d", lv_slider_get_value(curtain));
	printf("idx:%d; dev_id:%d ; name:%s\n", idx, device_item[idx].dev_id, device_item[idx].dev_name);
	// todo 发送窗帘的具体参数
}

/**********************************************************************
 *Functional description:窗帘设备解析
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
void Device_curtain(lv_obj_t *DeviceList, int16_t device_num)
{
	printf("device_num:%d; dev_id:%d ; name:%s\n", device_num, device_item[device_num].dev_id, device_item[device_num].dev_name);
	lv_obj_t *curtain = lv_obj_create(DeviceList);
	ui_init_device(curtain);

	LV_IMG_DECLARE(big_device_bg);
	lv_obj_t *bg = lv_img_create(curtain);
	lv_img_set_src(bg, &big_device_bg);

	lv_obj_t *curtain_name = lv_label_create(curtain);
	lv_label_set_text(curtain_name, device_item[device_num].dev_name);
	lv_obj_set_pos(curtain_name, 30, 39);
	lv_obj_set_size(curtain_name, 100, 25);
	lv_obj_set_style_text_color(curtain_name, lv_color_hex(0xffffff), 0);

	lv_obj_t *curtain_position = lv_label_create(curtain);
	lv_label_set_text(curtain_position, "78%");
	lv_obj_set_style_text_font(curtain_position, &lv_font_montserrat_30, 0);
	// todo 格式化显示获取到的百分比
	// lv_label_set_text_fmt(curtain_position, "%d%%",lv_slider_get_value(obj));
	lv_obj_set_pos(curtain_position, 30, 78);
	lv_obj_set_size(curtain_position, 100, 25);
	lv_obj_set_style_text_color(curtain_position, lv_color_hex(0xffffff), 0);

	// LV_IMG_DECLARE(curtain_knob);
	// LV_IMG_DECLARE(curtain_slider);
	lv_obj_t *curtain_slider_bg = lv_slider_create(curtain);
	// todo 设置背景 滑动条背景
	lv_obj_set_style_bg_img_src(curtain_slider_bg, &curtain_knob, LV_PART_KNOB);
	lv_obj_set_style_bg_opa(curtain_slider_bg, LV_OPA_0, LV_PART_KNOB);
	lv_obj_set_pos(curtain_slider_bg, 170, 30);
	lv_obj_set_size(curtain_slider_bg, 240, 80);
	lv_obj_set_style_radius(curtain_slider_bg, 6, 0);
	lv_obj_set_style_radius(curtain_slider_bg, 6, LV_PART_INDICATOR);
	lv_obj_set_style_bg_img_src(curtain_slider_bg, &curtain_slider, LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(curtain_slider_bg, lv_color_hex(0x87878b), 0);
	lv_obj_set_style_bg_opa(curtain_slider_bg, LV_OPA_60, 0);

	lv_obj_add_event_cb(curtain_slider_bg, curtain_position_change_event_cb, LV_EVENT_VALUE_CHANGED, curtain_position);
	lv_obj_add_event_cb(curtain_slider_bg, curtain_position_released_event_cb, LV_EVENT_VALUE_CHANGED , curtain);
	// lv_obj_add_event_cb(curtain_slider_bg, curtain_position_released_event_cb, LV_EVENT_CLICKED, curtain);
	// 初始值
	lv_slider_set_value(curtain_slider_bg, 78, LV_ANIM_OFF);
}

static void DeviceList_gesture_event_handler(lv_event_t *e)
{
	printf("DeviceList_gesture_event_handler\n");
}

static void _lv_show_time(lv_ui *ui)
{
	// 显示时间和日期，星期
	lv_obj_t *time_cont = lv_obj_create(ui->MainPage);
	lv_obj_set_pos(time_cont, 20, 40);
	lv_obj_set_size(time_cont, 300, 180);
	lv_obj_clear_flag(time_cont, LV_OBJ_FLAG_SCROLLABLE);
	ui_init_cont(time_cont, LV_OPA_TRANSP);

	lv_obj_t *time_lable = lv_label_create(time_cont);
	lv_obj_set_pos(time_lable, 10, 10);
	lv_obj_set_size(time_lable, 300, 110);
	lv_obj_set_style_opa(time_lable, LV_OPA_COVER, 0);
	lv_obj_set_style_text_color(time_lable, lv_color_hex(0xffffff), 0);
	lv_obj_set_scrollbar_mode(time_lable, LV_SCROLLBAR_MODE_OFF);

	LV_FONT_DECLARE(num_108);
	lv_obj_set_style_text_font(time_lable, &num_108, 0);
	lv_label_set_text(time_lable, "15:56");

	// todo 获取时间/日期星期
	lv_obj_t *day_lable = lv_label_create(time_cont);
	lv_obj_set_pos(day_lable, 10, 120);
	lv_obj_set_size(day_lable, 300, 110);
	lv_obj_set_style_opa(day_lable, LV_OPA_COVER, 0);
	lv_obj_set_style_text_color(day_lable, lv_color_hex(0xffffff), 0);
	lv_obj_set_scrollbar_mode(day_lable, LV_SCROLLBAR_MODE_OFF);
	LV_FONT_DECLARE(mainpage_36);
	lv_obj_set_style_text_font(day_lable, &mainpage_36, 0);
	lv_label_set_text(day_lable, "4月11日   星期二");
}

static void _lv_show_weather(lv_ui *ui)
{
	// todo 获取天气，显示天气logo
	lv_obj_t *weather_cont = lv_obj_create(ui->MainPage);
	lv_obj_set_pos(weather_cont, 10, 217);
	lv_obj_set_size(weather_cont, 160, 55);
	ui_init_cont(weather_cont, LV_OPA_TRANSP);

	// todo 天气图片在确定天气后再加载图片
	// LV_IMG_DECLARE(w_sunny);
	lv_obj_t *icon_sunny = lv_img_create(weather_cont);
	lv_img_set_src(icon_sunny, &w_sunny);
	lv_obj_set_pos(icon_sunny, 20, 0);
	lv_obj_set_style_opa(icon_sunny, LV_OPA_COVER, 0);

	lv_obj_t *weather_lable = lv_label_create(weather_cont);
	lv_obj_set_pos(weather_lable, 65, 0);
	lv_obj_set_size(weather_lable, 120, 55);
	lv_obj_set_style_opa(weather_lable, LV_OPA_COVER, 0);
	lv_obj_set_style_text_color(weather_lable, lv_color_hex(0xffffff), 0);
	lv_obj_set_scrollbar_mode(weather_lable, LV_SCROLLBAR_MODE_OFF);
	LV_FONT_DECLARE(mainpage_36);
	lv_obj_set_style_text_font(weather_lable, &mainpage_36, 0);
	lv_label_set_text(weather_lable, "19℃");
}

static void _lv_show_btn(lv_ui *ui)
{
	lv_obj_t *btn_cont = lv_obj_create(ui->MainPage);
	lv_obj_set_pos(btn_cont, 20, 320);
	lv_obj_set_size(btn_cont, 460, 160);
	ui_init_cont(btn_cont, LV_OPA_TRANSP);
	lv_obj_set_flex_flow(btn_cont, LV_FLEX_FLOW_ROW_WRAP);
	lv_obj_set_layout(btn_cont, LV_LAYOUT_FLEX);

	// todo 普通灯和情景可以使用同个接口，调光灯需要再写一个
	Device_switch(btn_cont, 1);
	Device_switch(btn_cont, 1);
}

/**********************************************************************
*Functional description:创建绘制主界面
*Input parameter:
*Return:
*Other description:1.下拉进入APP应用程序
					2.主页天气，时间
					3.主页显示两个情景
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-05-05           V1.0           RunningCode             Create
***********************************************************************/
static void _lv_creat_main_page(lv_ui *ui)
{
	// main page init
	ui->MainPage = lv_tabview_add_tab(ui->tabview, "");
	lv_obj_set_pos(ui->MainPage, 0, 0);
	lv_obj_set_size(ui->MainPage, LCD_WIDTH, LCD_HEIGHT);
	lv_obj_set_style_pad_all(ui->MainPage, 0, 0);
	lv_obj_clear_flag(ui->MainPage, LV_OBJ_FLAG_SCROLLABLE); // 禁止界面左右滑动
	lv_obj_clear_flag(ui->MainPage, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
	lv_obj_set_scrollbar_mode(ui->MainPage, LV_SCROLLBAR_MODE_OFF);

	// 下拉有效区域
	lv_obj_t *cont;
	cont = lv_obj_create(ui->MainPage);
	lv_obj_set_pos(cont, 0, 0);
	lv_obj_set_size(cont, LCD_WIDTH, 20);
	lv_obj_set_style_pad_all(cont, 0, 0);
	lv_obj_set_style_opa(cont, LV_OPA_TRANSP, 0);
	lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLL_CHAIN);
	lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

	// 显示时间
	_lv_show_time(ui);

	// 显示天气
	_lv_show_weather(ui);

	// todo 获取主界面两个设备
	_lv_show_btn(ui);
}

static void _test_init_device_list(lv_ui *ui)
{
	int16_t i;
	for (i = 0; i < ARRAY_SIZE(device_item); i++)
	{

		switch (device_item[i].dev_type)
		{
		case 1:
			// todo 绘制开关
			Device_switch(ui->DeviceList, i);
			break;
		case 2:
			// todo 绘制窗帘
			Device_curtain(ui->DeviceList, i);
			break;
		case 3:
			// todo 绘制情景
			Device_scene(ui->DeviceList, i);
			break;
		case 4:
			// todo 绘制调光灯 dimming light
			Device_dimming_light(ui->DeviceList, i);
			break;
		case 5:
			// todo 绘制色温灯 color temp light
			Device_color_light(ui->DeviceList, i);
			break;

		default:
			break;
		}
	}
}

/**********************************************************************
 *Functional description:创建设备列表界面
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_creat_device_page(lv_ui *ui)
{
	ui->DevicePage = lv_tabview_add_tab(ui->tabview, "");
	lv_obj_set_pos(ui->DevicePage, 0, 0);
	lv_obj_set_size(ui->DevicePage, LCD_WIDTH, LCD_HEIGHT);
	lv_obj_set_style_pad_top(ui->DevicePage, 0, 0);
	lv_obj_set_style_pad_bottom(ui->DevicePage, 0, 0);
	lv_obj_set_style_pad_right(ui->DevicePage, 0, 0);
	lv_obj_set_style_pad_left(ui->DevicePage, 20, 0);
	lv_obj_set_scrollbar_mode(ui->DevicePage, LV_SCROLLBAR_MODE_OFF);
	lv_obj_clear_flag(ui->DevicePage, LV_OBJ_FLAG_SCROLLABLE);

	// 下拉有效区域
	lv_obj_t *cont;
	cont = lv_obj_create(ui->DevicePage);
	lv_obj_set_pos(cont, 0, 0);
	lv_obj_set_size(cont, 450, 20);
	lv_obj_set_style_pad_all(cont, 0, 0);
	lv_obj_set_style_opa(cont, LV_OPA_TRANSP, 0);
	lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLL_CHAIN);
	lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

	// 创建设备列表
	ui->DeviceList = lv_obj_create(ui->DevicePage);
	lv_obj_set_pos(ui->DeviceList, 0, 20);
	lv_obj_set_size(ui->DeviceList, LCD_WIDTH, 460);
	lv_obj_set_flex_flow(ui->DeviceList, LV_FLEX_FLOW_ROW_WRAP);
	// lv_obj_set_flex_flow(ui->DeviceList ,  LV_FLEX_FLOW_COLUMN_WRAP_REVERSE);
    // lv_obj_set_scroll_snap_x(ui->DeviceList , LV_SCROLL_SNAP_CENTER);
	lv_obj_set_layout(ui->DeviceList, LV_LAYOUT_FLEX);
	lv_obj_set_style_bg_opa(ui->DeviceList, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->DeviceList, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_style_border_width(ui->DeviceList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->DeviceList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->DeviceList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// 设备列表初始化
	_test_init_device_list(ui);
}

/**********************************************************************
 *Functional description:创建主页和设备页面
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_create_HomePage_tabview(lv_ui *ui)
{
	ui->tabview = lv_tabview_create(ui->HomePage, LV_DIR_LEFT, 0); // 表头的高度
	lv_obj_set_style_bg_opa(ui->tabview, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->tabview, 0, 0);
	lv_obj_set_size(ui->tabview, LCD_WIDTH, LCD_HEIGHT); // 宏定义屏幕宽度，高度
	lv_obj_set_scrollbar_mode(ui->tabview, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_style_pad_all(ui->tabview, 0, 0);

	// 创建主页
	_lv_creat_main_page(ui);
	// 创建设备页面
	_lv_creat_device_page(ui);
}

// 下拉进APP
static void anim_y_cb(void *var, int32_t v)
{
	lv_obj_set_y(var, v);
}

/**********************************************************************
 *Functional description:监听手势函数
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-24           V1.0           RunningCode             Create
 ***********************************************************************/
static void HomePage_gesture_event_handler(lv_event_t *e)
{
	printf("HomePage_gesture_event_handler\n");
	lv_indev_t *indev = lv_indev_get_act();
	lv_dir_t dir = lv_indev_get_gesture_dir(indev);
	lv_ui *ui = lv_event_get_user_data(e);

	if (dir == LV_DIR_BOTTOM) // 从上面往下面滑动
	{
		// load app page
		printf("LV_DIR_BOTTOM\n");
		// 启动动画
		lv_anim_t a;
		lv_anim_init(&a); // 初始化一个动画变量
		lv_anim_set_var(&a, ui->Apps_entry);
		lv_anim_set_values(&a, -LCD_WIDTH, 0);
		lv_anim_set_exec_cb(&a, anim_y_cb);
		lv_anim_set_path_cb(&a, lv_anim_path_linear);
		lv_anim_start(&a);
	}
	else if (dir == LV_DIR_TOP) // 从下面往上滑动
	{
		printf("LV_DIR_TOP\n");
	}
}

/**********************************************************************
 *Functional description:删除APP入口画布
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
static void delete_event_handler(lv_event_t *e)
{
	printf("delete_event_handler");
	lv_ui *ui = lv_event_get_user_data(e);

	lv_anim_t a;
	lv_anim_init(&a); // 初始化一个动画变量
	lv_anim_set_var(&a, ui->Apps_entry);
	lv_anim_set_values(&a, 0, -LCD_HEIGHT);
	lv_anim_set_exec_cb(&a, anim_y_cb);
	lv_anim_set_path_cb(&a, lv_anim_path_linear);
	lv_anim_start(&a);
}

static void add_icon_event_handler(lv_event_t *e)
{
	printf("goto add\n");
	lv_ui *ui = lv_event_get_user_data(e);

	lv_obj_t *act_scr = lv_scr_act();
	lv_disp_t *d = lv_obj_get_disp(act_scr);
	if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
	{
		lv_obj_clean(act_scr);
		if (ui->AddDevice_del == true)
			setup_scr_AddDevice(ui);
		lv_scr_load_anim(ui->AddDevice, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
		ui->HomePage_del = true;
	}
}

static void set_icon_event_handler(lv_event_t *e)
{
	printf("goto set\n");
	lv_ui *ui = lv_event_get_user_data(e);
	lv_obj_t *act_scr = lv_scr_act();
	lv_disp_t *d = lv_obj_get_disp(act_scr);
	if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
	{
		lv_obj_clean(act_scr);
		if (ui->Setting_del == true)
			setup_scr_Setting(ui);
		lv_scr_load_anim(ui->Setting, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
		ui->HomePage_del = true;
	}
}

// todo 是否做成点击之后再进入
/**********************************************************************
 *Functional description:APP 入口
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-05           V1.0           RunningCode             Create
 ***********************************************************************/
static void _lv_create_Apps_entry(lv_ui *ui)
{
	ui->Apps_entry = lv_btn_create(ui->HomePage);
	lv_obj_set_pos(ui->Apps_entry, 0, -LCD_HEIGHT);
	lv_obj_set_size(ui->Apps_entry, LCD_WIDTH, LCD_HEIGHT);
	ui_init_cont(ui->Apps_entry, LV_OPA_TRANSP);
	lv_obj_set_style_shadow_width(ui->Apps_entry, 0, 0);
	lv_obj_add_event_cb(ui->Apps_entry, delete_event_handler, LV_EVENT_CLICKED, ui);

	// 显示APP区域
	lv_obj_t *cont = lv_obj_create(ui->Apps_entry);
	// lv_obj_remove_style_all(cont);
	lv_obj_set_pos(cont, 0, 0);
	lv_obj_set_size(cont, LCD_WIDTH, 150);
	lv_obj_set_style_bg_color(cont, lv_color_hex(0x1d1d1d), 0);
	ui_init_cont(cont, LV_OPA_COVER);

	// 添加APP logo 和 event
	LV_IMG_DECLARE(ic_add);
	LV_IMG_DECLARE(ic_set);
	lv_obj_t *add_icon = lv_img_create(cont);
	lv_img_set_src(add_icon, &ic_add);
	lv_obj_set_pos(add_icon, 108, 28);
	lv_obj_set_size(add_icon, 64, 64);
	lv_obj_add_flag(add_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(add_icon, add_icon_event_handler, LV_EVENT_CLICKED, ui);

	lv_obj_t *set_icon = lv_img_create(cont);
	lv_img_set_src(set_icon, &ic_set);
	lv_obj_set_pos(set_icon, 308, 28);
	lv_obj_set_size(set_icon, 64, 64);
	lv_obj_add_flag(set_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(set_icon, set_icon_event_handler, LV_EVENT_CLICKED, ui);

	lv_obj_t *add_lable = lv_label_create(cont);
	lv_obj_set_style_text_font(add_lable, &HanSansCN_20, 0);
	lv_label_set_text(add_lable, "添加");
	lv_obj_set_pos(add_lable, 120, 104);
	lv_obj_set_size(add_lable, 100, 25);
	lv_obj_set_style_text_color(add_lable, lv_color_hex(0xffffff), 0);

	lv_obj_t *set_lable = lv_label_create(cont);
	lv_obj_set_style_text_font(set_lable, &HanSansCN_20, 0);
	lv_label_set_text(set_lable, "设置");
	lv_obj_set_pos(set_lable, 320, 104);
	lv_obj_set_size(set_lable, 100, 25);
	lv_obj_set_style_text_color(set_lable, lv_color_hex(0xffffff), 0);
}

/**********************************************************************
 *Functional description:主界面函数
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-05-04           V1.0           RunningCode             Create
 ***********************************************************************/
void setup_scr_HomePage(lv_ui *ui)
{
	// Write codes HomePage 主界面样式
	ui->HomePage = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->HomePage, LV_SCROLLBAR_MODE_OFF);
	// Write style state: LV_STATE_DEFAULT for style_homepage_main_main_default
	static lv_style_t style_homepage_main_main_default;
	if (style_homepage_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_main_main_default);
	else
		lv_style_init(&style_homepage_main_main_default);
	// lv_style_set_bg_opa(&style_homepage_main_main_default, 255);
	lv_style_set_bg_img_src(&style_homepage_main_main_default, &bg);
	lv_obj_add_style(ui->HomePage, &style_homepage_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_event_cb(ui->HomePage, HomePage_gesture_event_handler, LV_EVENT_GESTURE, ui); // 在此处监听，处理最上层的滑动

	// 创建一个选项卡控件
	_lv_create_HomePage_tabview(ui);

	// 创建一个APP入口
	_lv_create_Apps_entry(ui); // 后创建的至于上层
}