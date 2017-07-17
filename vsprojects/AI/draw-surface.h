#pragma once

namespace draw
{
    struct DRAWDot
    {
        vec2i v1;
        ccon::CCONColour c1;
    };

    struct DRAWLine
    {
        vec2i v1, v2;
        ccon::CCONColour c1, c2;
    };

    struct DRAWFace
    {
        vec2i v1, v2, v3;
        ccon::CCONColour c1, c2, c3;
    };

    void drawRender(ccon::WIN32Buffer * buffer, DRAWDot & object);
    void drawRender(ccon::WIN32Buffer * buffer, DRAWLine & object);
    void drawRender(ccon::WIN32Buffer * buffer, DRAWFace & object);
}