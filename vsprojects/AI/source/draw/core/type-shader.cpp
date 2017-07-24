/** Dependencies **********************************************************************************/

    #include "..\include.h"
    #include "detail.h"

    void _def_Callback00(draw::vec4 & data) { return; }
    bool _def_Callback01(draw::vec4 & data) { return true; }

/** Declarations **********************************************************************************/

    ccon::CCONResult draw::drawDeleteShader(DRAWShader * object)
    {
        // delete object
        CCON_DELETE_OBJECT(*object);
        // return as successfull
        return ccon::CCON_SUCCESS;
    }

    ccon::CCONResult draw::drawCreateShader(DRAWShaderInfo * info, DRAWShader * object)
    {
        // check if null
        if (info == CCON_NULL)
        {
            // create object
            (*object) = new DRAWShader_T{};
            // copy info values
            (*object)->frag00 = info->fragCallback00 != CCON_NULL ? info->fragCallback00 : _def_Callback00;
            (*object)->frag01 = info->fragCallback01 != CCON_NULL ? info->fragCallback01 : _def_Callback01;
            (*object)->vert00 = info->vertCallback00 != CCON_NULL ? info->vertCallback00 : _def_Callback00;
            (*object)->vert01 = info->vertCallback01 != CCON_NULL ? info->vertCallback01 : _def_Callback01;
            // return as successfull
            return ccon::CCON_SUCCESS;
        }
        // return as failed
        return ccon::CCON_FAILURE;
    }

/**************************************************************************************************/