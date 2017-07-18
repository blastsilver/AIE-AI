/** Dependencies **********************************************************************************/

    #include "draw.h"
    #include <math.h>
    #include <Windows.h>
    
    //float _Length(const draw::vec4 & data) { }
    draw::vec4 _Lerp(const draw::vec4 & a, const draw::vec4 & b, const float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
        };
    }

    void _draw_Dot(draw::DRAWLink1 & link)
    {

    };
    void _draw_Line(draw::DRAWLink2 & link)
    {

    };
    void _draw_TriangleAxisY(draw::DRAWLink3 & link)
    {
        // calculate steps
        int steps = int(std::abs(link.v3.y - link.v1.y) + 0.5f * 2);
        float delta = 1 / float(steps);
        // iterate through pixels
        for (int i = 0; i <= steps; i++)
        {
            draw::vec4 v1 = _Lerp(link.v1, link.v3, delta*i);
            draw::vec4 v2 = _Lerp(link.v2, link.v3, delta*i);
            draw::vec4 c1 = _Lerp(link.c1, link.c3, delta*i);
            draw::vec4 c2 = _Lerp(link.c2, link.c3, delta*i);
            _draw_Line({ v1, v2, c1, c2 });
        }
    }
    void _draw_TriangleAxisX(draw::DRAWLink3 & link)
    {
        // calculate steps
        int steps = int(std::abs(link.v3.y - link.v1.y) + 0.5f * 2);
        float delta = 1 / float(steps);
        // iterate through pixels
        for (int i = 0; i <= steps; i++)
        {
            DRAWVectorf v1 = Lerp(link.v1, link.v3, delta*i);
            DRAWVectorf v2 = Lerp(link.v2, link.v3, delta*i);
            DRAWColour c1 = Lerp(link.c1, link.c3, delta*i);
            DRAWColour c2 = Lerp(link.c2, link.c3, delta*i);
            render({ v1, v2, c1, c2 });
        }
    }

/** Definitions ***********************************************************************************/

    draw::Canvas::Canvas(int width, int height)
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
        this->m_ColourBuffer = new vec4[width * height];
        this->m_StencilBuffer = new int[width * height];
        ccon::WIN32BufferInfo bInfo = { 0, 0, short(width), short(height) };
        ccon::win32Create(&bInfo, &m_buffer, GetStdHandle(STD_OUTPUT_HANDLE));
    }
    draw::Canvas::~Canvas()
    {
        // set defaults
        ccon::win32Update(&m_oldWindow);
        // delete handles
        delete [] m_ColourBuffer;
        delete [] m_StencilBuffer;
        ccon::win32Delete(&m_buffer);
        ccon::win32Delete(&m_oldWindow);
        ccon::win32Delete(&m_newWindow);
    }
    void draw::Canvas::draw()
    {
        // draw console buffer
        ccon::win32Update(&m_buffer, GetStdHandle(STD_OUTPUT_HANDLE));
    }
    void draw::Canvas::clear(int mode)
    {
        // check depth buffer
        // check colour buffer
        // check stencil buffer
    }
    void draw::Canvas::render(DRAWLink1 & link)
    {

    }
    void draw::Canvas::render(DRAWLink2 & link)
    {

    }
    void draw::Canvas::render(DRAWLink3 & link)
    {

    }

/**************************************************************************************************/