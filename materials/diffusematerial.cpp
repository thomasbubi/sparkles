#include "diffusematerial.h"

namespace sparkles {

DiffuseMaterial::DiffuseMaterial(const Color& color)
{
    color_ = color;
}

Color DiffuseMaterial::shade(const Ray &ray,
                           const Vector3 &intersection_point,
                           const Vector3 &normal,
                           unsigned int recursion_depth,
                           unsigned int max_recursion_depth
                        ) const
{

    if(tex_){
        return tex_->get_value_at( intersection_point.x(), intersection_point.y() );
    } else {
        return color_;
    }

}

}
