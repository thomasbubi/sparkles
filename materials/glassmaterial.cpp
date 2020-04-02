#include "glassmaterial.h"
#include "../scene/scene.h"

namespace sparkles {

GlassMaterial::GlassMaterial()
{
    color_ = Color(1,1,1);
    ior_ = 1.45;
}

double GlassMaterial::schlick_approximation(double ior, double cos_theta) const
{
    double r0_sqrt = (ior - 1.0) / (ior + 1.0);
    double r0 = r0_sqrt * r0_sqrt;
    return r0 + ( 1.0 - r0 ) * std::pow( 1.0 - cos_theta, 5.0 );
}

Color GlassMaterial::shade(const ShaderInput &shader_input) const
{
    Vector3 normal = Vector3(shader_input.normal);
    Vector3 direction = shader_input.ray.direction();

    //calculate reflected ray
    Vector3 reflected_direction = direction - normal
            * 2.0 * Vector3::dot( direction, normal);

    Ray reflected = Ray(
        //again, start ray with little offset to avoid that ray intersects the object whose shade
        //function is currently running
        shader_input.intersection_point + reflected_direction * 0.001,
        reflected_direction
    );

    //using formulas described in "Fundamentals of Computer Graphics, 3rd edition", p. 304f

    double ior_in = shader_input.is_front_face ? 1.0 : this->ior_;
    double ior_out = shader_input.is_front_face ? this->ior_ : 1.0;

    double cos_theta = Vector3::dot( direction*-1.0, normal );
    double sin_theta = sqrt( 1 - cos_theta * cos_theta );

    double reflection_probability = this->schlick_approximation( ior_in / ior_out , cos_theta );
    bool has_total_internal_reflection = ( ( ior_in / ior_out ) * sin_theta ) > 1.0;

    //total internal reflection
    if( has_total_internal_reflection ){
        return shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1,
                                                    shader_input.pix_i, shader_input.pix_j );
    }

    //calculate refracted ray
    Vector3 parallel = ( direction + normal * cos_theta ) * ( ior_in / ior_out );

    double perpendicular_under_root = ( ior_in * ior_in ) / ( ior_out * ior_out ) *
            ( 1 - ( cos_theta * cos_theta ) );
    perpendicular_under_root = 1 - perpendicular_under_root;

    Vector3 perpendicular = normal * -1 * sqrt( perpendicular_under_root );
    Vector3 refracted_direction = parallel + perpendicular;
    refracted_direction.normalize();

    //start ray with little offset (refracted_direction * 0.001) to avoid that ray intersects
    //the object whose shade function is currently running
    Ray refracted = Ray( shader_input.intersection_point + refracted_direction * 0.001,
                        refracted_direction );

    Color refracted_color = shader_input.scene->color_along_ray(refracted, shader_input.current_recursion_depth +1,
                                                            shader_input.pix_i, shader_input.pix_j );
    Color reflected_color = shader_input.scene->color_along_ray(reflected, shader_input.current_recursion_depth +1,
                                                                       shader_input.pix_i, shader_input.pix_j );

    return reflected_color * reflection_probability + refracted_color * (1-reflection_probability);

}

}
