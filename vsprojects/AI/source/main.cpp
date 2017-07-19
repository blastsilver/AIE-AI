////https://qiao.github.io/PathFinding.js/visual/
////https://www.wholetomato.com/#
////https://en.wikipedia.org/wiki/HSL_and_HSV
////https://stackoverflow.com/questions/2353211/hsl-to-rgb-color-conversion
////https://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another
////https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
////https://www.google.com.au/search?q=c%2B%2B+interpolate+between+2+colours&oq=c%2B%2B+interpolate+between+2+colours&gs_l=serp.3...105210.116945.0.117081.41.37.3.0.0.0.297.4753.0j19j6.25.0....0...1.1.64.serp..13.24.3997...0j0i67k1j0i10i67k1j0i131k1j0i10k1j0i22i30k1j33i160k1j33i21k1j30i10k1.lpcVdyxoNQs

#include "draw.h"
#include <ctime>
#include <math.h>
#include <iostream>
#include <Windows.h>

using namespace ccon;
struct DRAWColour { float r, g, b; };
struct DRAWVectori { int x, y, z; };
struct DRAWVectorf { float x, y, z; };
struct DRAWLink2 {
    DRAWVectorf v1, v2;
    DRAWColour c1, c2;
};
struct DRAWLink3 {
    DRAWVectorf v1, v2, v3;
    DRAWColour c1, c2, c3;
};

class ConsoleWindow
{
    ccon::WIN32Buffer m_buffer;
    ccon::WIN32Window m_oldWindow;
    ccon::WIN32Window m_newWindow;
public:
    ConsoleWindow(short width, short height)
    {
        // get defaults
        ccon::win32Create(CCON_NULL, &m_oldWindow);
        // create window
        ccon::WIN32WindowInfo info = {
            { 8, 8, FF_DONTCARE, FW_NORMAL, "Terminal" },
            { ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS },
            { NULL },
            { WS_CAPTION | WS_SYSMENU | WS_VISIBLE },
            { width, height },
            { FALSE, 1 },
        };
        ccon::win32Create(&info, &m_newWindow);
        // create buffers
        ccon::WIN32BufferInfo bInfo = { 0, 0, short(width), short(height) };
        ccon::win32Create(&bInfo, &m_buffer, GetStdHandle(STD_OUTPUT_HANDLE));
    }
    ~ConsoleWindow()
    {
        // set defaults
        ccon::win32Update(&m_oldWindow);
        // delete handles
        ccon::win32Delete(&m_buffer);
        ccon::win32Delete(&m_oldWindow);
        ccon::win32Delete(&m_newWindow);
    }
    void render()
    {
        // draw buffer
        ccon::win32Update(&m_buffer, GetStdHandle(STD_OUTPUT_HANDLE));
    }
    void render(DRAWLink2 link)
    {
        if (link.v1.x != link.v2.x || link.v1.y != link.v2.y)
        {
            // calculate steps
            DRAWVectorf dir = Direction(link.v1, link.v2);
            int steps = int(std::abs(std::abs(dir.x) > std::abs(dir.y) ? dir.x : dir.y) + 0.5f * 2);
            float delta = 1 / float(steps);
            // iterate through pixels
            if (steps == 0) return;
            for (int i = 0; i <= steps; i++)
            {
                DRAWVectorf vec = Lerp(link.v1, link.v2, (delta) * i);
                DRAWColour col = Lerp(link.c1, link.c2, (delta) * i);
                ccon::win32Update(&m_buffer, { col.r, col.g, col.b }, int(vec.x + 0.5f), int(vec.y + 0.5f));
                //render();
                //Sleep(10);
            }
        }
        else
        {
            ccon::win32Update(&m_buffer, { link.c1.r, link.c1.g, link.c1.b }, int(link.v1.x), int(link.v1.y));
        }
    }

