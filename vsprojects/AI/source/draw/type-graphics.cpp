/** Dependencies **********************************************************************************/

    #include "include.h"
    #include "detail.h"

    static draw::DRAWBuffer * _drawBuffer = CCON_NULL;
    static draw::DRAWShader * _drawShader = CCON_NULL;
    static draw::_DRAWGraphics _drawGraphics = {};

/** Declarations **********************************************************************************/

    namespace draw
    {
        void drawUse(DRAWShader * object)
        {
            // set current object
            _drawShader = object;
        }

        void drawUse(DRAWBuffer * object)
        {
            // set current object
            _drawBuffer = object;
        }
    
        void drawVertex(float x, float y)
        {

        }

        void drawColour(const vec4 & vector4)
        {

        }

        void drawVertex(const vec4 & vector4)
        {

        }

        void drawColour(float r, float g, float b)
        {

        }

        void drawVertex(float x, float y, float z)
        {

        }

        void drawColour(float r, float g, float b, float a)
        {

        }

        void drawVertex(float x, float y, float z, float w)
        {

        }
    }

/**************************************************************************************************/