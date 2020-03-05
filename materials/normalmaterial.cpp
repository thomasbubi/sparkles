#include "normalmaterial.h"

namespace sparkles {

NormalMaterial::NormalMaterial()
{

}

Color NormalMaterial::shade( const ShaderInput& shader_input ) const
{
    double r = 0.5 + shader_input.normal.x() / 2;
    double g = 0.5 + shader_input.normal.y() / 2;
    double b = 0.5 + shader_input.normal.z() / 2;
    return Color(r,g,b,1);
}

}
