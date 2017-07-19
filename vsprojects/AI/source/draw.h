#pragma once
/** Declarations **********************************************************************************/

    namespace draw
    {
        struct vec2 { union { struct { float x, y; }; struct { float r, g; }; }; };
        struct vec3 { union { struct { float x, y, z; }; struct { float r, g, b; }; }; };
        struct vec4 { union { struct { float x, y, z, w; }; struct { float r, g, b, a; }; }; };
    }

/** Dependencies **********************************************************************************/

    #include <ccon3.h>
    #include "type-algorithm.h"

/**************************************************************************************************/