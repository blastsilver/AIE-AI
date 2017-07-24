#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace draw
    {
        struct DRAWShaderInfo
        {
            void(*vertCallback00)(vec4 &);
            bool(*vertCallback01)(vec4 &);
            void(*fragCallback00)(vec4 &);
            bool(*fragCallback01)(vec4 &);
        };

        CCON_DEFINE_HANDLE(DRAWShader);

        ccon::CCONResult drawDeleteShader(DRAWShader * object);
        ccon::CCONResult drawCreateShader(DRAWShaderInfo * info, DRAWShader * object);
    }

/**************************************************************************************************/