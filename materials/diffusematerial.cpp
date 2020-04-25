#include "diffusematerial.h"
#include "../math/randomizer.h"
#include "../scene/scene.h"

namespace sparkles {

DiffuseMaterial::DiffuseMaterial(const Color& color)
{
    color_ = color;
}

Color DiffuseMaterial::shade( const ShaderInput& shader_input ) const
{

    //http://viclw17.github.io/2018/07/20/raytracing-diffuse-materials/

    Color temp_color;

    if(tex_){
        temp_color = tex_->get_value_at( shader_input.intersection_point.x(), shader_input.intersection_point.y() );
    } else {
        temp_color = color_;
    }

    //double amount_of_reflection = 1.0/3.0 * temp_color.r() + 1.0/3.0 * temp_color.g() + 1.0/3.0 * temp_color.b();

    Color return_color;

    unsigned int diffuse_samples = shader_input.current_recursion_depth == 0 ? shader_input.scene->get_spp_diffuse() : 1;
    return_color = Color(0,0,0,1);

    for(unsigned int i=0; i<diffuse_samples; i++){
        Vector3 bounce_dir = Vector3(shader_input.normal) + random_vector_on_unit_sphere();
        Ray bounce = Ray(shader_input.intersection_point + bounce_dir * 0.001,
                         bounce_dir);

        return_color += temp_color * shader_input.scene->color_along_ray(bounce, shader_input.current_recursion_depth +1,
                                                                      shader_input.pix_i, shader_input.pix_j) * 0.5;
    }

    return_color *= 1 /static_cast<double>(diffuse_samples);
    return_color.set_a(1);

    return return_color;
}

}
