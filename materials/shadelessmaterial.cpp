#include "shadelessmaterial.h"

namespace sparkles {

ShadelessMaterial::ShadelessMaterial( const Color& color )
{
    color_ = color;
}

Color ShadelessMaterial::shade( const ShaderInput& shader_input ) const
{
    return color_;
}

}
