

#include "mcc_generated_files/mcc.h"
#include "LED_Array.h"
#include "math.h"

#define NUM_OF_LEDS 192

color_t colorBuffer[NUM_OF_LEDS];
float redd, grnn, bluu;
float kelv;

//static hsv   rgb2hsv(rgb in);
//static rgb   hsv2rgb(hsv in);

void initArray(color_t initTo){
    for(uint8_t i = 0; i < NUM_OF_LEDS; i++){
        colorBuffer[i] = initTo;
    }
}

void enterSendMode(void){
    LED_CS_SetLow();
}

void exitSendMode(void){
    
    LED_CS_SetHigh();
}

void sendColor(color_t color){
    SSP1BUF = color.g; //Green
    while (!SSP1STATbits.BF);
    SSP1BUF = color.r; //Red
    while (!SSP1STATbits.BF); 
    SSP1BUF = color.b; //Blue 
    while (!SSP1STATbits.BF);
}

void redraw(void){
    draw(colorBuffer);
}

void flashColor(color_t flashThisColor){
    for(uint8_t i = 0; i < 10; i++){
        fillScreen(flashThisColor);
        __delay_ms(20);
        fillScreen(blank);
        __delay_ms(80);
    }
}

void fillScreen(color_t fillWith){
    enterSendMode();
    for(uint8_t i = 0; i < NUM_OF_LEDS; i++){
        sendColor(fillWith);
    }
    exitSendMode();
}

void draw(color_t *typeArray) {
    //Write WS2812 LEDS
    enterSendMode();
    
    for (uint8_t i = 0; i < NUM_OF_LEDS; i++) {
        sendColor(typeArray[i]);
    }
    __delay_ms(20);
    exitSendMode();
}

float temperature(kelv){

kelv = kelv / 100;
 //Calculate Red
 if (kelv <= 66) {
     redd = 255;
 }
 else {
     redd = kelv-55; //-55
     redd = 351.97690566805693 + (redd*0.114206453784165) + ((-40.25366309332127)*log(redd));

    if (redd < 0) {
       redd = 0;
    }
    if (redd > 255) {
         redd = 255;
    }
 }
//    Calculate Green:
if (kelv <= 66) {
    grnn = kelv-2;
    grnn = (-155.25485562709179)+((-0.44596950469579133)*grnn)+(104.49216199393888 * log(grnn));
    if (grnn < 0) {
        grnn = 0;
    }
    if (grnn > 255) {
        grnn = 255;
    }
}
else {
    grnn = kelv - 50; //-
    grnn = (325.4494125711974)+((0.07943456536662342)*grnn)+((-28.0852963507957)*log(grnn));
    if (grnn < 0) {
        grnn = 0;
    }
    if (grnn > 255) {
        grnn = 255;
    }
}
//    Calculate Blue:
if (kelv >= 66) {
    bluu = 255;
}
else {
    if (kelv <= 19) {
        bluu = 0;
    }
    else {
        bluu = kelv - 10;
        bluu = (-254.76935184120902)+(0.8274096064007395*bluu)+(115.67994401066147*log(bluu));
        if (bluu < 0) {
            bluu = 0;
        }
        if (bluu > 255) {
            bluu = 255;
        }
    }
}
return redd, grnn, bluu;
}


hsv rgb2hsv(rgb in)
{
    hsv         out;
    double      min, max, delta;

    min = in.r < in.g ? in.r : in.g;
    min = min  < in.b ? min  : in.b;

    max = in.r > in.g ? in.r : in.g;
    max = max  > in.b ? max  : in.b;

    out.v = max;                                // v
    delta = max - min;
    if (delta < 0.00001)
    {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }
    if( max > 0.0 ) { // NOTE: if Max is == 0, this divide would cause a crash
        out.s = (delta / max);                  // s
    } else {
        // if max is 0, then r = g = b = 0              
        // s = 0, v is undefined
        out.s = 0.0;
        //out.h= NAN;                            // its now undefined
        return out;
    }
    if( in.r >= max )                           // > is bogus, just keeps compilor happy
        out.h = ( in.g - in.b ) / delta;        // between yellow & magenta
    else
    if( in.g >= max )
        out.h = 2.0 + ( in.b - in.r ) / delta;  // between cyan & yellow
    else
        out.h = 4.0 + ( in.r - in.g ) / delta;  // between magenta & cyan

    out.h *= 60.0;                              // degrees

    if( out.h < 0.0 )
        out.h += 360.0;

    return out;
}


rgb hsv2rgb(hsv in)
{
    double      hh, p, q, t, ff;
    long        i;
    rgb         out;

    if(in.s <= 0.0) {       // < is bogus, just shuts up warnings
        out.r = in.v;
        out.g = in.v;
        out.b = in.v;
        return out;
    }
    hh = in.h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = in.v * (1.0 - in.s);
    q = in.v * (1.0 - (in.s * ff));
    t = in.v * (1.0 - (in.s * (1.0 - ff)));

    switch(i) {
    case 0:
        out.r = in.v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = in.v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = in.v;
        out.b = t;
        break;

    case 3:
        out.r = p;
        out.g = q;
        out.b = in.v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = in.v;
        break;
    case 5:
    default:
        out.r = in.v;
        out.g = p;
        out.b = q;
        break;
    }
    return out;     
}


/**
 End of File
 */
