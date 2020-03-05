#include "glossymaterial.h"
#include "../scene/scene.h"

namespace sparkles {

GlossyMaterial::GlossyMaterial(const Color &color, double roughness)
{
    color_ = color;
    roughness_ = roughness;
}

Color GlossyMaterial::shade(const ShaderInput& shader_input) const
{
    Vector3 n = Vector3(shader_input.normal);
    Vector3 reflected_direction = shader_input.ray.direction() - n
            * 2.0 * Vector3::dot(shader_input.ray.direction(), n);
    Ray reflected = Ray(shader_input.intersection_point, reflected_direction);
    return shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1 );
}

}
