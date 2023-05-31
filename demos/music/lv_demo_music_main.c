/**
 * @file lv_demo_music_main.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_music_main.h"
#if LV_USE_DEMO_MUSIC

#include "lv_demo_music_list.h"
#include "assets/spectrum_1.h"
#include "assets/spectrum_2.h"
#include "assets/spectrum_3.h"

/*********************
 *      DEFINES
 *********************/
#define ACTIVE_TRACK_CNT    3
#define INTRO_TIME          2000
#define BAR_COLOR1          lv_color_hex(0xe9dbfc)
#define BAR_COLOR2          lv_color_hex(0x6f8af6)
#define BAR_COLOR3          lv_color_hex(0xffffff)
#if LV_DEMO_MUSIC_LARGE
    #define BAR_COLOR1_STOP     160
    #define BAR_COLOR2_STOP     200
#else
    #define BAR_COLOR1_STOP     80
    #define BAR_COLOR2_STOP     100
#endif
#define BAR_COLOR3_STOP     (2 * LV_HOR_RES / 3)
#define BAR_CNT             20
#define DEG_STEP            (180/BAR_CNT)
#define BAND_CNT            4
#define BAR_PER_BAND_CNT    (BAR_CNT / BAND_CNT)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_obj_t * create_cont(lv_obj_t * parent);
static void create_wave_images(lv_obj_t * parent);
static lv_obj_t * create_title_box(lv_obj_t * parent);
static lv_obj_t * create_icon_box(lv_obj_t * parent);
static lv_obj_t * create_spectrum_obj(lv_obj_t * parent);
static lv_obj_t * create_ctrl_box(lv_obj_t * parent);
static lv_obj_t * create_handle(lv_obj_t * parent);

static void spectrum_anim_cb(void * a, int32_t v);
static void start_anim_cb(void * a, int32_t v);
static void spectrum_draw_event_cb(lv_event_t * e);
static lv_obj_t * album_img_create(lv_obj_t * parent);
static void album_gesture_event_cb(lv_event_t * e);
static void play_event_click_cb(lv_event_t * e);
static void prev_click_event_cb(lv_event_t * e);
static void next_click_event_cb(lv_event_t * e);
static void timer_cb(lv_timer_t * t);
static void track_load(uint32_t id);
static void stop_start_anim(lv_timer_t * t);
static void spectrum_end_cb(lv_anim_t * a);
static int32_t get_cos(int32_t deg, int32_t a);
static int32_t get_sin(int32_t deg, int32_t a);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * main_cont; //主界面容器
static lv_obj_t * spectrum_obj;
static lv_obj_t * title_label;
static lv_obj_t * artist_label;
static lv_obj_t * genre_label;
static lv_obj_t * time_obj;
static lv_obj_t * album_img_obj;
static lv_obj_t * slider_obj;
static uint32_t spectrum_i = 0;
static uint32_t spectrum_i_pause = 0;
static uint32_t bar_ofs = 0;
static uint32_t spectrum_lane_ofs_start = 0;
static uint32_t bar_rot = 0;
static uint32_t time_act;
static lv_timer_t  * sec_counter_timer; //lvgl定时器：刷新进度条和时间
static const lv_font_t * font_small;
static const lv_font_t * font_large;
static uint32_t track_id; //专辑图片
static bool playing; //播放状态
static bool start_anim;
static lv_coord_t start_anim_values[40];
static lv_obj_t * play_obj;
static const uint16_t (* spectrum)[4];
static uint32_t spectrum_len;
static const uint16_t rnd_array[30] = {994, 285, 553, 11, 792, 707, 966, 641, 852, 827, 44, 352, 146, 581, 490, 80, 729, 58, 695, 940, 724, 561, 124, 653, 27, 292, 557, 506, 382, 199};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*
 * Callback adapter function to convert parameter types to avoid compile-time
 * warning.
 */
static void _img_set_zoom_anim_cb(void * obj, int32_t zoom)
{
    lv_img_set_zoom((lv_obj_t *)obj, (uint16_t)zoom);
}

/*
 * Callback adapter function to convert parameter types to avoid compile-time
 * warning.
 */
static void _obj_set_x_anim_cb(void * obj, int32_t x)
{
    lv_obj_set_x((lv_obj_t *)obj, (lv_coord_t)x);
}

