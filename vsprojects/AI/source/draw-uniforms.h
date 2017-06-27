#pragma once

namespace draw
{
    float * drawGetUniform(char * uniform);
    uint8 drawCreateUniform(char * uniform);
    void drawSetUniform1f(uint8 uniform, float n);
    void drawSetUniform2f(uint8 uniform, float x, float y);
    void drawSetUniform3f(uint8 uniform, float x, float y, float z);
    void drawSetUniform4f(uint8 uniform, float x, float y, float z, float w);
    void drawSetUniformM3x3f(uint8 uniform, float * buffer);
    void drawSetUniformM4x4f(uint8 uniform, float * buffer);
}