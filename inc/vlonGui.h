/**
 * @file vlonGui.h
 * @author Weilong Shen (valonshen@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-06
 * 
 * Copyright © 2019-2021 Weilong Shen (valonshen@foxmail.com).
 * All rights reserved.
 * 
 */
#ifndef _VLONGUI_H_
#define _VLONGUI_H_

#include <stdint.h>
#include "vlonGui_window.h"
#include "vlonGui_base.h"
#include "vlonGui_fonts.h"


#define VLGUI_ASSERT(cons)  
#define VLGUI_MIN(a,b)          (a > b ? b : a)
#define VLGUI_MAX(a,b)          (a > b ? a : b)

/*
 * Config Macro
 */

/* Enable animation feature for window */
#define LVGUI_ANIMATION                 (1)

/* The number of key can be enqueued */
#define LVGUI_KEY_MAX_NUM               (10)

/* 
 * Declaration 
 */ 
typedef uint8_t     vlonGui_color;

typedef void (* displayInit_func_t)(void);
typedef void (* displayFresh_func_t)(void);
typedef void (* drawBlock_func_t)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t color);
typedef void (* drawPoint_func_t)(uint16_t x, uint16_t y, uint8_t color);
typedef void (* drawLineH_func_t)(uint16_t x, uint16_t y, uint16_t length, uint16_t width, uint8_t color);
typedef void (* drawLineV_func_t)(uint16_t x, uint16_t y, uint16_t length, uint16_t width, uint8_t color);
typedef void (* drawBitmap_func_t)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t *bitmap);

struct vlonGui_driver_t {
    displayInit_func_t  pInit;
    displayFresh_func_t pFresh;
    drawBlock_func_t    pDrawBlock;
    drawPoint_func_t    pDrawPoint;
    drawLineH_func_t    pDrawLineH;
    drawLineV_func_t    pDrawLineV;
    drawBitmap_func_t   pDrawBitmap;
};

struct vlonGui_t {
    uint8_t fresh;
    int16_t width;
    int16_t height;
    struct vlonGui_font_t *curFont;
    struct vlonGui_driver_t *displayDriver;
    struct vlonGui_window_t *window;
};


extern struct vlonGui_t *vlonGui_cur_screen;

void * vlonGui_malloc(uint32_t size);

uint32_t vlonGui_getTime(void);

int vlonGui_screen_init(struct vlonGui_t *screen, int16_t width, int16_t height);

void vlonGui_register_driver(struct vlonGui_t *screen, struct vlonGui_driver_t *driver);

struct vlonGui_window_t * vlinGui_getMainWindow(struct vlonGui_t *screen);

void vlonGui_refresh(void);

struct vlonGui_driver_t * vlonGui_portGetDriver(void);

void vlonGui_setFont(struct vlonGui_font_t *font);
#endif