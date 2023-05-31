/*
 * @Company: HOPE
 * @Author: RunningCode
 * @Date: 2023-03-23 17:03:40
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-04-25 10:32:08
 * @Description: 
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\examples\layouts\flex\lv_example_flex_3.c
 */
#include "../../lv_examples.h"
#if LV_USE_FLEX && LV_BUILD_EXAMPLES

/**
 * Demonstrate flex grow.
 */
/**********************************************************************
*Functional description:
*Input parameter:
*Return:
*Other description:
*Modified Date       Version         Modified by      Modify Content
*--------------------------------------------------------------------
*2023-04-25           V1.0           RunningCode             Create
***********************************************************************/
void lv_example_flex_3(void)
{
    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, 300, 220);
    lv_obj_center(cont);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);

    lv_obj_t * obj;
    obj = lv_obj_create(cont);
    lv_obj_set_size(obj, 40, 40);           /*Fix size*/

    obj = lv_obj_create(cont);
    lv_obj_set_height(obj, 40);
    lv_obj_set_flex_grow(obj, 1);           /*1 portion from the free space*/

    obj = lv_obj_create(cont);
    lv_obj_set_height(obj, 40);
    lv_obj_set_flex_grow(obj, 2);           /*2 portion from the free space*/

    obj = lv_obj_create(cont);
    lv_obj_set_size(obj, 40, 40);           /*Fix size. It is flushed to the right by the "grow" items*/
}

#endif
