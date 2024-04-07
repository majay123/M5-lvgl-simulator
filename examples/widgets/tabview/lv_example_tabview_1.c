#include "../../lv_examples.h"
#include <stdio.h>

#if LV_USE_TABVIEW && LV_BUILD_EXAMPLES

static void album_gesture_event_cb(lv_event_t * e)
{
    //检测手势
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());

    printf("========+++++++++++++dir = %d\n", dir);
    //左滑
    if(dir == LV_DIR_LEFT) 
        printf("left\n");
    //右滑
    if(dir == LV_DIR_RIGHT) 
        printf("right\n");
}


void lv_example_tabview_1(void)
{
    /*Create a Tab view object*/
    lv_obj_t *tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 50);

    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Tab 1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Tab 3");

    /*Add content to the tabs*/
    lv_obj_t * label = lv_label_create(tab1);
    lv_label_set_text(label, "This the first tab\n\n"
                             "If the content\n"
                             "of a tab\n"
                             "becomes too\n"
                             "longer\n"
                             "than the\n"
                             "container\n"
                             "then it\n"
                             "automatically\n"
                             "becomes\n"
                             "scrollable.\n"
                             "\n"
                             "\n"
                             "\n"
                             "Can you see it?");

    label = lv_label_create(tab2);
    lv_label_set_text(label, "Second tab");

    label = lv_label_create(tab3);
    lv_label_set_text(label, "Third tab");

    lv_obj_scroll_to_view_recursive(label, LV_ANIM_ON);

    lv_obj_add_event_cb(lv_scr_act(), album_gesture_event_cb, LV_EVENT_GESTURE, NULL);

    
    // lv_obj_clear_flag(tab1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // lv_obj_clear_flag(tab2, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // lv_obj_clear_flag(tab3, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // lv_obj_add_event_cb(tab1, album_gesture_event_cb, LV_EVENT_GESTURE, NULL); //手势处理，其中动画包含图片退出效果
    // lv_obj_add_event_cb(tab2, album_gesture_event_cb, LV_EVENT_GESTURE, NULL); //手势处理，其中动画包含图片退出效果
    // lv_obj_add_event_cb(tab3, album_gesture_event_cb, LV_EVENT_GESTURE, NULL); //手势处理，其中动画包含图片退出效果

}
#endif
