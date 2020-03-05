#include "glossymaterial.h"
#include "../scene/scene.h"
#include "../math/randomizer.h"

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
    if(roughness_ > 0.001){
        reflected_direction += random_vector_on_unit_sphere() * roughness_;
    }
    Ray reflected = Ray(shader_input.intersection_point, reflected_direction);
    Color self_color( color_);
    return self_color * shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1 );
}

}
