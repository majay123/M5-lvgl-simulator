// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.3
// Project name: AiotArc

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

// IMAGE DATA: assets\voice_symbol.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_voice_symbol_png_data[] = {
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x83,0x7A,0x6E,0xA3,0x82,0x6D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x06,0x44,0xA3,0x81,0x84,0xE4,0xF3,0x24,0xFD,0x64,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x63,0x72,0x45,0xE4,0xC3,0xC3,0xC5,0xEC,0xFF,0x05,0xFD,0xFF,0x05,0xFD,0x5C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x01,0x00,0x05,0x63,0x39,0x2E,0x63,0x82,0x03,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x61,0x10,0x0B,0x44,0xA3,0x87,0x65,0xE4,0xF7,0xE5,0xFC,0xFF,0x05,0xFD,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xC3,0x82,0x2D,0x44,0xCC,0xE5,0xE3,0xBB,0xC0,0x02,0x00,0x22,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xC4,0x92,0x35,0x05,0xCC,0xBC,0xA5,0xF4,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x63,0xA3,0x64,0xE4,0xEC,0xFF,0x24,0xFD,0xFF,0xA3,0xB3,0xB5,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x02,0x00,0x0D,0x85,0xBB,0x7F,0x45,0xE4,0xF5,0xC6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC5,0xFC,0xFF,0xC5,0xFC,0xFF,0xC5,0xFC,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0x5F,0xFF,0xFF,0x00,0xC2,0x28,0x07,0x83,0x7A,0x7D,0x44,0x9B,0x0F,0xFF,0xFF,0x00,0x03,0x62,0x0E,0xA3,0xBB,0x95,0xE4,0xEC,0xFF,0x44,0xFD,0xF5,0x83,0xAB,0x7E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x44,0x72,0x0F,0x06,0xAB,0x0F,0x05,0xAB,0x0F,0x05,0xAB,0x0F,0x05,0xAB,0x0F,0x25,0xA3,0x0F,0x05,0xA3,0x0F,0x64,0x7A,0x3E,0x06,0xDC,0xBF,0x86,0xF4,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0xFF,
    0xA6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC5,0xFC,0xFF,0xE5,0xFC,0xFF,0xE5,0xFC,0x5F,0xFF,0xFF,0x00,0xE4,0xC3,0x70,0x64,0xE4,0xFF,0xC4,0xC3,0xAB,0x00,0x00,0x06,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x04,0xC4,0xA5,0x24,0xFD,0xFF,0x64,0xD4,0xFF,0x63,0x72,0x39,0xFF,0xFF,0x00,0xE5,0x9A,0xEC,0x07,0xE4,0xEC,0x07,0xE4,0xEC,0x07,0xE4,0xEC,0x06,0xE4,0xEC,0x06,0xE4,0xEB,0x26,0xE4,0xEC,0x46,0xEC,0xFB,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC5,0xFC,0xFF,0xC5,0xFC,0xFF,0xC5,0xFC,0x5F,0xFF,0xFF,0x00,0x24,0xDC,0x6B,0x05,0xFD,0xF7,0xC5,0xF4,0xFF,0xA4,0xB3,0x76,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xA3,0x49,0x31,0x84,0xDC,0xE4,0x44,0xFD,0xFF,0x83,0xAB,0xA1,0x01,0x00,0x07,0x26,0xB3,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0xFF,
    0xC6,0xFC,0xFF,0xC6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x64,0xAB,0x94,0xC5,0xF4,0xFF,0xC5,0xF4,0xE8,0x63,0x72,0x44,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xC4,0xBB,0x60,0x24,0xF5,0xFF,0x64,0xCC,0xF4,0x42,0x41,0x41,0x26,0xB3,0xFF,0x68,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x02,0x00,0x12,0x45,0xDC,0xC6,0xE5,0xFC,0xFF,0x04,0xCC,0x9D,0x00,0x00,0x01,0xFF,0xFF,0x00,0x43,0x41,0x2D,0xA4,0xE4,0xEB,0x04,0xFD,0xFF,0x24,0xC4,0x4B,0x06,0xB3,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xC6,0xFC,0xFF,0xC6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0x44,0xAB,0x7E,0xA5,0xEC,0xFF,0x85,0xEC,0xD6,0x44,0x6A,0x11,0xFF,0xFF,0x00,0x62,0x08,0x07,0x04,0xCC,0xBB,0x04,0xFD,0xFF,0x63,0xA3,0xDE,0x06,0xB3,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xC4,0x8A,0x30,0xA5,0xF4,0xEC,0xC5,0xF4,0xF5,0x24,0xA3,0x49,0xFF,0xFF,0x00,0x00,0x00,0x0D,0xC3,0x8A,0xCB,0x04,0xFD,0xFF,0x04,0xCC,0xFF,0x06,0xB3,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x68,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x64,0x7A,0x10,0x65,0xE4,0xDA,0xA5,0xE4,0xFF,
    0x64,0x7A,0x99,0xFF,0xFF,0x00,0x01,0x00,0x02,0xE4,0x92,0x9C,0x05,0xFD,0xFF,0x84,0xE4,0xFF,0x06,0xB3,0xFF,0x28,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0xFF,0xA6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xC3,0x51,0x1B,0x25,0xDC,0xDF,0x85,0xE4,0xFF,0x84,0x7A,0x99,0xFF,0xFF,0x00,0x00,0x00,0x02,0x04,0x93,0x9C,0xE5,0xFC,0xFF,0x64,0xE4,0xFF,0x06,0xB3,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0x86,0xFC,0xFF,0xA6,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xE5,0xD3,0x11,0xA5,0xF4,0xE3,0xC5,0xF4,0xF6,0x64,0xA3,0x46,0xFF,0xFF,0x00,0x01,0x00,0x0D,0x04,0x93,0xCB,
    0xE5,0xFC,0xFF,0xC4,0xBB,0xFF,0x07,0xB3,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x86,0xFC,0xFF,0x86,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x45,0xAB,0x5A,0xA6,0xF4,0xF9,0x45,0xE4,0xEA,0x24,0x93,0x1D,0xFF,0xFF,0x00,0x43,0x41,0x05,0x45,0xE4,0xBB,0xE5,0xFC,0xFF,0x04,0x93,0xDF,0xE7,0xB2,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x85,0xBB,0xCA,0xC6,0xFC,0xFF,0xE5,0xCB,0xBB,0x00,0x00,0x0A,0xFF,0xFF,0x00,0x43,0x72,0x2A,0xA5,0xF4,0xEB,0xA5,0xEC,0xFF,0x24,0xA3,0x4B,0x07,0xB3,0xFF,0x29,0xFC,0xFF,
    0x29,0xFC,0xFF,0x28,0xFC,0xFF,0x28,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0xFF,0x87,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xE5,0x9A,0x6C,0x86,0xEC,0xFF,0x46,0xEC,0xFF,0x64,0x7A,0x80,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x64,0xB3,0x9F,0xE5,0xFC,0xFF,0x25,0xD4,0xD4,0x03,0x31,0x22,0xA6,0xA2,0xEC,0xC8,0xEB,0xEC,0xC8,0xE3,0xEC,0xC8,0xE3,0xEC,0xC8,0xE3,0xEC,0xC8,0xE3,0xEB,0xC8,0xE3,0xEC,0x08,0xEC,0xFC,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x87,0xFC,0x5F,0xFF,0xFF,0x00,0xE5,0xA2,0x64,0x06,0xDC,0xFD,0xE7,0xFC,0xFF,0x65,0xBB,0xB9,0x01,0x00,0x10,0xFF,0xFF,0x00,0xC4,0x92,0x3F,0x65,0xEC,0xFE,0xA5,0xFC,0xFF,0xA5,0xC3,0x66,0xFF,0xFF,0x00,0x25,0x7A,0x0F,0xE7,0xB2,0x0F,0xE7,0xB2,0x0F,0xE7,0xB2,0x0F,0x07,0xB3,0x0F,0x06,0xB3,0x0F,
    0xC6,0xAA,0x0F,0x25,0x72,0x53,0x26,0xB3,0xE5,0x28,0xF4,0xFF,0x68,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0x5F,0xFF,0xFF,0x00,0xA6,0xCB,0xA7,0xA7,0xFC,0xFF,0x65,0xBB,0xF7,0xE3,0x30,0x41,0xFF,0xFF,0x00,0x42,0x08,0x3D,0x85,0xBB,0xE9,0xE6,0xFC,0xFF,0x05,0xD4,0xE1,0x83,0x41,0x17,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x01,0x00,0x1B,0x47,0xBB,0x7D,0xE7,0xE3,0xF5,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0x5F,0xFF,0xFF,0x00,0xC5,0x92,0x20,0xE5,0xA2,0xBF,0x83,0x49,0x5D,0xFF,0xFF,0x00,0xE3,0x61,0x34,0x25,0xAB,0xE4,0xE6,0xFC,0xFF,0x26,0xDC,0xFF,0x44,0x72,0x6B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xA5,0x9A,0x35,0xA7,0xD3,0xBC,0x28,0xF4,0xFF,0x68,0xFC,0xFF,0x48,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0xFF,0x67,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x06,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x05,0xAB,0x78,0x86,0xF4,0xFF,0x86,0xEC,0xFF,0x05,0xA3,0x7D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x82,0x18,0x0B,0xE6,0xAA,0x87,0xE7,0xE3,0xF7,0x48,0xFC,0xFF,0x68,0xFC,0xFF,0x47,0xFC,0xFF,0x67,0xFC,0x5F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x86,0xCB,0x17,0xA6,0xC3,0xBE,0x05,0xA3,0x8B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x45,0x7A,0x45,
    0x87,0xCB,0xC3,0x28,0xEC,0xFF,0x68,0xFC,0xFF,0x48,0xFC,0x5C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x09,0x00,0x00,0x05,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x06,0xE6,0xAA,0x81,0xE7,0xE3,0xF3,0x68,0xFC,0x64,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x45,0x7A,0x6E,0x65,0x82,0x6D,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
};
const lv_img_dsc_t ui_img_voice_symbol_png = {
    .header.always_zero = 0,
    .header.w = 30,
    .header.h = 26,
    .data_size = sizeof(ui_img_voice_symbol_png_data),
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = ui_img_voice_symbol_png_data
};
