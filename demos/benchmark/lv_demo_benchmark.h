/*
 * @Company: Hope
 * @Author: RunningCode
 * @Date: 2023-03-23 17:03:40
 * @LastEditors: RunningCode
 * @LastEditTime: 2023-03-31 15:59:14
 * @Description: 
 * @Email: 547387405@qq.cn
 * @FilePath: \lvgl\demos\benchmark\lv_demo_benchmark.h
 */
/**
 * @file lv_demo_benchmark.h
 *
 */

#ifndef LV_DEMO_BENCHMARK_H
#define LV_DEMO_BENCHMARK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "../lv_demos.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_demo_benchmark(void);

void lv_demo_benchmark_run_scene(int_fast16_t scene_no);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_DEMO_BENCHMARK_H*/
