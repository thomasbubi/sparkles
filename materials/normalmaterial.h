#ifndef NORMALMATERIAL_H
#define NORMALMATERIAL_H

#include "material.h"

namespace sparkles {

class NormalMaterial : public Material
{
public:
    NormalMaterial();
    Color shade( const ShaderInput& shader_input ) const;
};

}

#endif // NORMALMATERIAL_H
