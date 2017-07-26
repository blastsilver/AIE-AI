#pragma once
/** Dependencies **********************************************************************************/

    #include <cmath>
    #include "Graphics.h"
    #include "draw\detail.h"

    static draw::Graphics * g_graphics = 0;

    void g_Mul(draw::vec4 & point, float scalar)
    {
        // update point
        point.x *= scalar;
        point.y *= scalar;
        point.z *= scalar;
        point.w *= scalar;
    }
    
    void g_2SortY(draw::vec4 * point, draw::vec4 * colour)
    {
        // check highest y
        if (point[1].y > point[0].y)
        {
            // swap points
            draw::vec4 vtemp = point[0];
            point[0] = point[1];
            point[1] = vtemp;
            // swap colours
            draw::vec4 ctemp = colour[0];
            colour[0] = colour[1];
            colour[1] = ctemp;
        }
    }

    void g_3SortY(draw::vec4 * point, draw::vec4 * colour)
    {
        // swap v1-v2
        g_2SortY(&point[0], &colour[0]);
        // swap v2-v3
        g_2SortY(&point[1], &colour[1]);
        // swap v1-v2
        g_2SortY(&point[0], &colour[0]);
    }

    float g_Dot2(draw::vec4 & a, draw::vec4 & b)
    {
        return a.x * b.x + a.y * b.y;
    }

    float g_Dot3(draw::vec4 & a, draw::vec4 & b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    float g_Length3(draw::vec4 & vec)
    {
        return std::sqrtf(g_Dot3(vec, vec));
    }

    float g_Length2(draw::vec4 & vec)
    {
        return std::sqrtf(g_Dot2(vec, vec));
    }

    draw::vec4 g_Norm2(draw::vec4 & vec)
    {
        float length = g_Length2(vec);
        return
        {
            vec.x / length,
            vec.y / length,
        };
    }

    draw::vec4 g_Norm3(draw::vec4 & vec)
    {
        float length = g_Length3(vec);
        return
        {
            vec.x / length,
            vec.y / length,
            vec.z / length,
        };
    }

    void g_WorldToScreen(draw::vec4 & point, draw::vec4 & viewport)
    {
        // check division by 0
        if (point.z != 0)
        {
            point.x /= -point.z;
            point.x /= -point.z;
        }
        // calculate screen coordinates
        point.x = (point.x + 1.0f) * ((viewport.z - 1) / 2.0f) + viewport.x;
        point.y = (-point.y + 1.0f) * ((viewport.w - 1) / 2.0f) + viewport.y;
    }

    draw::vec4 g_Sub2(const draw::vec4 & a, const draw::vec4 & b)
    {
        return{
            a.x - b.x,
            a.y - b.y,
        };
    }

    draw::vec4 g_Sub(const draw::vec4 & a, const draw::vec4 & b)
    {
        return {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w,
        };
    }

    draw::vec4 g_Lerp(draw::vec4 & a, draw::vec4 & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.y + (b.y - a.y) * t,
            a.w + (b.w - a.w) * t,
        };
    }

    void g_DrawLine(draw::vec4 & v1, draw::vec4 & v2, draw::vec4 & c1, draw::vec4 & c2)
    {
        // calculate steps
        draw::vec4 dir = g_Sub(v2, v1);
        int steps = int(std::abs(std::abs(dir.x) > std::abs(dir.y) ? dir.x : dir.y) + 0.5f * 2);
        float delta = 1 / float(steps == 0 ? 1 : steps);
        // iterate through pixels
        for (int i = 0; i <= steps; i++)
        {
            draw::vec4 vec = g_Lerp(v1, v2, (delta) * i);
            draw::vec4 col = g_Lerp(c1, c2, (delta) * i);
            // shader :: draw fragment
            if (draw::fragCallback01(vec, col)) draw::fragCallback00(vec, col);
        }
    }

    void g_DrawTriangle(draw::vec4 & v1, draw::vec4 & v2, draw::vec4 & v3, draw::vec4 & c1, draw::vec4 & c2, draw::vec4 & c3)
    {
        // check flat triangle
        if (v1.y == v2.y)
        {
            // calculate steps
            int steps = int(std::abs(v3.y - v1.y) + 0.5f * 2);
            float delta = 1 / float(steps);
            // iterate through pixels
            for (int i = 0; i <= steps; i++)
            {
                // draw triangle line
                g_DrawLine(
                    g_Lerp(v1, v3, delta * i),
                    g_Lerp(v2, v3, delta * i),
                    g_Lerp(c1, c3, delta * i),
                    g_Lerp(c2, c3, delta * i)
                );
            }

            //g_DrawLine(v1, v2, c1, c2);
            //g_DrawLine(v2, v3, c2, c3);
            //g_DrawLine(v3, v1, c3, c1);
        }
        // calculate complex triangle
        else
        {
            // calculate x & y
            draw::vec4 vN = {
                //(int)(v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x)),
                (v1.x + ((v2.y - v1.y) / (v3.y - v1.y)) * (v3.x - v1.x)),
                v2.y,
            };
            // find ration between v3v4 - v3v1
            draw::vec4 v3v4 = g_Sub(v3, vN);
            draw::vec4 v3v1 = g_Sub(v3, v1);
            float length1 = g_Length2(v3v4);
            float length2 = g_Length2(v3v1);
            float ratio = length1 / length2;
            // recalculate v4 using lerp
            draw::vec4 v4 = g_Lerp(v3, v1, ratio);
            draw::vec4 c4 = g_Lerp(c3, c1, ratio);
            v4.y = v2.y;
            c4.y = c2.y;

            //// find point on line v1-v3
            //draw::vec4 v1v2 = g_Sub(v2, v1);
            //draw::vec4 v1v3 = g_Sub({ v1.x, v3.y, v3.z, v3.w }, v1);
            //float delta = g_Dot3(v1v2, v1v3);
            //draw::vec4 v4 = g_Lerp(v1, v3, delta);
            //draw::vec4 c4 = g_Lerp(c1, c3, delta);
            //v4.y = v2.y;
            //c4.y = c2.y;

            // fill bottom/top flat triangle
            g_DrawTriangle(v2, v4, v3, c2, c4, c3);
            g_DrawTriangle(v4, v2, v1, c4, c2, c1);
        }
    }

    void draw::vertCallback00(vec4 & point, vec4 & colour)
    {
        // convert coordinates
        g_WorldToScreen(point, g_graphics->m_viewport);
        // update rgb colour
        g_Mul(colour, 255 * point.a);
    }

    bool draw::vertCallback01(vec4 & point, vec4 & colour)
    {
        return true;
    }

    void draw::fragCallback00(vec4 & point, vec4 & colour)
    {
        // update surface
        ccon::cconUpdate(&g_graphics->m_surface, { point.x, point.y, colour.r, colour.g, colour.b });
    }

    bool draw::fragCallback01(vec4 & point, vec4 & colour)
    {
        int index = int(point.x + 0.5f) * g_graphics->m_width + int(point.y + 0.5f);
        // culling check
        if (point.x < 0.0f || point.x > float(g_graphics->m_width - 1)) return false;
        if (point.y < 0.0f || point.y > float(g_graphics->m_height - 1)) return false;
        // depth buffer check
        if (point.z < 0.0f || point.z < ((float*)(g_graphics->m_depthBuffer->buffer))[index]) return false;
        // update stencil/depth buffer 
        ((int*)(g_graphics->m_stencilBuffer->buffer))[index]++;
        ((float*)(g_graphics->m_depthBuffer->buffer))[index] = point.z;
        // all tests passed successfully
        return true;
    }
    

