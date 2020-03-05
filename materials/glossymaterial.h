#ifndef GLOSSYMATERIAL_H
#define GLOSSYMATERIAL_H

#include "material.h"

namespace sparkles {

class GlossyMaterial : public Material
{
    Color color_;
    double roughness_;
public:
    GlossyMaterial(const Color& color, double roughness);
    Color shade( const ShaderInput& shader_input ) const;
};

}

#endif // GLOSSYMATERIAL_H
