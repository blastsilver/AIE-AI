#pragma once
/** Dependencies **********************************************************************************/

    #include <stdlib.h>
    #include "type-buffer.h"
    #include "type-shader.h"

/** Declarations **********************************************************************************/

    namespace draw
    {
        struct DRAWBuffer_T
        {
            int bSize;
            int sizeW;
            int sizeH;
            void * buffer;
        };

        struct DRAWShader_T
        {
            void(*vert00)(vec4 &, vec4 &);
            bool(*vert01)(vec4 &, vec4 &);
            void(*frag00)(vec4 &, vec4 &);
            bool(*frag01)(vec4 &, vec4 &);
        };
    }

/**************************************************************************************************/