#pragma once
/** Dependencies **********************************************************************************/

    #include <ccon3.h>
    #include "draw-surface.h"

    namespace draw
    {
        // vector template
        template <typename _type> struct vec2 { _type x, y; };
        template <typename _type> struct vec3 { _type x, y, z; };
        template <typename _type> struct vec4 { _type x, y, z, w; };
        // matrix template
        template <typename _type, int _size> struct mat { _type data[_size * _size]; };
        // type definitions
        typedef vec2<int> vec2i;
        typedef vec3<int> vec3i;
        typedef vec4<int> vec4i;
        typedef vec2<float> vec2f;
        typedef vec3<float> vec3f;
        typedef vec4<float> vec4f;
        typedef mat<float, 2> mat2f;
        typedef mat<float, 3> mat3f;
        typedef mat<float, 4> mat4f;
    }

/** Declarations **********************************************************************************/
/**************************************************************************************************/