#include "glossymaterial.h"

namespace sparkles {

GlossyMaterial::GlossyMaterial(const Color &color, double roughness)
{
    color_ = color;
    roughness_ = roughness;
}

Color GlossyMaterial::shade(const Ray &ray, const Vector3 &intersection_point, const Vector3 &normal, unsigned int current_recursion_depth, unsigned int max_recursion_depth) const
{
    return Color(0,1,1);
}

}
