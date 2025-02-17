#include "../../lv_examples.h"
#if LV_USE_TABLE && LV_BUILD_EXAMPLES

#define ITEM_CNT 20

LV_IMG_DECLARE(ic_wifi11);
LV_IMG_DECLARE(ic_wifi21);
LV_IMG_DECLARE(ic_wifi31);
LV_IMG_DECLARE(ic_lock1);

char ssid[20] = {1,2,3,3,2,3,1,2,3,2,
                 1,2,3,3,1,3,2,1,1,3};

#if 0
static void draw_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    /*If the cells are drawn...*/
    if(dsc->part == LV_PART_ITEMS) {
        bool chk = lv_table_has_cell_ctrl(obj, dsc->id, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);

        lv_draw_rect_dsc_t rect_dsc;
        lv_draw_rect_dsc_init(&rect_dsc);
        rect_dsc.bg_color = chk ? lv_theme_get_color_primary(obj) : lv_palette_lighten(LV_PALETTE_GREY, 2);
        rect_dsc.radius = LV_RADIUS_CIRCLE;

        lv_area_t sw_area;
        sw_area.x1 = dsc->draw_area->x2 - 50;
        sw_area.x2 = sw_area.x1 + 40;
        sw_area.y1 = dsc->draw_area->y1 + lv_area_get_height(dsc->draw_area) / 2 - 10;
        sw_area.y2 = sw_area.y1 + 20;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area);

        rect_dsc.bg_color = lv_color_white();
        if(chk) {
            sw_area.x2 -= 2;
            sw_area.x1 = sw_area.x2 - 16;
        }
        else {
            sw_area.x1 += 2;
            sw_area.x2 = sw_area.x1 + 16;
        }
        sw_area.y1 += 2;
        sw_area.y2 -= 2;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area);
    }
}
#else
static void draw_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    lv_obj_t *tab = lv_event_get_user_data(e);
    uint16_t row = lv_table_get_row_cnt(tab);

    // printf("row = %d\n", row);

    /*If the cells are drawn...*/
    if(dsc->part == LV_PART_ITEMS) {
        
        // lv_table_get_selected_cell(obj, &row, &col);
        bool chk = lv_table_has_cell_ctrl(obj, dsc->id, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        // printf("row = %d, col = %d, id = %d\n", row, col, dsc->id);
#if 1
        lv_draw_rect_dsc_t rect_dsc;
        lv_draw_rect_dsc_init(&rect_dsc);
        rect_dsc.bg_color = chk ? /* lv_theme_get_color_primary(obj) */lv_color_make(0xf6, 0x8f, 0x3b) : lv_palette_lighten(LV_PALETTE_GREY, 2);
        rect_dsc.radius = LV_RADIUS_CIRCLE;

        lv_area_t sw_area;
        sw_area.x1 = dsc->draw_area->x2 - 55;
        sw_area.x2 = sw_area.x1 + 45;
        sw_area.y1 = dsc->draw_area->y1 + lv_area_get_height(dsc->draw_area) / 2 - 10;
        sw_area.y2 = sw_area.y1 + 25;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area);  // 画矩形

        rect_dsc.bg_color = lv_color_white();
        if(chk) {
            sw_area.x2 -= 2;
            sw_area.x1 = sw_area.x2 - 16;
        }
        else {
            sw_area.x1 += 2;
            sw_area.x2 = sw_area.x1 + 16;
        }
        sw_area.y1 += 4;
        sw_area.y2 -= 4;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area); // 画圆
#else
        lv_img_header_t header;
        lv_res_t res = lv_img_decoder_get_info(&ic_wifi31, &header);

        if(res != LV_RES_OK) {
            printf("res = %d\n", res);
            return;
        }

        lv_draw_img_dsc_t img_draw_dsc;
        lv_draw_img_dsc_init(&img_draw_dsc);

        lv_area_t a;
        a.x1 = dsc->draw_area->x1 + (lv_area_get_width(dsc->draw_area) - header.w) / 2 + 100;
        a.x2 = a.x1 + header.w - 1;
        a.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - header.h) / 2;
        a.y2 = a.y1 + header.h - 1;
        switch(ssid[dsc->id]) {
            case 1:
                lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ic_wifi11);
                break;
            case 2:
                lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ic_wifi21);
                break;
            case 3:
                lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ic_wifi31);
                break;
            default:
                break;
        }

        // lv_img_header_t header;
        lv_memset_00(&header, sizeof(lv_img_header_t));
        res = lv_img_decoder_get_info(&ic_lock1, &header);

        if(res != LV_RES_OK) {
            printf("res = %d\n", res);
            return;
        }

        lv_draw_img_dsc_init(&img_draw_dsc);

        // lv_area_t a;
        lv_memset_00(&a, sizeof(lv_area_t));
        a.x1 = dsc->draw_area->x1 + (lv_area_get_width(dsc->draw_area) - header.w) / 2  + 120;
        a.x2 = a.x1 + header.w - 1 ;
        a.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - header.h) / 2;
        a.y2 = a.y1 + header.h - 1;

        // printf("x1: %d, y1: %d, x2: %d, y2: %d\n", a.x1, a.y1, a.x2, a.y2);

        lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ic_lock1);
