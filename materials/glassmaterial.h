#ifndef GLASSMATERIAL_H
#define GLASSMATERIAL_H

#include "material.h"

namespace sparkles {

class GlassMaterial : public Material
{
    Color color_;
    double ior_;//index of refraction
public:
    GlassMaterial();
    Color shade( const ShaderInput& shader_input ) const;
};

}

#endif // GLASSMATERIAL_H
