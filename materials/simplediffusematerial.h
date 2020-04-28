#ifndef SIMPLEDIFFUSE_H
#define SIMPLEDIFFUSE_H

#include "material.h"

namespace sparkles {

class SimpleDiffuseMaterial : public Material
{
    Color color_;
public:
    SimpleDiffuseMaterial(const Color& color);
    Color shade( const ShaderInput& shader_input ) const;
};

}

#endif // SIMPLEDIFFUSE_H
