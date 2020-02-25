#include "shadelessmaterial.h"

namespace sparkles {

ShadelessMaterial::ShadelessMaterial( const Color& color )
{
    color_ = color;
}

Color ShadelessMaterial::shade(const Ray &ray,
                           const Vector3 &intersection_point,
                           const Vector3 &normal,
                           unsigned int recursion_depth,
                           unsigned int max_recursion_depth
                        ) const
{
    return color_;
}

}
