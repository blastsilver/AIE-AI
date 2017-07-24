#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace draw
    {
        struct DRAWBufferInfo
        {
            int bSize;
            int sizeW;
            int sizeH;
        };

        CCON_DEFINE_HANDLE(DRAWBuffer);

        ccon::CCONResult drawDeleteBuffer(DRAWBuffer * object);
        ccon::CCONResult drawCreateBuffer(DRAWBufferInfo * info, DRAWBuffer * object);
    }

/**************************************************************************************************/