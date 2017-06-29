/* 
 * File:   
 * Author: Alex LeBlanc 
 * Comments: willem.jsmit@microchip.com
 * Revision history: 
 */
 
#ifndef LED_ARRAY_H //
#define	LED_ARRAY_H

#include <stdint.h>
#include <stdbool.h>

typedef struct color_t {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} color_t;

typedef struct {
    double r;       // a fraction between 0 and 1
    double g;       // a fraction between 0 and 1
    double b;       // a fraction between 0 and 1
} rgb;

typedef struct {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} hsv;

//Functions
//void initArray(color_t initToColor);

//void setXY(uint8_t x, uint8_t y, color_t setTo);
//void tempDraw(uint8_t x, uint8_t y, uint8_t setTo);
void fillScreen(color_t fillWith);
void redraw(void);
//void drawOld(uint8_t *typeArray);
void draw(color_t *typeArray);
void flashColor(color_t flashThisColor);

const color_t blank = {0,0,0};

const color_t red = {255,0,0};
const color_t grn = {0,255,0};
const color_t blu = {0,0,255};
const color_t failure = {10,10,10};

bool use_standard_colors = false;

#endif	/* LED_ARRAY_H */

