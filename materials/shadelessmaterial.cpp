#include "shadelessmaterial.h"

namespace sparkles {

ShadelessMaterial::ShadelessMaterial(const Color& color)
{
    color_ = color;
}

Color ShadelessMaterial::shade(const Ray &ray, const Vector3 &intersection_point, const Vector3 &normal) const
{
    return color_;
}

}