#endif
    }
}
#endif

static void change_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    uint16_t col;
    uint16_t row;
    lv_obj_t *tab = lv_event_get_user_data(e);
    lv_table_get_selected_cell(obj, &row, &col);
    bool chk = lv_table_has_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    printf("chk = %d, row = %d\n", chk, row);
        
    if(chk) lv_table_clear_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    else lv_table_add_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
}

static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *tab = lv_event_get_user_data(e);


    if (code == LV_EVENT_VALUE_CHANGED) {
        // lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
        // printf("%d, %d\n", dsc->draw_area->x2 - dsc->draw_area->x1, dsc->draw_area->y2 - dsc->draw_area->y1);

        bool state = lv_obj_has_state(obj, LV_STATE_CHECKED);
        LV_LOG_USER("State: %s\n", state ? "On" : "Off");
        if (!state) {
            // lv_obj_clean(tab);
            lv_obj_add_flag(tab, LV_OBJ_FLAG_HIDDEN);
            printf("clean table\n");
        }
        else {
            lv_obj_clear_flag(tab, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

/**
 * A very light-weighted list created from table
 */
void lv_example_table_2(void)
{
    /*Measure memory usage*/
    lv_mem_monitor_t mon1;
    lv_mem_monitor(&mon1);

    uint32_t t = lv_tick_get();

    lv_obj_t * table = lv_table_create(lv_scr_act());
    
    // 不显示滚动条
    lv_obj_set_scrollbar_mode(table, LV_SCROLLBAR_MODE_OFF);

    /*Set a smaller height to the table. It'll make it scrollable*/
    lv_obj_set_size(table, 300, 390);

    lv_table_set_col_width(table, 0, 300);
    lv_table_set_row_cnt(table, ITEM_CNT); /*Not required but avoids a lot of memory reallocation lv_table_set_set_value*/
    lv_table_set_col_cnt(table, 1);

    /*Don't make the cell pressed, we will draw something different in the event*/
    lv_obj_remove_style(table, NULL, LV_PART_ITEMS | LV_STATE_PRESSED);

    lv_obj_set_style_text_color(table, lv_color_hex(0xFFFFFF),  LV_STATE_DEFAULT | LV_PART_ITEMS);
    lv_obj_set_style_text_color(table, lv_color_hex(0xFFFFFF),  LV_STATE_PRESSED | LV_PART_ITEMS);
    lv_obj_set_style_text_color(table, lv_color_hex(0xFFFFFF),  LV_STATE_FOCUS_KEY | LV_PART_ITEMS);
    // lv_obj_set_style_bg_color(table, lv_color_hex(0x000000),   LV_STATE_DEFAULT | LV_PART_ITEMS);
    // lv_obj_set_style_bg_color(table, lv_color_hex(0x000000), LV_PART_ITEMS | LV_STATE_PRESSED);
    // lv_obj_set_style_bg_color(table, lv_color_hex(0x000000), LV_PART_ITEMS | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_bg_color(table, lv_color_hex(0x030303),   LV_STATE_DEFAULT | LV_PART_ITEMS);
    lv_obj_set_style_bg_color(table, lv_color_hex(0x757070), LV_PART_ITEMS | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(table, lv_color_hex(0x757070), LV_PART_ITEMS | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_bg_opa(table, 255, LV_PART_SELECTED| LV_STATE_DEFAULT);

    lv_obj_set_style_border_width(table, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    char *buf = "Item 11";
    uint32_t i;
    for(i = 0; i < ITEM_CNT; i++) {
        lv_table_set_cell_value_fmt(table, i, 0, "Item %"LV_PRIu32/* "\nconnected" */, i + 1);
        lv_table_add_cell_ctrl(table, i, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);

    }

    lv_obj_align(table, LV_ALIGN_CENTER, 0, -20);

    /*Add an event callback to to apply some custom drawing*/
    lv_obj_add_event_cb(table, draw_event_cb, LV_EVENT_DRAW_PART_END, table);
    lv_obj_add_event_cb(table, change_event_cb, LV_EVENT_VALUE_CHANGED, table);

    lv_mem_monitor_t mon2;
    lv_mem_monitor(&mon2);

    uint32_t mem_used = mon1.free_size - mon2.free_size;

    uint32_t elaps = lv_tick_elaps(t);

    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(label, "%"LV_PRIu32" items were created in %"LV_PRIu32" ms\n"
                          "using %"LV_PRIu32" bytes of memory",
                          ITEM_CNT, elaps, mem_used);

    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -10);


    lv_obj_t * ui_Switch1 = lv_switch_create(lv_scr_act());
    lv_obj_set_width( ui_Switch1, 50);
    lv_obj_set_height( ui_Switch1, 25);
    lv_obj_set_x( ui_Switch1, 0 );
    lv_obj_set_y( ui_Switch1, 0 );
    // lv_obj_set_align( ui_Switch1, LV_ALIGN_CENTER );
    lv_obj_add_event_cb(ui_Switch1, event_handler, LV_EVENT_ALL, table);

}

#endif
