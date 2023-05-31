
#include "../../lv_examples.h"
#if LV_USE_FLEX && LV_BUILD_EXAMPLES

/**
 * Arrange items in rows with wrap and place the items to get even space around them.
 */
/**********************************************************************
 *Functional description:弹性布局
 *Input parameter:
 *Return:
 *Other description:
 *Modified Date       Version         Modified by      Modify Content
 *--------------------------------------------------------------------
 *2023-04-25           V1.0           RunningCode             Create
 ***********************************************************************/
void lv_example_flex_2(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_flex_flow(&style, LV_FLEX_FLOW_ROW_WRAP); // 将子孩子排成一排并包裹起来
    // 确定如何在主轴上的轨道中分布项目。
    // LV_FLEX_ALIGN_SPACE_EVENLY 项目是分布的，因此任意两个项目之间的间距（以及到边缘的空间）是相等的
    lv_style_set_flex_main_place(&style, LV_FLEX_ALIGN_SPACE_EVENLY);
    // 将项目排列成行或列
    lv_style_set_layout(&style, LV_LAYOUT_FLEX);

    lv_obj_t *cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, 300, 220);
    lv_obj_center(cont);
    lv_obj_add_style(cont, &style, 0);

    uint32_t i;
    for (i = 0; i < 15; i++)
    {
        lv_obj_t *obj = lv_obj_create(cont);
        // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
        lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);

        lv_obj_t *label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "%" LV_PRIu32, i);
        lv_obj_center(label);
    }

    lv_obj_t *obj = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text_fmt(label, "%" LV_PRIu32, i);
    lv_obj_center(label);

    lv_obj_t *obj1 = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label1 = lv_label_create(obj1);
    lv_label_set_text_fmt(label1, "%" LV_PRIu32, i);
    lv_obj_center(label1);

    lv_obj_t *obj2 = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj2, 300, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label2 = lv_label_create(obj2);
    lv_label_set_text_fmt(label2, "%" LV_PRIu32, i);
    lv_obj_center(label2);

    lv_obj_t *obj3 = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj3, 100, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj3, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label3 = lv_label_create(obj3);
    lv_label_set_text_fmt(label3, "%" LV_PRIu32, i);
    lv_obj_center(label3);

    lv_obj_t *obj4 = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj4, 100, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj4, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label4 = lv_label_create(obj4);
    lv_label_set_text_fmt(label4, "%" LV_PRIu32, i);
    lv_obj_center(label4);

    lv_obj_t *obj5 = lv_obj_create(cont);
    // LV_SIZE_CONTENT 设置为包含给定方向上的所有子控件的大小
    lv_obj_set_size(obj5, 300, LV_SIZE_CONTENT);
    lv_obj_add_flag(obj5, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_t *label5 = lv_label_create(obj5);
    lv_label_set_text_fmt(label5, "%" LV_PRIu32, i);
    lv_obj_center(label5);
}

#endif
