////https://qiao.github.io/PathFinding.js/visual/
////https://www.wholetomato.com/#
////https://en.wikipedia.org/wiki/HSL_and_HSV
////https://stackoverflow.com/questions/2353211/hsl-to-rgb-color-conversion
////https://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another
////https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
////https://www.google.com.au/search?q=c%2B%2B+interpolate+between+2+colours&oq=c%2B%2B+interpolate+between+2+colours&gs_l=serp.3...105210.116945.0.117081.41.37.3.0.0.0.297.4753.0j19j6.25.0....0...1.1.64.serp..13.24.3997...0j0i67k1j0i10i67k1j0i131k1j0i10k1j0i22i30k1j33i160k1j33i21k1j30i10k1.lpcVdyxoNQs

/*
void DrawLine(D2D1_POINT_2F start, D2D1_POINT_2F end, int color = 0, int stroke = 5, int alpha = 255)
{
	int x0 = (int)start.x, y0 = (int)start.y, x1 = (int)end.x, y1 = (int)end.y;  
	int dx = abs(x1 - x0), dy = abs(y1 - y0); 
	int sx = (x0 < x1) ? 1 : -1, sy = (y0 < y1) ? 1 : -1; 
	int err = dx - dy; 
		
	while (true)
	{
		SetColor(y0, x0, color, stroke); 
		if (alpha != 255) SetAlpha(y0, x0, alpha, stroke); 
		if (x0 == x1 && y0 == y1) return; 
		int e2 = (err << 1); 
		if (e2 > -dy)
		{
			err -= dy; 
			x0 += sx; 
		}
		if (e2 < dx)
		{
			err += dx; 
			y0 += sy; 
		}
	}
}
*/

#include <ccon3.h>
#include <ctime>
#include <math.h>
#include <iostream>
#include <Windows.h>

