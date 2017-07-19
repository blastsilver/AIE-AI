#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace draw
    {
        struct DRAWVertex { vec4 pos, rgb; };
        struct DRAWShape2 { DRAWVertex v1, v2; };
        struct DRAWShape3 { DRAWVertex v1, v2, v3; };

        void drawRenderMode(int mode);
        void drawRenderShape(ccon::WIN32Buffer & buffer, DRAWVertex data);
        void drawRenderShape(ccon::WIN32Buffer & buffer, DRAWShape2 data);
        void drawRenderShape(ccon::WIN32Buffer & buffer, DRAWShape3 data);
    }

/**************************************************************************************************/