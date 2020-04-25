#include "emissionmaterial.h"

namespace sparkles {

EmissionMaterial::EmissionMaterial(double energy)
{
    color_ = Color(1,1,1,1);
    energy_ = energy;
}

EmissionMaterial::EmissionMaterial(const Color &color, double energy)
{
    color_ = color;
    energy_ = energy;
}

Color EmissionMaterial::shade(const ShaderInput &shader_input) const
{
    return color_;
}

}
