#pragma once
/** Dependencies **********************************************************************************/

    #include "draw\include.h"
    #include "draw\core\type-buffer.h"
    #include "draw\core\type-shader.h"

/** Declarations **********************************************************************************/

    namespace draw
    {
        class Graphics
        {
            // private variables
            int m_width;
            int m_height;
            int m_drawCount;
            vec4 m_viewport;
            vec4 m_colour[3];
            vec4 m_vertex[3];
            DRAWBuffer m_depthBuffer;
            DRAWBuffer m_stencilBuffer;
            DRAWShader m_defaultShader;
            ccon::CCONWindow m_oldWindow;
            ccon::CCONWindow m_newWindow;
            ccon::CCONSurface m_surface;
        public:
            // public defaults
            ~Graphics();
            Graphics(int width, int height);
            // public functions [buffers]
            void DrawBuffers();
            void ClearBuffers();
            // public functions [graphics]
            void AddVertex(float x, float y);
            void AddColour(float r, float g, float b) {};
            void AddVertex(float x, float y, float z);
            void AddColour(float r, float g, float b, float a) {};
            void AddVertex(float x, float y, float z, float w);
        private:
            // private functions [shaders]
            friend void vertCallback00(vec4 & point, vec4 & colour);
            friend bool vertCallback01(vec4 & point, vec4 & colour);
            friend void fragCallback00(vec4 & point, vec4 & colour);
            friend bool fragCallback01(vec4 & point, vec4 & colour);
        };

        //inline void _AlgorithmDot(DRAWBuffer * cBuffer, DRAWBuffer * zBuffer, const ccon::CCONPixel & data)
        //{
        //    // calculate index
        //    int index = int(data.y + 0.5f) * (*object)->sizeW + int(data.x + 0.5f);
        //    ((float*)(*object)->buffer)[index + 0] = data.r;
        //    ((float*)(*object)->buffer)[index + 1] = data.g;
        //    ((float*)(*object)->buffer)[index + 2] = data.b;
        //    //((float*)(*object)->buffer)[index + 3] = data.b; // z-buffer
        //}
        //void render(DRAWLink2 link)
        //{
        //    if (link.v1.x != link.v2.x || link.v1.y != link.v2.y)
        //    {
        //        // calculate steps
        //        DRAWVectorf dir = Direction(link.v1, link.v2);
        //        int steps = int(std::abs(std::abs(dir.x) > std::abs(dir.y) ? dir.x : dir.y) + 0.5f * 2);
        //        float delta = 1 / float(steps);
        //        // iterate through pixels
        //        if (steps == 0) return;
        //        for (int i = 0; i <= steps; i++)
        //        {
        //            DRAWVectorf vec = Lerp(link.v1, link.v2, (delta) * i);
        //            DRAWColour col = Lerp(link.c1, link.c2, (delta) * i);
        //            ccon::cconUpdate(&m_surface, { int(vec.x + 0.5f), int(vec.y + 0.5f), col.r, col.g, col.b });
        //            //render();
        //            //Sleep(10);
        //        }
        //    }
        //    else
        //    {
        //        ccon::cconUpdate(&m_surface, { int(link.v1.x), int(link.v1.y), link.c1.r, link.c1.g, link.c1.b });
        //    }
        //}
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
        //void FillTriangle(draw::DRAWShape3 & shape)
        //{
        //    draw::drawRenderShape(m_buffer, shape);
        //}
    }

/**************************************************************************************************/