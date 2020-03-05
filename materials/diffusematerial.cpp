#include "diffusematerial.h"

namespace sparkles {

DiffuseMaterial::DiffuseMaterial(const Color& color)
{
    color_ = color;
}

Color DiffuseMaterial::shade( const ShaderInput& shader_input ) const
{

    if(tex_){
        return tex_->get_value_at( shader_input.intersection_point.x(), shader_input.intersection_point.y() );
    } else {
        return color_;
    }

}

}