/** Declarations **********************************************************************************/

    // public defaults
    draw::Graphics::~Graphics()
    {
        // ccon :: reset console
        ccon::cconUpdate(&m_oldWindow);
        // ccon :: delete handles
        ccon::cconDelete(&m_surface);
        //ccon::cconDelete(&m_oldWindow);
        ccon::cconDelete(&m_newWindow);
        // draw :: delete handles
        draw::drawDeleteBuffer(&m_depthBuffer);
        draw::drawDeleteBuffer(&m_stencilBuffer);
        draw::drawDeleteShader(&m_defaultShader);
    }

    draw::Graphics::Graphics(int width, int height)
    {
        // initialize values
        m_width = width;
        m_height = height;
        m_viewport = { 0, 0, float(width), float(height) };
        m_drawCount = 0;
        m_colour[0] = {};
        m_colour[1] = {};
        m_colour[2] = {};
        m_vertex[0] = {};
        m_vertex[1] = {};
        m_vertex[2] = {};
        // ccon :: create handles
        ccon::CCONWindowInfo windInfo = { short(width), short(height) };
        ccon::CCONSurfaceInfo surfInfo = { 0, 0, short(width), short(height) };
        ccon::cconCreate(&surfInfo, &m_surface);
        ccon::cconCreate(CCON_NULL, &m_oldWindow);
        ccon::cconCreate(&windInfo, &m_newWindow);
        // draw :: create handles
        draw::DRAWBufferInfo buffInfo1i = { sizeof(int) * 1, width, height };
        draw::DRAWBufferInfo buffInfo1f = { sizeof(float) * 1, width, height };
        draw::DRAWShaderInfo shaderInfo = { vertCallback00, vertCallback01, fragCallback00, fragCallback01 };
        draw::drawCreateBuffer(&buffInfo1f, &m_depthBuffer);
        draw::drawCreateBuffer(&buffInfo1i, &m_stencilBuffer);
        draw::drawCreateShader(&shaderInfo, &m_defaultShader);
        // ######################
        // ### FIX THIS LATER ###

        g_graphics = this;

        // ### FIX THIS LATER ###
        // ######################
    }

    // public functions [buffers]
    void draw::Graphics::DrawBuffers()
    {
        // reset values
        m_drawCount = 0;
        m_colour[0] = {};
        m_colour[1] = {};
        m_colour[2] = {};
        m_vertex[0] = {};
        m_vertex[1] = {};
        m_vertex[2] = {};
        // ccon :: update surface
        ccon::cconUpdate(&m_surface);
    }

    void draw::Graphics::ClearBuffers()
    {
        int index;
        int index3x;
        // clear all buffers
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                // calculate index
                index = y * m_width + x;
                index3x = index * 3;
                // clear stencil buffers
                ((int*)(m_stencilBuffer->buffer))[index] = 0;
                // clear depth buffers
                ((float*)(m_depthBuffer->buffer))[index] = 0;
                // clear color buffer
                ccon::cconUpdate(&m_surface, { float(x), float(y) });
            }
        }
    }

    // public functions [graphics]
    void draw::Graphics::AddVertex(float x, float y) { AddVertex(x, y, 0, 1); };

    void draw::Graphics::AddVertex(float x, float y, float z) { AddVertex(x, y, z, 1); };

    void draw::Graphics::AddVertex(float x, float y, float z, float w)
    {
        int index = m_drawCount++;
        // add vertex and colour
        m_vertex[index] = { x, y, z, w };
        m_colour[index] = {
            ((m_vertex[index].x + 1) / 2),
            ((m_vertex[index].y + 1) / 2),
            ((m_vertex[index].z + 1) / 2),
            1,
        };
        // [shader] run vertex shader
        draw::vertCallback00(m_vertex[index], m_colour[index]);
        // check draw count
        if (m_drawCount == 3)
        {
            // reset
            m_drawCount = 0;
            // sort points
            g_3SortY(m_vertex, m_colour);
            // draw triangle from points
            g_DrawTriangle(m_vertex[0], m_vertex[1], m_vertex[2], m_colour[0], m_colour[1], m_colour[2]);
        }
    }

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

/**************************************************************************************************/