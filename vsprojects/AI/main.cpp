#include <cmath>
#include <ctime>
#include <ccon.h>
#include <Windows.h>

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

unsigned char colorA(float a)
{
    // calculate alpha index
    unsigned int index = int(a * 5);
    // return ascii character
    return (index == 0 ? 0x00 : (index > 3 ? 0xdb : 0xb0 + index - 1));
}

unsigned char colourRGB(int r, int g, int b)
{
    // calculate bright bit
    int index = (r > 127 | g > 127 | b > 127) ? 8 : 0;
    // calculate console colours
    index |= r > 84 ? 4 : 0;
    index |= g > 84 ? 2 : 0;
    index |= b > 84 ? 1 : 0;
    // return attribute colour index
    return (unsigned char) index;
}

//unsigned char colourRGB(float r, float g, float b)
//{
//    return colourRGB(r * 255, g * 255, b * 255);
//    //// calculate colours
//    //unsigned char R = r < 0.33334f ? 0x00 : r < 0.66667f ? 0x04 : 0x0C;
//    //unsigned char G = g < 0.33334f ? 0x00 : g < 0.66667f ? 0x02 : 0x0A;
//    //unsigned char B = b < 0.33334f ? 0x00 : b < 0.66667f ? 0x01 : 0x09;
//    //// return attribute colour
//    //return R | G | B;
//}

void colour(float r, float g, float b, float a, int index)
{
    // print color on screen
    ccon::cconAscii(colorA(a), index);
    ccon::cconAttrib(colourRGB(int(r * 255 + 0.5f), int(g * 255 + 0.5f), int(b * 255 + 0.5f)), index);
    ccon::cconDrawBuffer();
}

void drawLine(Color & color1, Color & color2, int line)
{
    Color color = { color1.r, color1.g, color1.b, color1.a };
    Color delta = {
        (color2.r - color1.r) / (APP_WIDTH - 1),
        (color2.g - color1.g) / (APP_WIDTH - 1),
        (color2.b - color1.b) / (APP_WIDTH - 1),
        (color2.a - color1.a) / (APP_WIDTH - 1)
    };
    int index = APP_WIDTH * line;
    // draw line
    for (int i = 0; i < APP_WIDTH; i++)
    {
        colour(color.r, color.g, color.b, color.a, index++);

        color.r += delta.r;
        color.g += delta.g;
        color.b += delta.b;
        color.a += delta.a;
    }
}



void main()
{
    ccon::cconInit();
    ccon::cconSize(APP_WIDTH, APP_HEIGHT);
    ccon::cconViewport(0, 0, APP_WIDTH, APP_HEIGHT);

    Color red = { 1, 0, 0, 1 };
    Color blue = { 0, 0, 1, 1 };
    Color green = { 0, 1, 0, 1 };

    ccon::cconClear();
    
    drawLine(red, green, 0);

    while (ccon::cconRunning())
    {
        
    }

    ccon::cconTerminate();
}