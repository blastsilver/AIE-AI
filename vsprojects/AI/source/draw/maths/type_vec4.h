#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace draw
    {
        struct vec4 { union { struct { float x, y, z, w; }; struct { float r, g, b, a; }; }; };

        inline vec4 operator+(const vec4 & a, const float b)
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
            
        };
    }

/**************************************************************************************************/