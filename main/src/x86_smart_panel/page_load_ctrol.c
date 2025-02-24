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
 * @Date         : 2024-04-01 16:45:32
 * @LastEditors  : MCD
 * @LastEditTime : 2024-04-02 10:09:34
 * @FilePath     : /M5-lvgl-simulator/main/src/x86_smart_panel/page_load_ctrol.c
 * @Description  : 
 * 
 * ******************************************
 */

#include "page_load_ctrol.h"
#include "./common/ui_helpers.h"
#include "lvgl.h"
#include "ui.h"

//左右滑动的窗口管理
lv_obj_t *ui_tabview_screen;
lv_obj_t *ui_tabview;
lv_obj_t *ui_tab1;
lv_obj_t *ui_tab2;
lv_obj_t *ui_tab3;
lv_obj_t *ui_tab4;
lv_obj_t *ui_tab5;
lv_obj_t *ui_tab6;
int g_annim_flag = 0;

void ui_event_UiPage6_screen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        lv_scr_load_anim(ui_tabview_screen, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, true);
    }
}

void ui_event_tabview_screen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        if (1 == g_annim_flag) {
            printf("[%s][%d] del annim when page ver change\r\n", __FUNCTION__, __LINE__);
            lv_anim_del(NULL, (lv_anim_exec_xcb_t)_ui_anim_callback_set_x_new);
            g_annim_flag = 0;
        }
        ui_UiPage6_screen_init();
        lv_scr_load_anim(ui_UiPage6, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0, false);
    }
    if (event_code == LV_EVENT_SCREEN_LOADED) {
        printf("[%s][%d] play annim when page load\r\n", __FUNCTION__, __LINE__);
        move_x_add_Animation(ui_cloudSmall1, 0);
        mov_x_sub_Animation(ui_cloudSmall2, 0);
        mov_x_sub_Animation(ui_cloudSmall1, 2000);
        move_x_add_Animation(ui_cloudSmall2, 2000);
        g_annim_flag = 1;
    }
}

static void get_tab_act_index_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    int tab_id = 0;

    if (code == LV_EVENT_VALUE_CHANGED) {
        if (obj) {
            tab_id = lv_tabview_get_tab_act(obj);
            printf("tab_id:%d\r\n", tab_id);

            if (tab_id != 0) {
                printf("[%s][%d] del annim when page hor change\r\n", __FUNCTION__, __LINE__);
                lv_anim_del(NULL, (lv_anim_exec_xcb_t)_ui_anim_callback_set_x_new);
                g_annim_flag = 0;
            }
            else {
                if (0 == g_annim_flag) {
                    printf("[%s][%d] play annim when page hor change to 1\r\n", __FUNCTION__, __LINE__);
                    g_annim_flag = 1;
                    lv_obj_set_pos(ui_cloudSmall1, 246, 29);
                    lv_obj_set_pos(ui_cloudSmall2, 396, 80);
                    move_x_add_Animation(ui_cloudSmall1, 0);
                    mov_x_sub_Animation(ui_cloudSmall2, 0);
                    mov_x_sub_Animation(ui_cloudSmall1, 2000);
                    move_x_add_Animation(ui_cloudSmall2, 2000);
                }
            }
        }
    }
}

static void scroll_begin_event(lv_event_t *e)
{
    lv_obj_t *cont = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    lv_obj_t *tv = lv_obj_get_parent(cont);

    if (lv_event_get_code(e) == LV_EVENT_SCROLL_END) {
        lv_tabview_t *tabview = (lv_tabview_t *)tv;

        lv_coord_t s = lv_obj_get_scroll_x(cont);

        lv_point_t p;
        lv_obj_get_scroll_end(cont, &p);

        lv_coord_t w = lv_obj_get_content_width(cont);
        lv_coord_t t;

        if (lv_obj_get_style_base_dir(tv, LV_PART_MAIN) == LV_BASE_DIR_RTL)
            t = -(p.x - w / 2) / w;
        else
            t = (p.x + w / 2) / w;

        if (s < 0)
            t = tabview->tab_cnt - 1;
        else if ((t == (tabview->tab_cnt - 1)) && (s > p.x))
            t = 0;

        bool new_tab = false;
        if (t != lv_tabview_get_tab_act(tv))
            new_tab = true;
        lv_tabview_set_act(tv, t, LV_ANIM_ON);

        printf("scroll g_tab_act:%d, new_tab:%d\r\n", lv_tabview_get_tab_act(ui_tabview), new_tab);
    }
}

void hor_page_load_main(void)
{
    ui_tabview_screen = lv_obj_create(NULL);
    lv_obj_add_event_cb(ui_tabview_screen, ui_event_tabview_screen, LV_EVENT_ALL, NULL);

    ui_tabview = lv_tabview_create(ui_tabview_screen, LV_DIR_TOP, 0);
    lv_obj_set_style_bg_color(ui_tabview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_tabview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_add_event_cb(lv_tabview_get_content(ui_tabview), scroll_begin_event, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_tabview, get_tab_act_index_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_scroll_dir(ui_tabview, LV_DIR_HOR);
    // lv_obj_set_scroll_direction(ui_tabview, LV_SCROLL_DIR_HORIZONTAL);
    ui_tab1 = lv_tabview_add_tab(ui_tabview, "Tab 1");
    ui_tab2 = lv_tabview_add_tab(ui_tabview, "Tab 2");
    ui_tab3 = lv_tabview_add_tab(ui_tabview, "Tab 3");
    
    ui_tab4 = lv_tabview_add_tab(ui_tabview, "Tab 4");
    ui_tab5 = lv_tabview_add_tab(ui_tabview, "Tab 5");
    ui_tab6 = lv_tabview_add_tab(ui_tabview, "Tab 6");

    lv_obj_set_style_pad_all(ui_tab1, 0, 0);
    lv_obj_set_style_radius(ui_tab1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_UiPage1_screen_init(ui_tab1);

    lv_obj_set_style_pad_all(ui_tab2, 0, 0);
    lv_obj_set_style_border_width(ui_tab2, 0, 0);
    ui_UiPage2_screen_init(ui_tab2);

    lv_obj_set_style_pad_all(ui_tab3, 0, 0);
    lv_obj_set_style_border_width(ui_tab3, 0, 0);
    ui_UiArcPage_screen_init(ui_tab3);
    

    
    lv_obj_set_style_pad_all(ui_tab4, 0, 0);
    lv_obj_set_style_border_width(ui_tab4, 0, 0);
    ui_UiPage3_screen_init(ui_tab4);
    
    lv_obj_set_style_pad_all(ui_tab5, 0, 0);
    lv_obj_set_style_border_width(ui_tab5, 0, 0);
    ui_UiPage4_screen_init(ui_tab5);
    
    lv_obj_set_style_pad_all(ui_tab6, 0, 0);
    lv_obj_set_style_border_width(ui_tab6, 0, 0);
    ui_UiPage5_screen_init(ui_tab6);

    lv_disp_load_scr(ui_tabview_screen);
}

void ui_tabview_set(uint32_t id)
{
    lv_tabview_set_act(ui_tabview, id, LV_ANIM_ON);
}
