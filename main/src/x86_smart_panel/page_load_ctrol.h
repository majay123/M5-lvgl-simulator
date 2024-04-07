#ifndef __PAGE_LOAD_CTROL_H__
#define __PAGE_LOAD_CTROL_H__

#define TAG       "ui"
#define LOGI(...) printf(TAG, ##__VA_ARGS__)
#define LOGW(...) printf(TAG, ##__VA_ARGS__)
#define LOGE(...) printf(TAG, ##__VA_ARGS__)
#define LOGD(...) printf(TAG, ##__VA_ARGS__)

#include "lvgl.h"

void ui_event_UiPage6_screen(lv_event_t *e);
void hor_page_load_main(void);
void ui_tabview_set(uint32_t id);

#endif
