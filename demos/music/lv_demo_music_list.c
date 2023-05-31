/**
 * @file lv_demo_music_list.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_music_list.h"
#if LV_USE_DEMO_MUSIC

#include "lv_demo_music_main.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_obj_t * add_list_btn(lv_obj_t * parent, uint32_t track_id);
static void btn_click_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * list;
static const lv_font_t * font_small;
static const lv_font_t * font_medium;
static lv_style_t style_scrollbar;
static lv_style_t style_btn;
static lv_style_t style_btn_pr;
static lv_style_t style_btn_chk;
static lv_style_t style_btn_dis;
static lv_style_t style_title;
static lv_style_t style_artist;
static lv_style_t style_time;
LV_IMG_DECLARE(img_lv_demo_music_btn_list_play);
LV_IMG_DECLARE(img_lv_demo_music_btn_list_pause);

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

//歌曲列表
lv_obj_t * _lv_demo_music_list_create(lv_obj_t * parent)
{
#if LV_DEMO_MUSIC_LARGE
    font_small = &lv_font_montserrat_16;
    font_medium = &lv_font_montserrat_22;
#else
    font_small = &lv_font_montserrat_12;
    font_medium = &lv_font_montserrat_16;
#endif

    //设置侧边滑动条的样式
    lv_style_init(&style_scrollbar);
    lv_style_set_width(&style_scrollbar,  4); //滑动条的宽度设置 设置成0 就去掉了滑动条
    lv_style_set_bg_opa(&style_scrollbar, LV_OPA_COVER); //设置背景透明度 完全覆盖LV_OPA_100
    lv_style_set_bg_color(&style_scrollbar, lv_color_hex3(0xeee)); //设置背景颜色
    lv_style_set_radius(&style_scrollbar, LV_RADIUS_CIRCLE);  //设置圆角
    lv_style_set_pad_right(&style_scrollbar, 4); //滑动条到右边背景的距离

    //每一列的参数设置
    static const lv_coord_t grid_cols[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    //每一行的参数设置
#if LV_DEMO_MUSIC_LARGE
    static const lv_coord_t grid_rows[] = {35,  30, LV_GRID_TEMPLATE_LAST};
#else
    static const lv_coord_t grid_rows[] = {22,  17, LV_GRID_TEMPLATE_LAST};
#endif

    //设置 按钮样式
    lv_style_init(&style_btn);
    lv_style_set_bg_opa(&style_btn, LV_OPA_TRANSP); //完全透明 LV_OPA_0
    lv_style_set_grid_column_dsc_array(&style_btn, grid_cols);
    lv_style_set_grid_row_dsc_array(&style_btn, grid_rows);
    lv_style_set_grid_row_align(&style_btn, LV_GRID_ALIGN_CENTER);
    lv_style_set_layout(&style_btn, LV_LAYOUT_GRID);
#if LV_DEMO_MUSIC_LARGE
    lv_style_set_pad_right(&style_btn, 30);
#else
    lv_style_set_pad_right(&style_btn, 20);
#endif

    //list item 被按下的样式
    lv_style_init(&style_btn_pr);
    lv_style_set_bg_opa(&style_btn_pr, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn_pr,  lv_color_hex(0x4c4965));

    //list item 被点击的样式
    lv_style_init(&style_btn_chk);
    lv_style_set_bg_opa(&style_btn_chk, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn_chk, lv_color_hex(0x4c4965));

    //list item 不可操作的样式
    lv_style_init(&style_btn_dis);
    lv_style_set_text_opa(&style_btn_dis, LV_OPA_40);
    lv_style_set_img_opa(&style_btn_dis, LV_OPA_40);

    //设置歌曲名样式
    lv_style_init(&style_title);
    lv_style_set_text_font(&style_title, font_medium);
    lv_style_set_text_color(&style_title, lv_color_hex(0xffffff));

    //设置艺术家名字样式
    lv_style_init(&style_artist);
    lv_style_set_text_font(&style_artist, font_small);
    lv_style_set_text_color(&style_artist, lv_color_hex(0xb1b0be));

    //设计歌曲时长样式
    lv_style_init(&style_time);
    lv_style_set_text_font(&style_time, font_medium);
    lv_style_set_text_color(&style_time, lv_color_hex(0xffffff));

    /*Create an empty transparent container*/
    //创建歌单
    list = lv_obj_create(parent);
    lv_obj_remove_style_all(list);
    lv_obj_set_size(list, LV_HOR_RES, LV_VER_RES - LV_DEMO_MUSIC_HANDLE_SIZE);
    lv_obj_set_y(list, LV_DEMO_MUSIC_HANDLE_SIZE);
    lv_obj_add_style(list, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_set_flex_flow(list, LV_FLEX_FLOW_COLUMN);

    uint32_t track_id;

    for(track_id = 0; _lv_demo_music_get_title(track_id); track_id++) {
        add_list_btn(list,  track_id); //添加每个list item 的信息
    }

#if LV_DEMO_MUSIC_SQUARE || LV_DEMO_MUSIC_ROUND
    lv_obj_set_scroll_snap_y(list, LV_SCROLL_SNAP_CENTER);
#endif

    //默认为第一首歌曲，状态为等待播放状态
   // _lv_demo_music_list_btn_check(0, true);
    _lv_demo_music_list_btn_check(0, false);

    return list;
}

