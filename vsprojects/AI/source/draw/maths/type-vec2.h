#pragma once
/** Dependencies **********************************************************************************/

    #include "swizzle.h"

/** Declarations **********************************************************************************/

    namespace draw
    {
        struct vec2 {
            // variables
            union {
                struct { float x, y; };
                struct { float r, g; };

                swizzle2<2, vec2, 0, 0, -1, -2> xx;
                swizzle2<2, vec2, 0, 1, -1, -2> xy;
                swizzle2<2, vec2, 1, 0, -1, -2> yx;
                swizzle2<2, vec2, 1, 1, -1, -2> yy;
            };
            // public defaults
            inline vec2() : vec2(0, 0) {};
            inline vec2(float n) : vec2(n, n) {};
            inline vec2(float x, float y) { this->x = x; this->y = y; };
        };

        /*inline vec4 operator+(const vec4 & a, const float b)
        {
            return{
                a.x + b,
                a.y + b,
                a.z + b,
                a.w + b,
            };
        }
        inline vec4 operator+=(vec4 & a, const float b)
        {
            
        };*/
    }

/**************************************************************************************************/