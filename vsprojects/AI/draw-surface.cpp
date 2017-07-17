//// API :: Algorithm Method Declarations ----------
//
//inline void AlgorithmDot()
//{
//    // Algorithm :: GEOMETRY -------------------------
//    // Convert world-to-screen coordinates
//    ToScreen(&rInfo.vertex[0]);
//    // Out-of-bounds check
//    if (rInfo.vertex[0].z < 0) return;
//    if (rInfo.vertex[0].x < wInfo.viewport.x) return;
//    if (rInfo.vertex[0].y < wInfo.viewport.y) return;
//    if (rInfo.vertex[0].x > wInfo.viewport.z) return;
//    if (rInfo.vertex[0].y > wInfo.viewport.w) return;
//    // -----------------------------------------------
//    // Algorithm :: FRAGMENT -------------------------
//    // Convert screen-to-index coordinates
//    int index = ToIndex(&rInfo.vertex[0]);
//    // Depth-Buffer check
//    if (rInfo.depth[index] > 0 && rInfo.depth[index] < rInfo.vertex[0].z) return;
//    // -----------------------------------------------
//    // Algorithm :: RASTERIZATION --------------------
//    rInfo.depth[index] = rInfo.vertex[0].z;
//    ccon::cconAscii(ToAscii(&rInfo.colour[0]), index);
//    ccon::cconAttrib(ToAttrib(&rInfo.colour[0]), index);
//    // -----------------------------------------------
//}
//inline void AlgorithmLine()
//{
//    // Algorithm :: GEOMETRY -------------------------
//    // Convert world-to-screen coordinates
//    ToScreen(&rInfo.vertex[0]);
//    ToScreen(&rInfo.vertex[1]);
//    // Out-of-bounds check
//    if (rInfo.vertex[0].z < 0 || rInfo.vertex[1].z < 0) return;
//    if (rInfo.vertex[0].x < wInfo.viewport.x && rInfo.vertex[1].x < wInfo.viewport.x) return;
//    if (rInfo.vertex[0].y < wInfo.viewport.y && rInfo.vertex[1].y < wInfo.viewport.y) return;
//    if (rInfo.vertex[0].x > wInfo.viewport.z && rInfo.vertex[1].x > wInfo.viewport.z) return;
//    if (rInfo.vertex[0].y > wInfo.viewport.w && rInfo.vertex[1].y > wInfo.viewport.w) return;
//    // -----------------------------------------------
//    // Algorithm :: FRAGMENT -------------------------
//    int index, i;
//    Vector2i pos;
//    // Calculate direction vectors
//    Vector4f dirVertex = rInfo.vertex[1] - rInfo.vertex[0];
//    Vector4f dirColour = rInfo.colour[1] - rInfo.colour[0];
//    float steps = std::abs(std::abs(dirVertex.x) > std::abs(dirVertex.y) ? dirVertex.x : dirVertex.y);
//    dirVertex = { dirVertex.x / steps, dirVertex.y / steps, dirVertex.z / steps, dirVertex.w / steps };
//    dirColour = { dirColour.x / (steps - 1), dirColour.y / (steps - 1), dirColour.z / (steps - 1), dirColour.w / (steps - 1) };
//    // Iterate throught each pixel
//    for (i = 0; i <= int(steps); i++)
//    {
//        // Convert to int coordinates
//        pos.x = int(rInfo.vertex[0].x + 0.5f);
//        pos.y = int(rInfo.vertex[0].y + 0.5f);
//        // Out-of-bounds-check
//        if (pos.x > -1 && pos.x < wInfo.viewsize.x)
//        {
//            if (pos.y > -1 && pos.y < wInfo.viewsize.y)
//            {
//                // Convert screen-to-index coordinates
//                index = pos.y * wInfo.viewsize.x + pos.x;
//                // Depth-Buffer check
//                float depth = rInfo.depth[index];
//                if (!(rInfo.vertex[0].z > rInfo.depth[index]) || rInfo.depth[index] == 0)
//                {
//                    // Algorithm :: RASTERIZATION --------
//                    rInfo.depth[index] = rInfo.vertex[0].z;
//                    ccon::cconAscii(ToAscii(&rInfo.colour[0]), index);
//                    ccon::cconAttrib(ToAttrib(&rInfo.colour[0]), index);
//                }
//            }
//        }
//        // Add direction vectors
//        rInfo.vertex[0] = rInfo.vertex[0] + dirVertex;
//        rInfo.colour[0] = rInfo.colour[0] + dirColour;
//    }
//    // -----------------------------------------------
//}
//inline void AlgorithmTriangle()
//{
//    // Algorithm :: GEOMETRY -------------------------
//    // Convert world-to-screen coordinates
//    ToScreen(&rInfo.vertex[0]);
//    ToScreen(&rInfo.vertex[1]);
//    ToScreen(&rInfo.vertex[2]);
//    // Out-of-bounds check
//    if (rInfo.vertex[0].z < 0 || rInfo.vertex[1].z < 0 || rInfo.vertex[2].z < 0) return;
//    if (rInfo.vertex[0].x < wInfo.viewport.x && rInfo.vertex[1].x < wInfo.viewport.x && rInfo.vertex[2].x < wInfo.viewport.x) return;
//    if (rInfo.vertex[0].y < wInfo.viewport.y && rInfo.vertex[1].y < wInfo.viewport.y && rInfo.vertex[2].y < wInfo.viewport.y) return;
//    if (rInfo.vertex[0].x > wInfo.viewport.z && rInfo.vertex[1].x > wInfo.viewport.z && rInfo.vertex[2].x > wInfo.viewport.z) return;
//    if (rInfo.vertex[0].y > wInfo.viewport.w && rInfo.vertex[1].y > wInfo.viewport.w && rInfo.vertex[2].y > wInfo.viewport.w) return;
//    // -----------------------------------------------
//    // Algorithm :: FRAGMENT -------------------------
//    //int index, i;
//    //Vector2i pos;
//
//    // -----------------------------------------------
//}


/** Dependencies **********************************************************************************/

    // dependencies
    #include "draw1.h"
    #include <ccon\win32\detail.h>

/** Declarations **********************************************************************************/

    void draw::drawRender(ccon::WIN32Buffer * buffer, DRAWDot & object)
    {

    }
    void draw::drawRender(ccon::WIN32Buffer * buffer, DRAWLine & object)
    {

    }
    void draw::drawRender(ccon::WIN32Buffer * buffer, DRAWFace & object)
    {

    }

/**************************************************************************************************/