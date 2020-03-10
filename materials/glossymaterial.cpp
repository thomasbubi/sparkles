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

    Color self_color( color_);

    //avoid going through all the glossyness calculations if sharp mirror is desired
    if(roughness_ > 0.001){

        Color pixel_color = Color(0,0,0,1);
        //shoot Scene::spp_glossy_ rays, sum their reflected color up, and devide the
        //color with Scene::spp_glossy_
        //the higher roughness_ is, the more the reflected ray will differ from reflected_direction

        for(unsigned int i=0; i<shader_input.scene->get_spp_glossy();i++){
            Vector3 randomized_direction = Vector3(reflected_direction);
            randomized_direction += random_vector_on_unit_sphere() * roughness_;
            //start ray with little offset to avoid that ray intersects the object whose shade
            //function is currently running
            Ray reflected = Ray(
                shader_input.intersection_point + reflected_direction * 0.001,
                randomized_direction
            );
            pixel_color +=  shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1,
                                                                shader_input.pix_i, shader_input.pix_j );
        }

        pixel_color *= 1 / static_cast<double>( shader_input.scene->get_spp_glossy() );
        pixel_color.set_a(1);
        return self_color * pixel_color;

    } else {

        Ray reflected = Ray(
            //again, start ray with little offset to avoid that ray intersects the object whose shade
            //function is currently running
            shader_input.intersection_point + reflected_direction * 0.001,
            reflected_direction
        );

        return self_color * shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1,
                                                                shader_input.pix_i, shader_input.pix_j );

    }

}

}
