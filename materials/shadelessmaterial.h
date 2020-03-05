#ifndef SHADELESSMATERIAL_H
#define SHADELESSMATERIAL_H

#include "material.h"

namespace sparkles {

class ShadelessMaterial : public Material
{
    Color color_;
public:
    ShadelessMaterial(const Color& color);
    Color shade( const ShaderInput& shader_input ) const;
};

}

#endif // SHADELESSMATERIAL_H
