#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace draw
    {
        void drawUse(DRAWBuffer * object);
        void drawUse(DRAWShader * object);
        void drawVertex(float x, float y);
        void drawColour(const vec4 & vector4);
        void drawVertex(const vec4 & vector4);
        void drawColour(float r, float g, float b);
        void drawVertex(float x, float y, float z);
        void drawColour(float r, float g, float b, float a);
        void drawVertex(float x, float y, float z, float w);
    }

/**************************************************************************************************/