    //void FillTriangle(DRAWLink3 & link)
    //{
    //    // calculate steps
    //    int steps = int(std::abs(link.v3.y - link.v1.y) + 0.5f * 2);
    //    float delta = 1 / float(steps);
    //    // iterate through pixels
    //    for (int i = 0; i <= steps; i++)
    //    {
    //        DRAWVectorf v1 = Lerp(link.v1, link.v3, delta*i);
    //        DRAWVectorf v2 = Lerp(link.v2, link.v3, delta*i);
    //        DRAWColour c1 = Lerp(link.c1, link.c3, delta*i);
    //        DRAWColour c2 = Lerp(link.c2, link.c3, delta*i);
    //        render({ v1, v2, c1, c2 });
    //    }
    //}
    void FillTriangle(draw::DRAWShape3 & shape)
    {
        draw::drawRenderShape(m_buffer, shape);
    }
private:

    float Distance(DRAWVectorf & p1, DRAWVectorf & p2)
    {
        DRAWVectorf dir = Direction(p1, p2);
        return sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    }
    DRAWColour Lerp(DRAWColour & a, DRAWColour & b, float t)
    {
        return{
            a.r + (b.r - a.r) * t,
            a.g + (b.g - a.g) * t,
            a.b + (b.b - a.b) * t,
        };
    }
    DRAWVectorf Lerp(DRAWVectorf & a, DRAWVectorf & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
        };
    }
    DRAWVectorf Direction(DRAWVectorf & p1, DRAWVectorf & p2)
    {
        return{
            p2.x - p1.x,
            p2.y - p1.y,
            p2.z - p1.z,
        };
    }
};

void main()
{
    try
    {
        Sleep(1000);
        short SIZE = 81;
        ConsoleWindow window{ SIZE, SIZE };

        draw::vec4 rgb1 = { 255, 0, 0 };
        draw::vec4 rgb2 = { 0, 255, 0 };
        draw::vec4 rgb3 = { 0, 0, 255 };

        float size1 = float(SIZE);
        float size2 = float(SIZE) / 2;
        float size4 = float(SIZE) / 4;


        draw::DRAWShape3 triangle = {
            { { 1 + 40, 39 + 40 }, rgb1 },
            { { 39 + 40, 39 + 40 }, rgb2 },
            { { 20 + 40,  1 + 40 }, rgb3 },
        };

        window.FillTriangle(triangle);
        //window.FillTriangle(triangle2);
        //window.FillTriangle(triangle3);
        //window.FillTriangle(triangle4);

        //draw::drawRenderShape(m_buffer)

        window.render();

        int zz = 0;
    }
    catch (char * message)
    {
        std::cout << message << std::endl;
    }
    Sleep(1000);
}


//void render(DRAWLink2 link)
//{
//    if (link.v1.x != link.v2.x || link.v1.y != link.v2.y)
//    {
//        // calculate steps
//        DRAWVectorf dir = Direction(link.v1, link.v2);
//        int steps = int(std::abs(std::abs(dir.x) > std::abs(dir.y) ? dir.x : dir.y) + 0.5f) * 2;
//        float delta = 1 / float(steps);
//        // iterate through pixels
//        for (int i = 0; i <= steps; i++)
//        {
//            DRAWVectorf vec = Lerp(link.v1, link.v2, (delta)* i);
//            DRAWColour col = Lerp(link.c1, link.c2, (delta)* i);
//            ccon::win32Update(&m_buffer, { col.r, col.g, col.b }, int(vec.x + 0.5f), int(vec.y + 0.5f));
//            render();
//        }
//    }
//    else
//    {
//        ccon::win32Update(&m_buffer, { link.c1.r, link.c1.g, link.c1.b }, int(link.v1.x + 0.5f), int(link.v1.y + 0.5f));
//    }
//}
//
//void FillTriangle(DRAWLink3 & link)
//{
//    // calculate steps
//    int steps = int(std::abs(link.v3.y - link.v1.y) + 0.5f) * 2;
//    float delta = 1 / float(steps);
//    // iterate through pixels
//    for (int i = 0; i <= steps; i++)
//    {
//        DRAWVectorf v1 = Lerp(link.v1, link.v3, delta*i);
//        DRAWVectorf v2 = Lerp(link.v2, link.v3, delta*i);
//        DRAWColour c1 = Lerp(link.c1, link.c3, delta*i);
//        DRAWColour c2 = Lerp(link.c2, link.c3, delta*i);
//        render({ v1, v2, c1, c2 });
//    }
//}