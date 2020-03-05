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
    Vector3 normal = Vector3(shader_input.normal);
    Vector3 direction = shader_input.ray.direction();
    Vector3 reflected_direction = direction - normal
            * 2.0 * Vector3::dot( direction, normal);
    Ray reflected = Ray(shader_input.intersection_point, reflected_direction);
    Color self_color( color_);
    return self_color * shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1 );
}

}