/**********************************************************************
*Functional description:demo 主界面
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-13           V1.0           RunningCode             Create
***********************************************************************/
lv_obj_t * _lv_demo_music_main_create(lv_obj_t * parent)
{
    //使用大号布局
#if LV_DEMO_MUSIC_LARGE 
    font_small = &lv_font_montserrat_22;
    font_large = &lv_font_montserrat_32;
#else
    font_small = &lv_font_montserrat_12;
    font_large = &lv_font_montserrat_16;
#endif

    //创建一个容器 
    /*Create the content of the music player*/ 
    lv_obj_t * cont = create_cont(parent);
    create_wave_images(cont);

    lv_obj_t * title_box = create_title_box(cont); 
    lv_obj_t * icon_box = create_icon_box(cont);
    lv_obj_t * ctrl_box = create_ctrl_box(cont);

    //创建频谱+专辑图片显示
    spectrum_obj = create_spectrum_obj(cont);
    lv_obj_t * handle_box = create_handle(cont); //创建一个底部栏

#if LV_DEMO_MUSIC_ROUND
    lv_obj_set_style_pad_hor(cont, LV_HOR_RES / 6, 0);
#endif

//将内容网格排列  动态布局方式
    /*Arrange the content into a grid*/
#if LV_DEMO_MUSIC_SQUARE || LV_DEMO_MUSIC_ROUND
    static const lv_coord_t grid_cols[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_rows[] = {LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                     0,   /*Spectrum obj, set later*/
                                     LV_GRID_CONTENT, /*Title box*/
                                     LV_GRID_FR(3),   /*Spacer*/
                                     LV_GRID_CONTENT, /*Icon box*/
                                     LV_GRID_FR(3),   /*Spacer*/
                                     LV_GRID_CONTENT, /*Control box*/
                                     LV_GRID_FR(3),   /*Spacer*/
                                     LV_GRID_CONTENT, /*Handle box*/
                                     LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                     LV_GRID_TEMPLATE_LAST
                                    };

    grid_rows[1] = LV_VER_RES;

    lv_obj_set_grid_dsc_array(cont, grid_cols, grid_rows);
    lv_obj_set_style_grid_row_align(cont, LV_GRID_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_set_grid_cell(spectrum_obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(title_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(icon_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(ctrl_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_ALIGN_CENTER, 6, 1);
    lv_obj_set_grid_cell(handle_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_ALIGN_CENTER, 8, 1);
#elif LV_DEMO_MUSIC_LANDSCAPE == 0
    static const lv_coord_t grid_cols[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static const lv_coord_t grid_rows[] = {LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Title box*/
                                           LV_GRID_FR(3),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Icon box*/
                                           LV_GRID_FR(3),   /*Spacer*/
# if LV_DEMO_MUSIC_LARGE == 0
                                           250,    /*Spectrum obj*/
# else
                                           480,   /*Spectrum obj*/
# endif
                                           LV_GRID_FR(3),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Control box*/
                                           LV_GRID_FR(3),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Handle box*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                           LV_GRID_TEMPLATE_LAST
                                          };

    //网格局部整个界面
    lv_obj_set_grid_dsc_array(cont, grid_cols, grid_rows);
    lv_obj_set_style_grid_row_align(cont, LV_GRID_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_set_grid_cell(title_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(icon_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(spectrum_obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 6, 1);
    lv_obj_set_grid_cell(ctrl_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 8, 1);
    lv_obj_set_grid_cell(handle_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 10, 1);
#else
    /*Arrange the content into a grid*/
    static const lv_coord_t grid_cols[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static const lv_coord_t grid_rows[] = {LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Title box*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Icon box*/
                                           LV_GRID_FR(3),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Control box*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_GRID_CONTENT, /*Handle box*/
                                           LV_GRID_FR(1),   /*Spacer*/
                                           LV_DEMO_MUSIC_HANDLE_SIZE,     /*Spacing*/
                                           LV_GRID_TEMPLATE_LAST
                                          };

    lv_obj_set_grid_dsc_array(cont, grid_cols, grid_rows);
    lv_obj_set_style_grid_row_align(cont, LV_GRID_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_set_grid_cell(title_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(icon_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(ctrl_box, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_CENTER, 6, 1);
    lv_obj_set_grid_cell(handle_box, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_CENTER, 8, 1);
    lv_obj_set_grid_cell(spectrum_obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 1, 9);
#endif

    //创建一个定时器：用于刷新进度条和时间的值
    sec_counter_timer = lv_timer_create(timer_cb, 1000, NULL);
    lv_timer_pause(sec_counter_timer); //暂停定时器

    /*Animate in the content after the intro time*/
    lv_anim_t a;

    start_anim = true;

    //创建一个定时任务，控制动画效果
    lv_timer_t * timer = lv_timer_create(stop_start_anim, INTRO_TIME + 6000, NULL);
    lv_timer_set_repeat_count(timer, 1);

    //动画初始化
    lv_anim_init(&a); //初始化一个动画变量
    lv_anim_set_path_cb(&a, lv_anim_path_bounce); //设置动画路径：从最终值反弹一点(就像撞到一堵墙)

    uint32_t i;
    lv_anim_set_exec_cb(&a, start_anim_cb); //设置一个动画回调
    for(i = 0; i < BAR_CNT; i++) { //一半为20，整个圆两边频谱对称
        lv_anim_set_values(&a, LV_HOR_RES, 5); //设置一个动画的开始和结束值
        lv_anim_set_delay(&a, INTRO_TIME - 200 + rnd_array[i] % 200);
        lv_anim_set_time(&a, 2500 + rnd_array[i] % 500);
        lv_anim_set_var(&a, &start_anim_values[i]); //为对象设置一个动画
        lv_anim_start(&a);//开始动画
    }

    //使用opa_scale动画淡入(从透明到完全覆盖)对象及其所有子对象。设置一个启动的效果  //此处可以增加开机logo
    //形参：obj：淡入的对象time：动画的持续时间[ms]delay：等待动画开始播放[ms]
    lv_obj_fade_in(title_box, 1000, INTRO_TIME + 1000);
    lv_obj_fade_in(icon_box, 1000, INTRO_TIME + 1000);
    lv_obj_fade_in(ctrl_box, 1000, INTRO_TIME + 1000);
    lv_obj_fade_in(handle_box, 1000, INTRO_TIME + 1000);
    lv_obj_fade_in(album_img_obj, 800, INTRO_TIME + 1000);
    lv_obj_fade_in(spectrum_obj, 0, INTRO_TIME);//频谱先出现

    //进主界面的动画
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out); //设置淡出---最后很慢
    lv_anim_set_var(&a, album_img_obj); //专辑图片为动画对象
    lv_anim_set_time(&a, 1000);
    lv_anim_set_delay(&a, INTRO_TIME + 1000);
    lv_anim_set_values(&a, 1, LV_IMG_ZOOM_NONE);
    lv_anim_set_exec_cb(&a, _img_set_zoom_anim_cb);
    lv_anim_set_ready_cb(&a, NULL);
    lv_anim_start(&a); //开始动画

    //初始动画和显示
    /* Create an intro from a logo + label */
    //创建logo
    LV_IMG_DECLARE(img_lv_demo_music_logo);
    lv_obj_t * logo = lv_img_create(lv_scr_act());
    lv_img_set_src(logo, &img_lv_demo_music_logo);
    lv_obj_move_foreground(logo); //将对象带到前台

    //创建标题
    lv_obj_t * title = lv_label_create(lv_scr_act());
    lv_label_set_text(title, "LVGL Demo\nMusic player");
    lv_obj_set_style_text_align(title, LV_TEXT_ALIGN_CENTER, 0); //居中
    lv_obj_set_style_text_font(title, font_large, 0);//大号字体
    lv_obj_set_style_text_line_space(title, 8, 0); //设置上下两排字体之间的间隔
    lv_obj_fade_out(title, 500, INTRO_TIME);// 使用opa_scale动画淡出(从透明到完全覆盖)对象及其所有子对象。 

    //对齐方式
    lv_obj_align_to(logo, spectrum_obj, LV_ALIGN_CENTER, 0, 0); //logo和频谱对象居中
    lv_obj_align_to(title, logo, LV_ALIGN_OUT_LEFT_MID, -20, 0);//标题相对于logo的位置

    //进入主界面，看到一个动画
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in); //开始时很慢
    lv_anim_set_var(&a, logo); //动画的对象设置为logo
    lv_anim_set_time(&a, 400); //设置动画的时长
    lv_anim_set_delay(&a, INTRO_TIME + 800); //在开始动画前设置一个延迟
    lv_anim_set_values(&a, LV_IMG_ZOOM_NONE, 10); //设置值， logo的动画效果从大到小
    lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb); //当动画准备好时，设置一个函数调用
    lv_anim_start(&a); //开启动画

    lv_obj_update_layout(main_cont); //更新加载界面

    return main_cont;
}

/**********************************************************************
*Functional description:切换专辑图片
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-18           V1.0           RunningCode             Create
***********************************************************************/
void _lv_demo_music_album_next(bool next)
{
    uint32_t id = track_id; //当前播放歌曲
    if(next) {
        id++;
        if(id >= ACTIVE_TRACK_CNT) id = 0;
    }
    else {
        if(id == 0) {
            id = ACTIVE_TRACK_CNT - 1;
        }
        else {
            id--;
        }
    }

    //歌曲播放状态
    if(playing) {
        _lv_demo_music_play(id);
    }
    else {
        track_load(id);
    }
}

/**********************************************************************
*Functional description:播放指定id歌曲
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-18           V1.0           RunningCode             Create
***********************************************************************/
void _lv_demo_music_play(uint32_t id)
{
    track_load(id);

    _lv_demo_music_resume();
}

/**********************************************************************
*Functional description:恢复音乐
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
void _lv_demo_music_resume(void)
{
    playing = true; //播放音乐
    spectrum_i = spectrum_i_pause;
    lv_anim_t a;
    lv_anim_init(&a); //设置一个函数来动画' var '
    lv_anim_set_values(&a, spectrum_i, spectrum_len - 1); //设置动画的开始和结束值
    lv_anim_set_exec_cb(&a, spectrum_anim_cb); //设置一个函数来动画' var '
    lv_anim_set_var(&a, spectrum_obj); //设置一个变量为animate
    lv_anim_set_time(&a, ((spectrum_len - spectrum_i) * 1000) / 30); //设置动画的持续时间
    lv_anim_set_playback_time(&a, 0); //回放时间，使动画回放时，正方向准备好了
    lv_anim_set_ready_cb(&a, spectrum_end_cb); //当动画准备好时，设置一个函数调用
    lv_anim_start(&a);

    //计时器进入计时状态
    lv_timer_resume(sec_counter_timer);
    //获取歌曲的时长，为滑动的长度
    lv_slider_set_range(slider_obj, 0, _lv_demo_music_get_track_length(track_id));

    lv_obj_add_state(play_obj, LV_STATE_CHECKED);

}

/**********************************************************************
*Functional description:音乐暂停
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
void _lv_demo_music_pause(void)
{
    playing = false;
    spectrum_i_pause = spectrum_i;
    spectrum_i = 0;
    lv_anim_del(spectrum_obj, spectrum_anim_cb);//删除频谱动画
    lv_obj_invalidate(spectrum_obj);
    //图片设置缩放
    lv_img_set_zoom(album_img_obj, LV_IMG_ZOOM_NONE);
    lv_timer_pause(sec_counter_timer);
    lv_obj_clear_state(play_obj, LV_STATE_CHECKED);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
/**********************************************************************
*Functional description:创建一个容器
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-17           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_cont(lv_obj_t * parent)
{
    /*A transparent container in which the player section will be scrolled*/
    main_cont = lv_obj_create(parent); //创建一个根容器，一般用于存放控件
    lv_obj_clear_flag(main_cont, LV_OBJ_FLAG_CLICKABLE); //清除主界面容器可点击的标志位
    lv_obj_clear_flag(main_cont, LV_OBJ_FLAG_SCROLL_ELASTIC); //允许在内部滚动但速度较慢
    lv_obj_remove_style_all(main_cont);  //删除所有样式                  /*Make it transparent*/
    lv_obj_set_size(main_cont, lv_pct(100), lv_pct(100)); //设置百分比来 设定控件的尺寸属性
    //捕捉Cont Y方向的子对象，将他们与Container中心对齐 ； snap ：捕获；捕捉
    lv_obj_set_scroll_snap_y(main_cont, LV_SCROLL_SNAP_CENTER);    /*Snap the children to the center*/

    /*Create a container for the player*/
    //创建player
    lv_obj_t * player = lv_obj_create(main_cont); //在主界面容器创建一个音乐播放的控件
    lv_obj_set_y(player, - LV_DEMO_MUSIC_HANDLE_SIZE);//设置y轴方向的坐标位置 ?整体布局Y轴偏移-20

#if LV_DEMO_MUSIC_SQUARE || LV_DEMO_MUSIC_ROUND
    lv_obj_set_size(player, LV_HOR_RES, 2 * LV_VER_RES + LV_DEMO_MUSIC_HANDLE_SIZE * 2);
#else
    lv_obj_set_size(player, LV_HOR_RES, LV_VER_RES + LV_DEMO_MUSIC_HANDLE_SIZE * 2); //设置
#endif
    //lv_obj_clear_flag禁用一些属性； lv_obj_add_flag 开启一些属性
    lv_obj_clear_flag(player, LV_OBJ_FLAG_SNAPABLE); //如果在父对象上启用了滚动捕捉，它可以捕捉到这个对象

    lv_obj_set_style_bg_color(player, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_border_width(player, 0, 0); //设置边框
    lv_obj_set_style_pad_all(player, 0, 0); //设置边框
    //限制滚动的方向
    lv_obj_set_scroll_dir(player, LV_DIR_VER); //只能垂直滚动

    /* Transparent placeholders below the player container
     * It is used only to snap it to center.*/
    lv_obj_t * placeholder1 = lv_obj_create(main_cont); //创建一个根容器
    lv_obj_remove_style_all(placeholder1);
    lv_obj_clear_flag(placeholder1, LV_OBJ_FLAG_CLICKABLE);
    //    lv_obj_set_style_bg_color(placeholder1, lv_color_hex(0xff0000), 0);
    //    lv_obj_set_style_bg_opa(placeholder1, LV_OPA_50, 0);

    lv_obj_t * placeholder2 = lv_obj_create(main_cont);
    lv_obj_remove_style_all(placeholder2);
    lv_obj_clear_flag(placeholder2, LV_OBJ_FLAG_CLICKABLE);
    //    lv_obj_set_style_bg_color(placeholder2, lv_color_hex(0x00ff00), 0);
    //    lv_obj_set_style_bg_opa(placeholder2, LV_OPA_50, 0);

#if LV_DEMO_MUSIC_SQUARE || LV_DEMO_MUSIC_ROUND
    lv_obj_t * placeholder3 = lv_obj_create(main_cont);
    lv_obj_remove_style_all(placeholder3);
    lv_obj_clear_flag(placeholder3, LV_OBJ_FLAG_CLICKABLE);
    //    lv_obj_set_style_bg_color(placeholder3, lv_color_hex(0x0000ff), 0);
    //    lv_obj_set_style_bg_opa(placeholder3, LV_OPA_20, 0);

    lv_obj_set_size(placeholder1, lv_pct(100), LV_VER_RES);
    lv_obj_set_y(placeholder1, 0);

    lv_obj_set_size(placeholder2, lv_pct(100), LV_VER_RES);
    lv_obj_set_y(placeholder2, LV_VER_RES);

    lv_obj_set_size(placeholder3, lv_pct(100),  LV_VER_RES - 2 * LV_DEMO_MUSIC_HANDLE_SIZE);
    lv_obj_set_y(placeholder3, 2 * LV_VER_RES + LV_DEMO_MUSIC_HANDLE_SIZE);
#else
    lv_obj_set_size(placeholder1, lv_pct(100), LV_VER_RES); //LV_VER_RES 获取高度
    lv_obj_set_y(placeholder1, 0);

    lv_obj_set_size(placeholder2, lv_pct(100),  LV_VER_RES - 2 * LV_DEMO_MUSIC_HANDLE_SIZE);
    lv_obj_set_y(placeholder2, LV_VER_RES + LV_DEMO_MUSIC_HANDLE_SIZE);
#endif

    lv_obj_update_layout(main_cont);

    return player;
}

/**********************************************************************
*Functional description:创建顶部和底部的图片并显示
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-13           V1.0           RunningCode             Create
***********************************************************************/
static void create_wave_images(lv_obj_t * parent)
{
    //顶部图片
    LV_IMG_DECLARE(img_lv_demo_music_wave_top); //顶部图片
    LV_IMG_DECLARE(img_lv_demo_music_wave_bottom); //底部图片
    lv_obj_t * wave_top = lv_img_create(parent);  //创建一个图片控件
    lv_img_set_src(wave_top, &img_lv_demo_music_wave_top); //设置图片资源
    lv_obj_set_width(wave_top, LV_HOR_RES);//设置图片的宽度，获取屏幕水平尺寸
    lv_obj_align(wave_top, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_add_flag(wave_top, LV_OBJ_FLAG_IGNORE_LAYOUT);

    lv_obj_t * wave_bottom = lv_img_create(parent);
    lv_img_set_src(wave_bottom, &img_lv_demo_music_wave_bottom);
    lv_obj_set_width(wave_bottom, LV_HOR_RES);
    lv_obj_align(wave_bottom, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(wave_bottom, LV_OBJ_FLAG_IGNORE_LAYOUT);

    //?效果未知
    LV_IMG_DECLARE(img_lv_demo_music_corner_left);
    LV_IMG_DECLARE(img_lv_demo_music_corner_right);
    lv_obj_t * wave_corner = lv_img_create(parent);
    lv_img_set_src(wave_corner, &img_lv_demo_music_corner_left);
#if LV_DEMO_MUSIC_ROUND == 0
    lv_obj_align(wave_corner, LV_ALIGN_BOTTOM_LEFT, 0, 0);
#else
    lv_obj_align(wave_corner, LV_ALIGN_BOTTOM_LEFT, -LV_HOR_RES / 6, 0);
#endif
    lv_obj_add_flag(wave_corner, LV_OBJ_FLAG_IGNORE_LAYOUT);

    wave_corner = lv_img_create(parent);
    lv_img_set_src(wave_corner, &img_lv_demo_music_corner_right);
#if LV_DEMO_MUSIC_ROUND == 0
    lv_obj_align(wave_corner, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
#else
    lv_obj_align(wave_corner, LV_ALIGN_BOTTOM_RIGHT, LV_HOR_RES / 6, 0);
#endif
    lv_obj_add_flag(wave_corner, LV_OBJ_FLAG_IGNORE_LAYOUT);
}

/**********************************************************************
*Functional description:创建标题栏：显示一些歌曲信息
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-13           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_title_box(lv_obj_t * parent)
{

    /*Create the titles*/
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_height(cont, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    title_label = lv_label_create(cont); //歌曲名字
    lv_obj_set_style_text_font(title_label, font_large, 0); //大字
    lv_obj_set_style_text_color(title_label, lv_color_hex(0x504d6d), 0);
    lv_label_set_text(title_label, _lv_demo_music_get_title(track_id)); //获取歌曲名字
    lv_obj_set_height(title_label, lv_font_get_line_height(font_large) * 3 / 2); //字体高度

    artist_label = lv_label_create(cont); //艺术家
    lv_obj_set_style_text_font(artist_label, font_small, 0); //小字
    lv_obj_set_style_text_color(artist_label, lv_color_hex(0x504d6d), 0);
    lv_label_set_text(artist_label, _lv_demo_music_get_artist(track_id));

    genre_label = lv_label_create(cont); //类型
    lv_obj_set_style_text_font(genre_label, font_small, 0);
    lv_obj_set_style_text_color(genre_label, lv_color_hex(0x8a86b8), 0);
    lv_label_set_text(genre_label, _lv_demo_music_get_genre(track_id));

    return cont;
}

/**********************************************************************
*Functional description:创建：收藏，频谱，下载，评论等图标
*Input parameter:实现具体功能，需要监听按钮事件
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-13           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_icon_box(lv_obj_t * parent)
{

    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_height(cont, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * icon;
    LV_IMG_DECLARE(img_lv_demo_music_icon_1);
    LV_IMG_DECLARE(img_lv_demo_music_icon_2);
    LV_IMG_DECLARE(img_lv_demo_music_icon_3);
    LV_IMG_DECLARE(img_lv_demo_music_icon_4);
    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_icon_1);
    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_icon_2);
    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_icon_3);
    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_icon_4);

    return cont;
}

/**********************************************************************
*Functional description:创建频谱对象和加载图片
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_spectrum_obj(lv_obj_t * parent)
{
    /*Create the spectrum visualizer*/
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
#if LV_DEMO_MUSIC_LARGE
    lv_obj_set_height(obj, 500);
#else
    lv_obj_set_height(obj, 250);
#endif
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(obj, spectrum_draw_event_cb, LV_EVENT_ALL, NULL);//添加一个绘制频谱事件
    lv_obj_refresh_ext_draw_size(obj); // 刷新绘图大小
    album_img_obj = album_img_create(obj);//创建一个专辑图片显示控件，并且监听手势事件
    return obj;
}

/**********************************************************************
*Functional description:创建控制音乐播放器栏目,播放进度条，时间
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-13           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_ctrl_box(lv_obj_t * parent)
{
    /*Create the control box*/
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    //用于设置一个对象和它子对象高度和宽度的特殊值。它类似于CSS里的自动设置
    lv_obj_set_height(cont, LV_SIZE_CONTENT); 
#if LV_DEMO_MUSIC_LARGE
    lv_obj_set_style_pad_bottom(cont, 17, 0);
#else
    lv_obj_set_style_pad_bottom(cont, 8, 0);
#endif
    //网格布局 [创建的数组一定要声明为 static 或全局变量，因为这部分数据在后续渲染时才会被用上]  行，列
    static const lv_coord_t grid_col[] = {LV_GRID_FR(2), LV_GRID_FR(3), LV_GRID_FR(5), LV_GRID_FR(5), LV_GRID_FR(5), LV_GRID_FR(3), LV_GRID_FR(2), LV_GRID_TEMPLATE_LAST};
    static const lv_coord_t grid_row[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    //为一个容器设置网格划分
    lv_obj_set_grid_dsc_array(cont, grid_col, grid_row);

    //添加图片声明
    LV_IMG_DECLARE(img_lv_demo_music_btn_loop);
    LV_IMG_DECLARE(img_lv_demo_music_btn_rnd);
    LV_IMG_DECLARE(img_lv_demo_music_btn_next);
    LV_IMG_DECLARE(img_lv_demo_music_btn_prev);
    LV_IMG_DECLARE(img_lv_demo_music_btn_play);
    LV_IMG_DECLARE(img_lv_demo_music_btn_pause);

    lv_obj_t * icon;
    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_btn_rnd); //随机播放
    //将每一个控件，放在对应的位置 【第一个为空占位符】
    lv_obj_set_grid_cell(icon, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);//第一行

    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_btn_loop); //循环播放
    lv_obj_set_grid_cell(icon, LV_GRID_ALIGN_END, 5, 1, LV_GRID_ALIGN_CENTER, 0, 1); //第5个控件第一排 播放模式，循环播放位于第一排，最后，

    icon = lv_img_create(cont);
    lv_img_set_src(icon, &img_lv_demo_music_btn_prev); //上一首歌曲
    lv_obj_set_grid_cell(icon, LV_GRID_ALIGN_CENTER, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);//第二个控件，上一首歌曲
    lv_obj_add_event_cb(icon, prev_click_event_cb, LV_EVENT_CLICKED, NULL);

    play_obj = lv_imgbtn_create(cont); //图片按钮
    lv_imgbtn_set_src(play_obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_lv_demo_music_btn_play, NULL); //播放歌曲
    lv_imgbtn_set_src(play_obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_lv_demo_music_btn_pause, NULL);//歌曲暂停
    lv_obj_add_flag(play_obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_grid_cell(play_obj, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_add_event_cb(play_obj, play_event_click_cb, LV_EVENT_CLICKED, NULL);//添加按钮点击事件
    lv_obj_add_flag(play_obj, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_width(play_obj, img_lv_demo_music_btn_play.header.w);

    icon = lv_img_create(cont); //下一首歌曲
    lv_img_set_src(icon, &img_lv_demo_music_btn_next);
    lv_obj_set_grid_cell(icon, LV_GRID_ALIGN_CENTER, 4, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_event_cb(icon, next_click_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_flag(icon, LV_OBJ_FLAG_CLICKABLE);

    //进度条样式
    LV_IMG_DECLARE(img_lv_demo_music_slider_knob); //播放进度条的小按钮
    slider_obj = lv_slider_create(cont);
    lv_obj_set_style_anim_time(slider_obj, 100, 0); //修改动画时间 
    lv_obj_add_flag(slider_obj, LV_OBJ_FLAG_CLICKABLE); /*No input from the slider*/

#if LV_DEMO_MUSIC_LARGE == 0
    lv_obj_set_height(slider_obj, 3);
#else
    lv_obj_set_height(slider_obj, 6);
#endif
    lv_obj_set_grid_cell(slider_obj, LV_GRID_ALIGN_STRETCH, 1, 4, LV_GRID_ALIGN_CENTER, 1, 1); //第二排，第一个图标，占位4

    //LV_PART_MAIN 滑动条背景；  LV_PART_INDICATOR：显示滑动条状态的指示器   LV_PART_KNOB：旋钮
    lv_obj_set_style_bg_img_src(slider_obj, &img_lv_demo_music_slider_knob, LV_PART_KNOB); //进度条的小按钮样式
    lv_obj_set_style_bg_opa(slider_obj, LV_OPA_TRANSP, LV_PART_KNOB); //设置透明度
    lv_obj_set_style_pad_all(slider_obj, 20, LV_PART_KNOB);
    lv_obj_set_style_bg_grad_dir(slider_obj, LV_GRAD_DIR_HOR, LV_PART_INDICATOR); //渐变？
    lv_obj_set_style_bg_color(slider_obj, lv_color_hex(0x569af8), LV_PART_INDICATOR); //主要颜色
    lv_obj_set_style_bg_grad_color(slider_obj, lv_color_hex(0xa666f1), LV_PART_INDICATOR); //渐变颜色
    lv_obj_set_style_outline_width(slider_obj, 0, 0); //滑动条的边框

    //歌曲时间显示
    time_obj = lv_label_create(cont);
    lv_obj_set_style_text_font(time_obj, font_small, 0); //设置字体大小
    lv_obj_set_style_text_color(time_obj, lv_color_hex(0x8a86b8), 0); //设置字体颜色
    lv_label_set_text(time_obj, "0:00"); //设置内容
    lv_obj_set_grid_cell(time_obj, LV_GRID_ALIGN_END, 5, 1, LV_GRID_ALIGN_CENTER, 1, 1); //设置标签的具体布局位置

    return cont;
}

/**********************************************************************
*Functional description:创建一个滑动到所有曲目的标签
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * create_handle(lv_obj_t * parent)
{
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);

    //还是容器的使用，是布局便于调整
    lv_obj_set_size(cont, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(cont, 8, 0);

    /*A handle to scroll to the track list*/ //创建一个标签
    lv_obj_t * handle_label = lv_label_create(cont);
    lv_label_set_text(handle_label, "ALL TRACKS"); //所有曲目
    lv_obj_set_style_text_font(handle_label, font_small, 0);
    lv_obj_set_style_text_color(handle_label, lv_color_hex(0x8a86b8), 0);

    //可以下拉的示意
    lv_obj_t * handle_rect = lv_obj_create(cont);
#if LV_DEMO_MUSIC_LARGE
    lv_obj_set_size(handle_rect, 40, 3);
#else
    lv_obj_set_size(handle_rect, 20, 2);
#endif

    lv_obj_set_style_bg_color(handle_rect, lv_color_hex(0x8a86b8), 0);
    lv_obj_set_style_border_width(handle_rect, 0, 0);

    return cont;
}

/**********************************************************************
*Functional description:加载指定id歌曲
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-18           V1.0           RunningCode             Create
***********************************************************************/
static void track_load(uint32_t id)
{
    spectrum_i = 0;//频谱的值为0
    time_act = 0; //播放时间为0
    spectrum_i_pause = 0; 
    //进度条设置成0，关闭动画
    lv_slider_set_value(slider_obj, 0, LV_ANIM_OFF);
    lv_label_set_text(time_obj, "0:00"); //时间设置为0

    if(id == track_id) return; //加载的音乐为当前音乐，直接返回
    bool next = false;
    if((track_id + 1) % ACTIVE_TRACK_CNT == id) next = true;  //重新加载的歌曲是否为下一首歌曲

    //同步播放列表的状态
    //在播放列表中，之前被选中的歌曲，设置为未被选中
    _lv_demo_music_list_btn_check(track_id, false);

    track_id = id; //当前播放歌曲更改

    _lv_demo_music_list_btn_check(id, true); //重新设定当前播放歌曲

    //标签更新当前播放歌曲的内容
    lv_label_set_text(title_label, _lv_demo_music_get_title(track_id));
    lv_label_set_text(artist_label, _lv_demo_music_get_artist(track_id));
    lv_label_set_text(genre_label, _lv_demo_music_get_genre(track_id));

    //淡出
    lv_obj_fade_out(album_img_obj, 500, 0);

    lv_anim_t a;
    lv_anim_init(&a);
    //专辑动画淡出的效果
    lv_anim_set_var(&a, album_img_obj);
    lv_anim_set_time(&a, 500);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
#if LV_DEMO_MUSIC_LANDSCAPE
    if(next) {
        lv_anim_set_values(&a, 0, - LV_HOR_RES / 7);
    }
    else {
        lv_anim_set_values(&a, 0, LV_HOR_RES / 7);
    }
#else
    if(next) {
        lv_anim_set_values(&a, 0, - LV_HOR_RES / 2);
    }
    else {
        lv_anim_set_values(&a, 0, LV_HOR_RES / 2);
    }
#endif
    lv_anim_set_exec_cb(&a, _obj_set_x_anim_cb);
    lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
    lv_anim_start(&a); //比较大的专辑进行退出

    lv_anim_set_path_cb(&a, lv_anim_path_linear);
    lv_anim_set_var(&a, album_img_obj);
    lv_anim_set_time(&a, 500);
    lv_anim_set_values(&a, LV_IMG_ZOOM_NONE, LV_IMG_ZOOM_NONE / 2);
    lv_anim_set_exec_cb(&a, _img_set_zoom_anim_cb);
    lv_anim_set_ready_cb(&a, NULL);
    lv_anim_start(&a);//再以一半的大小退出

    //专辑动画效果
    album_img_obj = album_img_create(spectrum_obj);
    lv_obj_fade_in(album_img_obj, 500, 100);

    lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
    lv_anim_set_var(&a, album_img_obj);
    lv_anim_set_time(&a, 500);
    lv_anim_set_delay(&a, 100);
    lv_anim_set_values(&a, LV_IMG_ZOOM_NONE / 4, LV_IMG_ZOOM_NONE);
    lv_anim_set_exec_cb(&a, _img_set_zoom_anim_cb);
    lv_anim_set_ready_cb(&a, NULL);
    lv_anim_start(&a);
}

int32_t get_cos(int32_t deg, int32_t a)
{
    int32_t r = (lv_trigo_cos(deg) * a);

    r += LV_TRIGO_SIN_MAX / 2;
    return r >> LV_TRIGO_SHIFT;
}

int32_t get_sin(int32_t deg, int32_t a)
{
    int32_t r = lv_trigo_sin(deg) * a;

    r += LV_TRIGO_SIN_MAX / 2;
    return r >> LV_TRIGO_SHIFT;

}

/**********************************************************************
*Functional description:创建频谱事件
*Input parameter:
*Return:
*Other description:包含频谱条显示，图片缩放
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
static void spectrum_draw_event_cb(lv_event_t * e) //lv_event_t 是传递给事件回调的唯一参数，它包含关于事件的所有数据。
{
    lv_event_code_t code = lv_event_get_code(e); //获取事件代码

    //获得对象周围所需的额外绘制区域(例如阴影)
    if(code == LV_EVENT_REFR_EXT_DRAW_SIZE) {
       // LV_LOG_WARN("1111111111111111");
#if LV_DEMO_MUSIC_LANDSCAPE
        lv_event_set_ext_draw_size(e, LV_HOR_RES);
#else
        lv_event_set_ext_draw_size(e, LV_VER_RES);
#endif
    }
    else if(code == LV_EVENT_COVER_CHECK) { //检查对象是否完全覆盖了一个区域。
        lv_event_set_cover_res(e, LV_COVER_RES_NOT_COVER);//设置封面检查的结果。可以在' LV_EVENT_COVER_CHECK '中使用
      //  LV_LOG_WARN("222222222222222222");
    }
    else if(code == LV_EVENT_DRAW_POST) { //执行post绘制阶段 (当所有子元素都绘制的时候)
     //   LV_LOG_WARN("3333333333333333333");
        lv_obj_t * obj = lv_event_get_target(e); //获取最初触发事件的对象(与Lv_event_get_target(如果启用了事件冒泡)
        lv_draw_ctx_t * draw_ctx = lv_event_get_draw_ctx(e); //获取事件对象的绘制上下文对象

        //功能：获取处于对象当前状态的对象的一部分的样式属性。如果正在运行过渡,则将其考虑在内
        lv_opa_t opa = lv_obj_get_style_opa(obj, LV_PART_MAIN); //透明度
        if(opa < LV_OPA_MIN) return; 

        lv_point_t poly[4];
        lv_point_t center;
        center.x = obj->coords.x1 + lv_obj_get_width(obj) / 2;
        center.y = obj->coords.y1 + lv_obj_get_height(obj) / 2;

        lv_draw_rect_dsc_t draw_dsc;
        lv_draw_rect_dsc_init(&draw_dsc);
        draw_dsc.bg_opa = LV_OPA_COVER; //设置透明度

        uint16_t r[64];
        uint32_t i;

        lv_coord_t min_a = 5;

#if LV_DEMO_MUSIC_LARGE == 0
        lv_coord_t r_in = 77;
#else
        lv_coord_t r_in = 160;
#endif

        r_in = (r_in * lv_img_get_zoom(album_img_obj)) >> 8; //获取图片缩放参数
        for(i = 0; i < BAR_CNT; i++) r[i] = r_in + min_a;

        uint32_t s;
        for(s = 0; s < 4; s++) {
            uint32_t f;
            uint32_t band_w = 0;    /*Real number of bars in this band.*/
            switch(s) {
                case 0:
                    band_w = 20;
                    break;
                case 1:
                    band_w = 8;
                    break;
                case 2:
                    band_w = 4;
                    break;
                case 3:
                    band_w = 2;
                    break;
            }

            /* Add "side bars" with cosine characteristic.*/
            for(f = 0; f < band_w; f++) {
                uint32_t ampl_main = spectrum[spectrum_i][s];
                int32_t ampl_mod = get_cos(f * 360 / band_w + 180, 180) + 180; //数学函数 sin cos tan
                int32_t t = BAR_PER_BAND_CNT * s - band_w / 2 + f;
                if(t < 0) t = BAR_CNT + t;
                if(t >= BAR_CNT) t = t - BAR_CNT;
                r[t] += (ampl_main * ampl_mod) >> 9;
            }
        }

        uint32_t amax = 20;
        int32_t animv = spectrum_i - spectrum_lane_ofs_start;
        if(animv > amax) animv = amax;
        for(i = 0; i < BAR_CNT; i++) {
            uint32_t deg_space = 1;
            uint32_t deg = i * DEG_STEP + 90;
            uint32_t j = (i + bar_rot + rnd_array[bar_ofs % 10]) % BAR_CNT;
            uint32_t k = (i + bar_rot + rnd_array[(bar_ofs + 1) % 10]) % BAR_CNT;

            uint32_t v = (r[k] * animv + r[j] * (amax - animv)) / amax;
            if(start_anim) {
                v = r_in + start_anim_values[i];
                deg_space = v >> 7;
                if(deg_space < 1) deg_space = 1;
            }

            if(v < BAR_COLOR1_STOP) draw_dsc.bg_color = BAR_COLOR1; //设置背景颜色
            else if(v > BAR_COLOR3_STOP) draw_dsc.bg_color = BAR_COLOR3;
            else if(v > BAR_COLOR2_STOP) draw_dsc.bg_color = lv_color_mix(BAR_COLOR3, BAR_COLOR2,
                                                                              ((v - BAR_COLOR2_STOP) * 255) / (BAR_COLOR3_STOP - BAR_COLOR2_STOP));
            else draw_dsc.bg_color = lv_color_mix(BAR_COLOR2, BAR_COLOR1,
                                                      ((v - BAR_COLOR1_STOP) * 255) / (BAR_COLOR2_STOP - BAR_COLOR1_STOP));

            uint32_t di = deg + deg_space;

            int32_t x1_out = get_cos(di, v);
            poly[0].x = center.x + x1_out;
            poly[0].y = center.y + get_sin(di, v);

            int32_t x1_in = get_cos(di, r_in);
            poly[1].x = center.x + x1_in;
            poly[1].y = center.y + get_sin(di, r_in);
            di += DEG_STEP - deg_space * 2;

            int32_t x2_in = get_cos(di, r_in);
            poly[2].x = center.x + x2_in;
            poly[2].y = center.y + get_sin(di, r_in);

            int32_t x2_out = get_cos(di, v);
            poly[3].x = center.x + x2_out;
            poly[3].y = center.y + get_sin(di, v);

            lv_draw_polygon(draw_ctx, &draw_dsc, poly, 4); //绘制多边形

            poly[0].x = center.x - x1_out;
            poly[1].x = center.x - x1_in;
            poly[2].x = center.x - x2_in;
            poly[3].x = center.x - x2_out;
            lv_draw_polygon(draw_ctx, &draw_dsc, poly, 4);
        }
    }
}

static void spectrum_anim_cb(void * a, int32_t v)
{
    lv_obj_t * obj = a;
    if(start_anim) {
        lv_obj_invalidate(obj);
        return;
    }

    spectrum_i = v;
    lv_obj_invalidate(obj);

    static uint32_t bass_cnt = 0;
    static int32_t last_bass = -1000;
    static int32_t dir = 1;
    if(spectrum[spectrum_i][0] > 12) {
        if(spectrum_i - last_bass > 5) {
            bass_cnt++;
            last_bass = spectrum_i;
            if(bass_cnt >= 2) {
                bass_cnt = 0;
                spectrum_lane_ofs_start = spectrum_i;
                bar_ofs++;
            }
        }
    }
    if(spectrum[spectrum_i][0] < 4) bar_rot += dir;

    lv_img_set_zoom(album_img_obj, LV_IMG_ZOOM_NONE + spectrum[spectrum_i][0]);
}

static void start_anim_cb(void * a, int32_t v)
{
    lv_coord_t * av = a;
    *av = v;
    lv_obj_invalidate(spectrum_obj); //用于标记 obj 的区域为 invalid，标记为 invalid 的区域，就意味着要被刷新；
}

/**********************************************************************
*Functional description:显示专辑图片
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * album_img_create(lv_obj_t * parent)
{
    //对应图片显示申明
    LV_IMG_DECLARE(img_lv_demo_music_cover_1);
    LV_IMG_DECLARE(img_lv_demo_music_cover_2);
    LV_IMG_DECLARE(img_lv_demo_music_cover_3);

    lv_obj_t * img;
    //album_img_create
    img = lv_img_create(parent);

    switch(track_id) {
        case 2:
            //设置图像
            lv_img_set_src(img, &img_lv_demo_music_cover_3);
            spectrum = spectrum_3;
            spectrum_len = sizeof(spectrum_3) / sizeof(spectrum_3[0]); //获取歌曲的时长
            break;
        case 1:
            lv_img_set_src(img, &img_lv_demo_music_cover_2);
            spectrum = spectrum_2;
            spectrum_len = sizeof(spectrum_2) / sizeof(spectrum_2[0]);
            break;
        case 0:
            lv_img_set_src(img, &img_lv_demo_music_cover_1);
            spectrum = spectrum_1;
            spectrum_len = sizeof(spectrum_1) / sizeof(spectrum_1[0]);
            break;
    }
    //抗锯齿开关
    lv_img_set_antialias(img, false);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0); //居中布局
    //监听手势事件
    lv_obj_add_event_cb(img, album_gesture_event_cb, LV_EVENT_GESTURE, NULL); //手势处理，其中动画包含图片退出效果
    lv_obj_clear_flag(img, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);

    return img;

}

//左右拖拽事件
static void album_gesture_event_cb(lv_event_t * e)
{
    //检测手势
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());

    //左滑
    if(dir == LV_DIR_LEFT) _lv_demo_music_album_next(true);
    //右滑
    if(dir == LV_DIR_RIGHT) _lv_demo_music_album_next(false);
}

//播放按钮，播放音乐
static void play_event_click_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)) {
        _lv_demo_music_resume(); //恢复音乐
    }
    else {
        _lv_demo_music_pause(); //音乐暂停
    }
}

static void prev_click_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    _lv_demo_music_album_next(false);
}

static void next_click_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        _lv_demo_music_album_next(true);
    }
}

/**********************************************************************
*Functional description:定时刷新进度条和时间
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-14           V1.0           RunningCode             Create
***********************************************************************/
static void timer_cb(lv_timer_t * t)
{
    LV_UNUSED(t);  //结构体可能存在
    time_act++;
    lv_label_set_text_fmt(time_obj, "%"LV_PRIu32":%02"LV_PRIu32, time_act / 60, time_act % 60);//格式化显示时间
    lv_slider_set_value(slider_obj, time_act, LV_ANIM_ON); //进度条设置值，随着定时器进行变化
}

static void spectrum_end_cb(lv_anim_t * a)
{
    LV_UNUSED(a);
    _lv_demo_music_album_next(true);
}


static void stop_start_anim(lv_timer_t * t)
{
    LV_UNUSED(t);
    start_anim = false;
    lv_obj_refresh_ext_draw_size(spectrum_obj);
}

// lv_obj_t * _lv_demo_music_main_create1(lv_obj_t * parent)
// {
//     //创建一个容器 
//     /*Create the content of the music player*/ 
//     lv_obj_t * cont = create_cont(parent);

// }

#endif /*LV_USE_DEMO_MUSIC*/

