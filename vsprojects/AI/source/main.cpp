#include <cmath>
#include <ctime>
#include <ccon.h>
#include <iostream>
#include <Windows.h>
#include "draw.h"
#include "util.h"

//https://en.wikipedia.org/wiki/HSL_and_HSV
//https://stackoverflow.com/questions/2353211/hsl-to-rgb-color-conversion
//https://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another
//https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
//https://www.google.com.au/search?q=c%2B%2B+interpolate+between+2+colours&oq=c%2B%2B+interpolate+between+2+colours&gs_l=serp.3...105210.116945.0.117081.41.37.3.0.0.0.297.4753.0j19j6.25.0....0...1.1.64.serp..13.24.3997...0j0i67k1j0i10i67k1j0i131k1j0i10k1j0i22i30k1j33i160k1j33i21k1j30i10k1.lpcVdyxoNQs

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif
#ifndef max
#define max(a,b) (a > b ? a : b)
#endif
#ifndef abs
#define abs(a) (a < 0 ? -a : a)
#endif

#define APP_WIDTH 40
#define APP_HEIGHT 40

struct Color { float r, g, b, a; };

unsigned char colourA(float a)
{
    // calculate alpha index
    unsigned int index = int(a * 5);
    // return ascii character
    return (index == 0 ? 0x00 : (index > 3 ? 0xdb : 0xb0 + index - 1));
}
unsigned char colourRGB(int r, int g, int b)
{
    // calculate bright bit
    int index = (r > 128 | g > 128 | b > 128) ? 8 : 0;
    // calculate console colours
    index |= r > 84 ? 4 : 0;
    index |= g > 84 ? 2 : 0;
    index |= b > 84 ? 1 : 0;
    // return attribute colour index
    return (unsigned char) index;
}



void colour(float r, float g, float b, float a, int index)
{
    // print color on screen
    ccon::cconAscii(colourA(a), index);
    ccon::cconAttrib(colourRGB(int(r * 255 + 0.5f), int(g * 255 + 0.5f), int(b * 255 + 0.5f)), index);
    //ccon::cconDrawBuffer();
}

Color LerpRGB(Color a, Color b, float t)
{
    return Color {
        a.r + (b.r - a.r) * t,
        a.g + (b.g - a.g) * t,
        a.b + (b.b - a.b) * t,
        a.a + (b.a - a.a) * t
    };
}


void drawLine(Color & color1, Color & color2, int line)
{
    int index = line * APP_WIDTH;
    Color color = { color1.r, color1.g, color1.b, color1.a };
    Color delta = {
        (color2.r - color1.r) / (APP_WIDTH - 1),
        (color2.g - color1.g) / (APP_WIDTH - 1),
        (color2.b - color1.b) / (APP_WIDTH - 1),
        (color2.a - color1.a) / (APP_WIDTH - 1)
    };
    // draw line
    for (int i = 0; i < APP_WIDTH; i++)
    {
        colour(color.r, color.g, color.b, color.a, index++);
        
        color.r += delta.r;
        color.g += delta.g;
        color.b += delta.b;
        color.a += delta.a;
    }

    //float time = 0;
    //float delta = 1.f / (APP_WIDTH);
    //int index = line * APP_WIDTH;
    //// draw line
    //for (int i = 0; i < APP_WIDTH; i++)
    //{
    //    Color color = LerpRGB(color1, color2, time);
    //    time += delta;
    //}
}



void main()
{
    float buffer1[6] = { 0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f };
    float buffer2[6] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };

    util::Collection<float> collection1(buffer1, sizeof(buffer1) / sizeof(float));
    util::Collection<float> collection2(buffer2, sizeof(buffer2) / sizeof(float));
    
    //collection2.remove(0);
    //collection2.remove(5);
    //collection2.remove(1);
    //collection2.remove(4);
    //collection2.remove(2);
    //collection2.remove(3);

    if (!collection2.remove(collection1)) std::cout << "failed to remove collection!\n";

    ccon::cconInit();
    ccon::cconSize(APP_WIDTH, APP_HEIGHT);
    ccon::cconViewport(0, 0, APP_WIDTH, APP_HEIGHT);
    ccon::cconClear();

    float delta = 1.0f / (APP_HEIGHT - 1);
    Color colour1 = { 1.0f, 0.0f, 0.0f, 1.0f };
    Color colour2 = { 0.0f, 1.0f, 0.0f, 1.0f };

    for (int i = 0; i < APP_HEIGHT; i++)
    {
        drawLine(colour1, colour2, i);
        //colour1.a -= delta;
        ccon::cconAscii(0x01, i * APP_WIDTH + i);
        ccon::cconAttrib(colourRGB((i / APP_WIDTH) * 255, 255, 255), i * APP_WIDTH + i);
    }

    ccon::cconDrawBuffer();

    while (ccon::cconRunning())
    {
        
    }

    ccon::cconTerminate();
}