/**********************************************************************
*Functional description:歌曲id和播放状态
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-19           V1.0           RunningCode             Create
***********************************************************************/
void _lv_demo_music_list_btn_check(uint32_t track_id, bool state)
{
    lv_obj_t * btn = lv_obj_get_child(list, track_id); //通过子索引获取对象的子对象
    lv_obj_t * icon = lv_obj_get_child(btn, 0);

    if(state) {
        lv_obj_add_state(btn, LV_STATE_CHECKED); //list item 的播放状态，改为播放中，按钮样式变为被点中的状态
        lv_img_set_src(icon, &img_lv_demo_music_btn_list_pause); //设置图片为点击暂停播放歌曲
        lv_obj_scroll_to_view(btn, LV_ANIM_ON); //
    }
    else {
        lv_obj_clear_state(btn, LV_STATE_CHECKED); //清除按钮被点击的状态
        lv_img_set_src(icon, &img_lv_demo_music_btn_list_play); //图片资源设置为，播放按钮
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**********************************************************************
*Functional description:将按钮添加到歌单列表
*Input parameter:
*Return:
*Other description:通过歌曲id，将歌曲信息放入列表
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-19           V1.0           RunningCode             Create
***********************************************************************/
static lv_obj_t * add_list_btn(lv_obj_t * parent, uint32_t track_id)
{
    uint32_t t = _lv_demo_music_get_track_length(track_id);
    char time[32];
    lv_snprintf(time, sizeof(time), "%"LV_PRIu32":%02"LV_PRIu32, t / 60, t % 60);
    const char * title = _lv_demo_music_get_title(track_id);
    const char * artist = _lv_demo_music_get_artist(track_id);

    //添加按钮样式
    lv_obj_t * btn = lv_obj_create(parent); //创建一个list按钮
    lv_obj_remove_style_all(btn); //创建控件之后，要清除控件的属性
#if LV_DEMO_MUSIC_LARGE
    lv_obj_set_size(btn, lv_pct(100), 110);
#else
    lv_obj_set_size(btn, lv_pct(100), 60);//高度为60
#endif

    //添加按钮在不同状态下的样式
    lv_obj_add_style(btn, &style_btn, 0);
    lv_obj_add_style(btn, &style_btn_pr, LV_STATE_PRESSED);
    lv_obj_add_style(btn, &style_btn_chk, LV_STATE_CHECKED);
    lv_obj_add_style(btn, &style_btn_dis, LV_STATE_DISABLED);
    lv_obj_add_event_cb(btn, btn_click_event_cb, LV_EVENT_CLICKED, NULL); //添加按钮点击事件

    if(track_id >= 3) {
        lv_obj_add_state(btn, LV_STATE_DISABLED); //歌曲id大于3，该歌曲不支持操作
    }
 
    //【每一行均是一个按钮，该大按钮有 播放按钮，歌曲名字，歌手名字，时间】
    //给按钮添加图片样式
    lv_obj_t * icon = lv_img_create(btn);
    lv_img_set_src(icon, &img_lv_demo_music_btn_list_play); //播放歌曲图片
    lv_obj_set_grid_cell(icon, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 0, 2); //网格布局的位置

    //
    lv_obj_t * title_label = lv_label_create(btn);
    lv_label_set_text(title_label, title);
    lv_obj_set_grid_cell(title_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_style(title_label, &style_title, 0);

    lv_obj_t * artist_label = lv_label_create(btn);
    lv_label_set_text(artist_label, artist);
    lv_obj_add_style(artist_label, &style_artist, 0);
    lv_obj_set_grid_cell(artist_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t * time_label = lv_label_create(btn);
    lv_label_set_text(time_label, time);
    lv_obj_add_style(time_label, &style_time, 0);
    lv_obj_set_grid_cell(time_label, LV_GRID_ALIGN_END, 2, 1, LV_GRID_ALIGN_CENTER, 0, 2);

    //list item 分割样式
    LV_IMG_DECLARE(img_lv_demo_music_list_border);
    lv_obj_t * border = lv_img_create(btn);
    lv_img_set_src(border, &img_lv_demo_music_list_border);
    lv_obj_set_width(border, lv_pct(120));
    lv_obj_align(border, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(border, LV_OBJ_FLAG_IGNORE_LAYOUT);

    return btn;
}


static void btn_click_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e); //获取按键的控件

    uint32_t idx = lv_obj_get_child_id(btn);//通过子索引获取对象的子对象
    LV_LOG_ERROR(" idx :%ld\n", idx);
    LV_LOG_WARN(" idx :%ld\n", idx);
    LV_LOG_USER(" idx :%ld\n", idx);
    _lv_demo_music_play(idx); //播放按键对应的歌曲ID
}
#endif /*LV_USE_DEMO_MUSIC*/