using namespace ccon;
struct DRAWColour { float r, g, b; };
struct DRAWVector { float x, y, z; };
struct DRAWLink2 {
    DRAWVector v1, v2;
    DRAWColour c1, c2;
};
struct DRAWLink3 {
    DRAWVector v1, v2, v3;
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
        srand((UINT)time(NULL));
        //~~~~~~~~~~~~~~~~~~~~~////~~~~~~~~~~~~~~~~~~~~~//
        // get defaults
        ccon::win32Create(CCON_NULL, &m_oldWindow);
        //~~~~~~~~~~~~~~~~~~~~~////~~~~~~~~~~~~~~~~~~~~~//
        // costumize window
        ccon::WIN32WindowInfo info = {
            { 8, 8, FF_DONTCARE, FW_NORMAL, "Terminal" },
            { ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS },
            { NULL },
            { WS_CAPTION | WS_SYSMENU | WS_VISIBLE },
            { width, height },
            { FALSE, 1 },
        };
        ccon::win32Create(&info, &m_newWindow);
        //~~~~~~~~~~~~~~~~~~~~~////~~~~~~~~~~~~~~~~~~~~~//
        // create draw buffer
        ccon::WIN32BufferInfo bInfo = { 0, 0, short(width), short(height) };
        ccon::win32Create(&bInfo, &m_buffer, GetStdHandle(STD_OUTPUT_HANDLE));
        //~~~~~~~~~~~~~~~~~~~~~////~~~~~~~~~~~~~~~~~~~~~//
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
        // calculate steps
        DRAWVector dir = Direction(link.v1, link.v2);
        float steps = std::abs(std::abs(dir.x) > std::abs(dir.y) ? dir.x : dir.y);
        float delta = 1 / (steps);
        float count = 0;
        // iterate through pixels
        for (int i = 0; i < int(steps); i++)
        {
            DRAWVector vec = Lerp(link.v1, link.v2, count);
            DRAWColour col = Lerp(link.c1, link.c2, count);
            ccon::win32Update(&m_buffer, { col.r, col.g, col.b }, int(vec.x), int(vec.y));
            count += delta;
        }
    }

    //inline void AlgorithmLine()
    //{
    //    // -----------------------------------------------
    //    // Algorithm :: FRAGMENT -------------------------
    //    int index, i;
    //    Vector2i pos;
    //    // Calculate direction vectors
    //    Vector4f dirVertex = rInfo.vertex[1] - rInfo.vertex[0];
    //    Vector4f dirColour = rInfo.colour[1] - rInfo.colour[0];
    //    float steps = std::abs(std::abs(dirVertex.x) > std::abs(dirVertex.y) ? dirVertex.x : dirVertex.y);
    //    dirVertex = { dirVertex.x / steps, dirVertex.y / steps, dirVertex.z / steps, dirVertex.w / steps };
    //    dirColour = { dirColour.x / (steps - 1), dirColour.y / (steps - 1), dirColour.z / (steps - 1), dirColour.w / (steps - 1) };
    //    // Iterate throught each pixel
    //    for (i = 0; i <= int(steps); i++)
    //    {
    //        // Convert to int coordinates
    //        pos.x = int(rInfo.vertex[0].x + 0.5f);
    //        pos.y = int(rInfo.vertex[0].y + 0.5f);
    //        // Out-of-bounds-check
    //        if (pos.x > -1 && pos.x < wInfo.viewsize.x)
    //        {
    //            if (pos.y > -1 && pos.y < wInfo.viewsize.y)
    //            {
    //                // Convert screen-to-index coordinates
    //                index = pos.y * wInfo.viewsize.x + pos.x;
    //                // Depth-Buffer check
    //                float depth = rInfo.depth[index];
    //                if (!(rInfo.vertex[0].z > rInfo.depth[index]) || rInfo.depth[index] == 0)
    //                {
    //                    // Algorithm :: RASTERIZATION --------
    //                    rInfo.depth[index] = rInfo.vertex[0].z;
    //                    ccon::cconAscii(ToAscii(&rInfo.colour[0]), index);
    //                    ccon::cconAttrib(ToAttrib(&rInfo.colour[0]), index);
    //                }
    //            }
    //        }
    //        // Add direction vectors
    //        rInfo.vertex[0] = rInfo.vertex[0] + dirVertex;
    //        rInfo.colour[0] = rInfo.colour[0] + dirColour;
    //    }
    //}


    void FillTriangle(DRAWLink3 & link)
    {
        // calculate steps
        float steps = std::abs(link.v3.y - link.v1.y);
        float delta = 1 / (steps);
        float count = 0;
        // iterate through pixels
        for (int i = 0; i <= int(steps); i++)
        {
            DRAWVector v1 = Lerp(link.v1, link.v3, count);
            DRAWVector v2 = Lerp(link.v2, link.v3, count);
            DRAWColour c1 = Lerp(link.c1, link.c3, count);
            DRAWColour c2 = Lerp(link.c2, link.c3, count);
            v2.x += 0.5f;
            v2.y += 0.5f;
            render({ v1, v2, c1, c2 });
            count += delta;
            render();
            Sleep(100);
        }


        //render({ link.v3, link.v2, link.c3, link.c2 });

        /*float invslope1 = (link.v3.x - link.v1.x) / (link.v3.y - link.v1.y);
        float invslope2 = (link.v3.x - link.v2.x) / (link.v3.y - link.v2.y);

        float curx1 = link.v3.x;
        float curx2 = link.v3.x;

        for (float scanlineY = link.v3.y; scanlineY >= link.v1.y; scanlineY--)
        {
            render({ {curx1, scanlineY }, {curx2 + 1.0f, scanlineY}, link.c1, link.c2 });
            curx1 -= invslope1;
            curx2 -= invslope2;
        }*/
    }
private:


    float Distance(DRAWVector & p1, DRAWVector & p2)
    {
        DRAWVector dir = Direction(p1, p2);
        return sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    }

    DRAWVector Lerp(DRAWVector & a, DRAWVector & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
        };
    }

    DRAWColour Lerp(DRAWColour & a, DRAWColour & b, float t)
    {
        return{
            a.r + (b.r - a.r) * t,
            a.g + (b.g - a.g) * t,
            a.b + (b.b - a.b) * t,
        };
    }

    DRAWVector Direction(DRAWVector & p1, DRAWVector & p2)
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
        short SIZE = 41;
        ConsoleWindow window{ SIZE, SIZE };

        //window.TFlatTriangle({ 1,0 }, { float(SIZE),0 }, { 20,float(SIZE) });
        DRAWColour rgb1 = { 255, 0, 0 };
        DRAWColour rgb2 = { 0, 255, 0 };
        DRAWColour rgb3 = { 0, 0, 255 };

        window.render({ { 40, 0 }, { 20, 20 }, rgb1, rgb2 });

        DRAWLink3 face3 = {
            {  1, 1 },
            { 39, 1 },
            { 20, 39 },
            rgb1, rgb2, rgb3
        };

       // window.FillTriangle(face3);

        /*for (short i = 0; i < SIZE; i++)
        {
            window.render({ { 0, float(i) }, { float(SIZE - i), float(i) }, rgb1, rgb2 });
        }*/

        window.render();

        int zz = 0;
    }
    catch (char * message)
    {
        std::cout << message << std::endl;
    }
    Sleep(1000);
}