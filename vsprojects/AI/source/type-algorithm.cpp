/** Dependencies **********************************************************************************/

    #include "draw.h"
    #include <math.h>
    
    // maths functions
    float _abs(const float n) { return n < 0 ? -n : n; };
    float _min(const float a, const float b) { return a < b ? a : b; };
    float _max(const float a, const float b) { return a > b ? a : b; };
    float _length3(const draw::vec4 & p1)
    {
        return sqrtf(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
    };
    draw::vec4 _lerp(const draw::vec4 & a, const draw::vec4 & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
            a.w + (b.w - a.w) * t,
        };
    }
    draw::vec4 _direction(const draw::vec4 & a, const draw::vec4 & b)
    {
        return{
            b.x - a.x,
            b.y - a.y,
            b.z - a.z,
            b.w - a.w,
        };
    }
    draw::DRAWVertex _lerp(const draw::DRAWVertex & a, const draw::DRAWVertex & b, float t)
    {
        return{
            {
                a.pos.x + (b.pos.x - a.pos.x) * t,
                a.pos.y + (b.pos.y - a.pos.y) * t,
                a.pos.z + (b.pos.z - a.pos.z) * t,
                a.pos.w + (b.pos.w - a.pos.w) * t,
            },
            {
                a.rgb.x + (b.rgb.x - a.rgb.x) * t,
                a.rgb.y + (b.rgb.y - a.rgb.y) * t,
                a.rgb.z + (b.rgb.z - a.rgb.z) * t,
                a.rgb.w + (b.rgb.w - a.rgb.w) * t,
            },
        };
    }
    // drawing algorithm
    inline void _algorithmDot(ccon::WIN32Buffer & buffer, const draw::DRAWVertex & v1)
    {
        // write to buffer
        ccon::win32Update(&buffer, { v1.rgb.r, v1.rgb.g, v1.rgb.b }, int(v1.pos.x + 0.5f), int(v1.pos.y + 0.5f));
    }
    inline void _algorithmLine(ccon::WIN32Buffer & buffer, const draw::DRAWShape2 & shape)
    {
        // check if different
        if (shape.v1.pos.x != shape.v2.pos.x || shape.v1.pos.y != shape.v2.pos.y)
        {
            // calculate steps
            draw::vec4 dir = _direction(shape.v1.pos, shape.v2.pos);
            int steps = int(_abs(_max(_abs(dir.x), _abs(dir.y))) + 0.5f * 2);
            float delta = 1 / float(steps);
            if (steps == 0) return;
            // iterate through pixels
            for (int i = 0; i <= steps; i++)
            {
                // write dot
                _algorithmDot(buffer, _lerp(shape.v1, shape.v2, (delta)* i));
                //Sleep(10);
            }
        }
    }
    inline void _algorithmTriangle(ccon::WIN32Buffer & buffer, const draw::DRAWShape3 & shape)
    {
        // calculate steps
        int steps = int((_abs(shape.v3.pos.y - shape.v1.pos.y) * 2) + 0.5f);
        float delta = 1 / float(steps);
        // iterate through pixels
        for (int i = 0; i <= steps; i++)
        {
            /*draw::DRAWShape2 line
            {
                _lerp(shape.v1, shape.v3, delta*i),
                _lerp(shape.v2, shape.v3, delta*i),
            };*/
            // write line
            _algorithmLine(buffer, { _lerp(shape.v1, shape.v3, delta*i), _lerp(shape.v2, shape.v3, delta*i) });
        }
    }
    

/** Declarations **********************************************************************************/

    void draw::drawRenderMode(int mode)
    {

    }
    void draw::drawRenderShape(ccon::WIN32Buffer & buffer, DRAWVertex data)
    {
        _algorithmDot(buffer, data);
    }
    void draw::drawRenderShape(ccon::WIN32Buffer & buffer, DRAWShape2 data)
    {
        _algorithmLine(buffer, data);
    }
    void draw::drawRenderShape(ccon::WIN32Buffer & buffer, DRAWShape3 data)
    {
        _algorithmTriangle(buffer, data);
    }

/**************************************************************************************************/