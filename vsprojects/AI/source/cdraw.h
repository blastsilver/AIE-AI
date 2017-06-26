#pragma once

namespace cdraw
{
    typedef unsigned int uint;

    //--------------------------------------------------------------------------------------------------
    //-- Shaders ---------------------------------------------------------------------------------------
    // :: shader creation ::

    // :: shader uniforms ::
    float * cdrawGetUniform(char * uniform);
    uint cdrawCreateUniform(char * uniform);
    void cdrawSetUniform1f(uint uniform, float n);
    void cdrawSetUniform2f(uint uniform, float x, float y);
    void cdrawSetUniform3f(uint uniform, float x, float y, float z);
    void cdrawSetUniform4f(uint uniform, float x, float y, float z, float w);
    void cdrawSetUniformM3x3f(uint uniform, float * buffer);
    void cdrawSetUniformM4x4f(uint uniform, float * buffer);
    //--------------------------------------------------------------------------------------------------
}