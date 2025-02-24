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
 * @Date         : 2024-06-12 14:10:56
 * @LastEditors  : MCD
 * @LastEditTime : 2024-06-12 14:14:58
 * @FilePath     : /M5-lvgl-simulator/examples/widgets/table/ic_lock.c
 * @Description  : 
 * 
 * ******************************************
 */

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_IC_LOCK
#define LV_ATTRIBUTE_IMG_IC_LOCK
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_IC_LOCK uint8_t ic_lock_map1[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0xb6, 0x44, 0xb6, 0xb9, 0xb6, 0xba, 0xb6, 0x46, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x92, 0x04, 0xb6, 0xad, 0x92, 0x04, 0x92, 0x04, 0xb6, 0xb1, 0x92, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0xb6, 0x26, 0xb6, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x7b, 0xb6, 0x26, 0x00, 0x00, 
  0xb6, 0x27, 0xb6, 0x81, 0xb6, 0xae, 0xb6, 0x66, 0xb6, 0x66, 0xb6, 0xae, 0xb6, 0x81, 0xb6, 0x27, 
  0xb6, 0xb4, 0xb6, 0x48, 0xb6, 0x44, 0xb6, 0x44, 0xb6, 0x44, 0xb6, 0x44, 0xb6, 0x48, 0xb6, 0xb3, 
  0xb6, 0x96, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xc4, 0xb6, 0xc2, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x96, 
  0xb6, 0x96, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x6d, 0xb6, 0x6d, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x96, 
  0xb6, 0x96, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x39, 0xb6, 0x39, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x96, 
  0xb6, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x9a, 
  0xb6, 0x94, 0xb6, 0xbc, 0xb6, 0xbb, 0xb6, 0xbb, 0xb6, 0xbb, 0xb6, 0xbb, 0xb6, 0xbc, 0xb6, 0x94, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0x9c, 0x44, 0xd3, 0x9c, 0xb9, 0xf3, 0x9c, 0xba, 0xd3, 0x9c, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x84, 0x04, 0xd3, 0x9c, 0xad, 0x10, 0x84, 0x04, 0x10, 0x84, 0x04, 0xd3, 0x9c, 0xb1, 0x10, 0x84, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xf3, 0x9c, 0x26, 0xd3, 0x9c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x7b, 0xf3, 0x9c, 0x26, 0x00, 0x00, 0x00, 
  0xd3, 0x9c, 0x27, 0xd3, 0x9c, 0x81, 0xd3, 0x9c, 0xae, 0xd3, 0x9c, 0x66, 0xd3, 0x9c, 0x66, 0xd3, 0x9c, 0xae, 0xd3, 0x9c, 0x81, 0xd3, 0x9c, 0x27, 
  0xd3, 0x9c, 0xb4, 0xd3, 0x9c, 0x48, 0xf3, 0x9c, 0x44, 0xf3, 0x9c, 0x44, 0xf3, 0x9c, 0x44, 0xf3, 0x9c, 0x44, 0xd3, 0x9c, 0x48, 0xd3, 0x9c, 0xb3, 
  0xd3, 0x9c, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0x9c, 0xc4, 0xd3, 0x9c, 0xc2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x96, 
  0xd3, 0x9c, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x6d, 0xd3, 0x9c, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x96, 
  0xd3, 0x9c, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x39, 0xd3, 0x9c, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x96, 
  0xd3, 0x9c, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x9a, 
  0xd3, 0x9c, 0x94, 0xd3, 0x9c, 0xbc, 0xd3, 0x9c, 0xbb, 0xd3, 0x9c, 0xbb, 0xd3, 0x9c, 0xbb, 0xd3, 0x9c, 0xbb, 0xd3, 0x9c, 0xbc, 0xd3, 0x9c, 0x94, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xf3, 0x44, 0x9c, 0xd3, 0xb9, 0x9c, 0xf3, 0xba, 0x9c, 0xd3, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x84, 0x10, 0x04, 0x9c, 0xd3, 0xad, 0x84, 0x10, 0x04, 0x84, 0x10, 0x04, 0x9c, 0xd3, 0xb1, 0x84, 0x10, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x9c, 0xf3, 0x26, 0x9c, 0xd3, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x7b, 0x9c, 0xf3, 0x26, 0x00, 0x00, 0x00, 
  0x9c, 0xd3, 0x27, 0x9c, 0xd3, 0x81, 0x9c, 0xd3, 0xae, 0x9c, 0xd3, 0x66, 0x9c, 0xd3, 0x66, 0x9c, 0xd3, 0xae, 0x9c, 0xd3, 0x81, 0x9c, 0xd3, 0x27, 
  0x9c, 0xd3, 0xb4, 0x9c, 0xd3, 0x48, 0x9c, 0xf3, 0x44, 0x9c, 0xf3, 0x44, 0x9c, 0xf3, 0x44, 0x9c, 0xf3, 0x44, 0x9c, 0xd3, 0x48, 0x9c, 0xd3, 0xb3, 
  0x9c, 0xd3, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xf3, 0xc4, 0x9c, 0xd3, 0xc2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x96, 
  0x9c, 0xd3, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x6d, 0x9c, 0xd3, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x96, 
  0x9c, 0xd3, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x39, 0x9c, 0xd3, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x96, 
  0x9c, 0xd3, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x9a, 
  0x9c, 0xd3, 0x94, 0x9c, 0xd3, 0xbc, 0x9c, 0xd3, 0xbb, 0x9c, 0xd3, 0xbb, 0x9c, 0xd3, 0xbb, 0x9c, 0xd3, 0xbb, 0x9c, 0xd3, 0xbc, 0x9c, 0xd3, 0x94, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x9a, 0x9a, 0x44, 0x99, 0x99, 0x99, 0xb9, 0x9a, 0x9a, 0x9a, 0xba, 0x99, 0x99, 0x99, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x04, 0x99, 0x99, 0x99, 0xad, 0x80, 0x80, 0x80, 0x04, 0x80, 0x80, 0x80, 0x04, 0x99, 0x99, 0x99, 0xb1, 0x80, 0x80, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x9a, 0x9a, 0x9a, 0x26, 0x98, 0x98, 0x98, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x7b, 0x9a, 0x9a, 0x9a, 0x26, 0x00, 0x00, 0x00, 0x00, 
  0x96, 0x96, 0x96, 0x27, 0x98, 0x98, 0x98, 0x81, 0x98, 0x98, 0x98, 0xae, 0x99, 0x99, 0x99, 0x66, 0x99, 0x99, 0x99, 0x66, 0x98, 0x98, 0x98, 0xae, 0x98, 0x98, 0x98, 0x81, 0x96, 0x96, 0x96, 0x27, 
  0x99, 0x99, 0x99, 0xb4, 0x98, 0x98, 0x98, 0x48, 0x9a, 0x9a, 0x9a, 0x44, 0x9a, 0x9a, 0x9a, 0x44, 0x9a, 0x9a, 0x9a, 0x44, 0x9a, 0x9a, 0x9a, 0x44, 0x98, 0x98, 0x98, 0x48, 0x98, 0x98, 0x98, 0xb3, 
  0x99, 0x99, 0x99, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x9a, 0x9a, 0xc4, 0x98, 0x98, 0x98, 0xc2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x96, 
  0x99, 0x99, 0x99, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x98, 0x98, 0x6d, 0x98, 0x98, 0x98, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x96, 
  0x99, 0x99, 0x99, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x98, 0x98, 0x39, 0x98, 0x98, 0x98, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x96, 
  0x98, 0x98, 0x98, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x98, 0x98, 0x9a, 
  0x99, 0x99, 0x99, 0x94, 0x99, 0x99, 0x99, 0xbc, 0x99, 0x99, 0x99, 0xbb, 0x99, 0x99, 0x99, 0xbb, 0x99, 0x99, 0x99, 0xbb, 0x99, 0x99, 0x99, 0xbb, 0x99, 0x99, 0x99, 0xbc, 0x99, 0x99, 0x99, 0x94, 
#endif
};

const lv_img_dsc_t ic_lock1 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 8,
  .header.h = 10,
  .data_size = 80 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = ic_lock_map1,
};
