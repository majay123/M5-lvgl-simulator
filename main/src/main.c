
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */

#include <stdlib.h>
#include <unistd.h>

#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/

#include "SDL2/SDL.h"
#include "demos/lv_demos.h"
#include "examples/lv_examples.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lvgl/lvgl.h"
#include "testapp/gui_guider.h"
#include "ui/ui.h"

lv_ui guider_ui;

static void hal_init(void);

static int tick_thread(void *data);

static void _imgbtn1_event_cb(lv_event_t *e)
{
    printf("_imgbtn1_event_cb\n");
}

void lv_ex_imgbtn_1(void)
{
    LV_IMG_DECLARE(light_on);
    LV_IMG_DECLARE(light_off);

    /*Darken the button when pressed*/
    static lv_style_t style;

    if(style.prop_cnt > 1)
        lv_style_reset(&style);
    else
        lv_style_init(&style);
    lv_style_set_img_recolor_opa(&style, LV_OPA_30);
    lv_style_set_img_recolor(&style, lv_color_black());

    /*Create an Image button*/
    lv_obj_t *imgbtn1 = lv_imgbtn_create(lv_scr_act());
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_RELEASED, NULL, &light_off, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_PRESSED, NULL, &light_off, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &light_on, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &light_on, NULL);
    lv_obj_set_size(imgbtn1, 58, 58);
    lv_obj_set_pos(imgbtn1, 0, 0);
    // lv_obj_set_y(imgbtn1, 0);
    lv_obj_set_align(imgbtn1, LV_ALIGN_CENTER);
    // lv_imgbtn_set_checkable(imgbtn1, true);
    lv_obj_add_style(imgbtn1, &style, LV_STATE_PRESSED);
    // lv_obj_align(imgbtn1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag( imgbtn1, LV_OBJ_FLAG_CHECKABLE );   /// Flags
    lv_obj_clear_flag( imgbtn1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
    lv_obj_set_scrollbar_mode(imgbtn1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_event_cb(imgbtn1, _imgbtn1_event_cb, LV_EVENT_CLICKED, imgbtn1);

    /*Create a label on the Image button*/
    // lv_obj_t * label = lv_label_create(imgbtn1);
    // lv_label_set_text(label, "Button");
}

int main(int argc, char **argv)
{
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();
    memset(&guider_ui, 0, sizeof(guider_ui));
    setup_ui(&guider_ui);
    // lv_ex_imgbtn_1();
    //init_ui();
    //lv_demo_benchmark();
    //lv_demo_keypad_encoder();
    // lv_demo_stress();
    // lv_demo_widgets();
    //   lv_demo_music();
    // lv_example_btn_1();
    // lv_example_imgbtn_1();
    //    lv_example_slider_3();
    // lv_example_menu_5();
    //  lv_example_qrcode_1();
    //   lv_example_anim_2();
    // lv_example_img_3();
    // lv_example_keyboard_1();
    // lv_example_checkbox_1();
    // lv_example_msgbox_1();

    while (1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        //lv_timer_handler();
        usleep(lv_timer_handler() * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
    /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();
    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
     * how much time were elapsed Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);

    /*Create a display buffer*/
    static lv_disp_draw_buf_t disp_buf1;
    static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
    static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
    lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

    /*Create a display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    disp_drv.hor_res = MONITOR_HOR_RES;
    disp_drv.ver_res = MONITOR_VER_RES;
    disp_drv.antialiasing = 1;

    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    lv_theme_t *th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, th);

    lv_group_t *g = lv_group_create();
    lv_group_set_default(g);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = mouse_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    keyboard_init();
    static lv_indev_drv_t indev_drv_2;
    lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
    indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv_2.read_cb = keyboard_read;
    lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
    lv_indev_set_group(kb_indev, g);
    mousewheel_init();
    static lv_indev_drv_t indev_drv_3;
    lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
    indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
    indev_drv_3.read_cb = mousewheel_read;

    lv_indev_t *enc_indev = lv_indev_drv_register(&indev_drv_3);
    lv_indev_set_group(enc_indev, g);

    /*Set a cursor for the mouse*/
    LV_IMG_DECLARE(mouse_cursor_icon);                  /*Declare the image file.*/
    lv_obj_t *cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);     /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);       /*Connect the image  object to the driver*/
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
    (void)data;

    while (1) {
        SDL_Delay(5);
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}
