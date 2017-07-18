#pragma once
/** Dependencies **********************************************************************************/

    #include <ccon3.h>

/** Declarations **********************************************************************************/

    #define DRAW_DEPTH_BUFFER 1
    #define DRAW_COLOUR_BUFFER 2
    #define DRAW_STENCIL_BUFFER 4

    namespace draw
    {
        struct mat4 { float data[16]; };
        struct vec4 { union { struct { float x, y, z, w; }; struct { float r, g, b, a; }; }; };
        struct DRAWLink1 { vec4 v1, c1; };
        struct DRAWLink2 { vec4 v1, v2, c1, c2; };
        struct DRAWLink3 { vec4 v1, v2, v3, c1, c2, c3; };

        class Canvas
        {
            int * m_StencilBuffer;
            vec4 * m_ColourBuffer;
            ccon::WIN32Buffer m_buffer;
            ccon::WIN32Window m_oldWindow;
            ccon::WIN32Window m_newWindow;
        public:
            Canvas(int width, int height);
            ~Canvas();
            void draw();
            void clear(int mode);
            void render(DRAWLink1 & link);
            void render(DRAWLink2 & link);
            void render(DRAWLink3 & link);
        };

    }

/**************************************************************************************************/