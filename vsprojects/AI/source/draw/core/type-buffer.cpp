#pragma once
/** Dependencies **********************************************************************************/

    #include "..\include.h"
    #include "detail.h"

    inline void * _address(void * buffer, const ccon::uint byteSize, const ccon::uint index)
    {
        int address = (int)buffer;
        address += index * byteSize;
        return (void *)address;
    }

    inline void _copy(float *& a, float *& b, const int size)
    {
        // copy buffer values
        for (int i = 0; i < size; i++) a[i] = b[i];
    }

/** Declarations **********************************************************************************/

    ccon::CCONResult draw::drawDeleteBuffer(DRAWBuffer * object)
    {
        // delete object
        if (!CCON_ISNULL(object))
        {
            free((*object)->buffer);
            CCON_DELETE_OBJECT(*object);
        }
        // return as successfull
        return ccon::CCON_SUCCESS;
    }

    ccon::CCONResult draw::drawCreateBuffer(DRAWBufferInfo * info, DRAWBuffer * object)
    {
        // check if null
        if (info == CCON_NULL)
        {
            // create object
            (*object) = new DRAWBuffer_T{};
            // copy info values
            (*object)->bSize = info->bSize;
            (*object)->sizeW = info->sizeW;
            (*object)->sizeH = info->sizeW;
            (*object)->buffer = malloc(info->sizeW * info->sizeH * info->bSize);
            // return as successfull
            return ccon::CCON_SUCCESS;
        }
        // return as failed
        return ccon::CCON_FAILURE;
    }

/**************************************************************************************************/