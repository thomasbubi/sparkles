#include "simplediffusematerial.h"

namespace sparkles {

SimpleDiffuseMaterial::SimpleDiffuseMaterial(const Color &color)
{
    color_ = color;
}

Color SimpleDiffuseMaterial::shade(const ShaderInput &shader_input) const
{
    return color_;
}

}
