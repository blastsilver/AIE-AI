#pragma once
/** Dependencies **********************************************************************************/

    #include "core\detail.h"
    #include "type-graphics.h"

/** Declarations **********************************************************************************/

    namespace draw
    {
        struct _DRAWGraphics
        {
            int count;
            vec4 points[3];
        };

        inline void _AlgorithmDot(DRAWBuffer * object, const ccon::CCONPixel & data)
        {
            // calculate index
            int index = int(data.y + 0.5f) * (*object)->sizeW + int(data.x + 0.5f);
            ((float*)(*object)->buffer)[index + 0] = data.r;
            ((float*)(*object)->buffer)[index + 1] = data.g;
            ((float*)(*object)->buffer)[index + 2] = data.b;
            //((float*)(*object)->buffer)[index + 3] = data.b; // z-buffer
        }
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