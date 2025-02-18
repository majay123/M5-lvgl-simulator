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
 * @Date         : 2024-03-04 15:17:15
 * @LastEditors  : MCD
 * @LastEditTime : 2025-02-18 14:59:42
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/setup_scr_Locattion.c
 * @Description  : 
 * 
 * ******************************************
 */
#include "gui_guider.h"
#include "lvgl.h"
#include "ui_common.h"
#include <stdio.h>


extern const char *prov_list[];
extern st_location *all_location_data[];
static uint8_t prov_index = 0;
static uint8_t city_index = 0;

const char *pro_roller = "北京市\n天津市\n河北省\n山西省\n内蒙古自治区\n辽宁省\n吉林省\n黑龙江省\n上海市\n"
                         "江苏省\n浙江省\n安徽省\n福建省\n江西省\n山东省\n河南省\n湖北省\n湖南省\n"
                         "广东省\n广西壮族自治区\n海南省\n重庆市\n四川省\n贵州省\n云南省\n西藏自治区\n陕西省\n甘肃省\n"
                         "青海省\n宁夏回族自治区\n新疆维吾尔自治区\n台湾省\n香港\n澳门";

void lv_get_select_location(lv_ui *ui)
{
    ui->province = all_location_data[prov_index]->prov;
    ui->city = all_location_data[prov_index]->cities[city_index]->name;
    // lv_get_select_location(ui);
    char buf[128] = {0};
    lv_snprintf(buf, sizeof(buf), "%s, %s", ui->province, ui->city);
    lv_label_set_text(ui->location_lable, buf);
}

static void _lv_location_outside_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e); 
    lv_obj_t *obj = lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_del(obj);
        lv_obj_remove_event_cb(lv_layer_top(), _lv_location_outside_event_cb);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
        // lv_get_select_location(&guider_ui);
        // todo 发送位置给网关
        LV_LOG_USER("prov: %d, city: %d\n", prov_index, city_index);
    }
}


static void _lv_mask_event_cb1(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *obj_r2 = lv_event_get_user_data(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

   if (code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        prov_index = lv_roller_get_selected(obj);
        LV_LOG_USER("Selected prov: %s, cnt: %d\n", buf, prov_index);

        if (prov_index > 33)
            lv_roller_set_options(obj_r2,  " ", LV_ROLLER_MODE_NORMAL);
        else {
            lv_roller_set_options(obj_r2, prov_list[prov_index], LV_ROLLER_MODE_NORMAL);
            city_index = 0;
            lv_get_select_location(&guider_ui);
        }
    }
    else if (code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    }
    else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t *font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t *fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);
    }
    else if (code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t *fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}

static void _lv_mask_event_cb2(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    static int16_t mask_top_id1 = -1;
    static int16_t mask_bottom_id1 = -1;

    if (code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        city_index = lv_roller_get_selected(obj);
        local_city_t *city_info = all_location_data[prov_index]->cities[city_index];
        LV_LOG_USER("prov: %s, city: %s, code: %s, lat: %s, lng: %s\n",all_location_data[prov_index]->prov, city_info->name, city_info->code, city_info->lat, city_info->lng);
        lv_get_select_location(&guider_ui);
    }
    else if (code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    }
    else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t *font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t *fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id1 = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id1 = lv_draw_mask_add(fade_mask_bottom, NULL);
    }
    else if (code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t *fade_mask_top = lv_draw_mask_remove_id(mask_top_id1);
        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id1);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id1 = -1;
        mask_bottom_id1 = -1;
    }
}

void lv_setting_location_select(lv_ui *ui)
{
    lv_obj_t *ui_Panel1;
    lv_obj_t *ui_Label1;
    lv_obj_t *roller1;
    lv_obj_t *roller2;

    prov_index = 0;
    city_index = 0;

    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    ui_Panel1 = lv_obj_create(lv_layer_top());

    lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_50, 0);
    lv_obj_set_style_bg_color(lv_layer_top(), lv_palette_main(LV_PALETTE_GREY), 0);

    lv_obj_add_event_cb(lv_layer_top(), _lv_location_outside_event_cb, LV_EVENT_CLICKED, (void *)ui_Panel1); 

    lv_obj_set_width(ui_Panel1, 318);
    lv_obj_set_height(ui_Panel1, 276);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_x(ui_Label1, -118);
    lv_obj_set_y(ui_Label1, -1);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "定位");
    lv_obj_add_flag(ui_Label1, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(ui_Label1, event_handler, LV_OBJ_FLAG_CLICKABLE, (void *)ui_Panel1);
#if LV_USE_MY_FONT
    lv_obj_set_style_text_font(ui_Label1, my_font, 0);
#else
    lv_obj_set_style_text_font(ui_Label1, &HanSansCN_20, 0);
#endif

    roller1 = lv_roller_create(ui_Panel1);
    roller2 = lv_roller_create(ui_Panel1);

    lv_obj_set_height(roller1, 135);
    lv_obj_set_width(roller1, 100);  /// 1
    lv_obj_set_x(roller1, -19);
    lv_obj_set_y(roller1, -4);
    lv_obj_set_align(roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_border_opa(roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(roller1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(roller1, lv_color_hex(0xCBC9C9), LV_STATE_DEFAULT | LV_PART_SELECTED);
    lv_obj_set_style_text_color(roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT | LV_PART_SELECTED);
    lv_obj_set_style_bg_opa(roller1, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_text_font(roller1, my_font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(roller1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_set_height(roller2, 135);
    lv_obj_set_width(roller2, 100);  /// 1
    lv_obj_set_x(roller2, 93);
    lv_obj_set_y(roller2, -4);
    lv_obj_set_align(roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_border_opa(roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(roller2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(roller2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(roller2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT | LV_PART_SELECTED);
    lv_obj_set_style_bg_opa(roller2, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_text_font(roller2, my_font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(roller2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_roller_set_options(roller1,
                          pro_roller,
                          LV_ROLLER_MODE_NORMAL);
    lv_roller_set_options(roller2,
                          prov_list[0],
                          LV_ROLLER_MODE_NORMAL);

    lv_roller_set_visible_row_count(roller1, 5);
    lv_roller_set_visible_row_count(roller2, 5);

    lv_obj_add_event_cb(roller1, _lv_mask_event_cb1, LV_EVENT_ALL, (void *)roller2);
    lv_obj_add_event_cb(roller2, _lv_mask_event_cb2, LV_EVENT_ALL, NULL);
}