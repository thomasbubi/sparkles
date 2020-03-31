#include "glassmaterial.h"
#include "../scene/scene.h"

namespace sparkles {

GlassMaterial::GlassMaterial()
{
    color_ = Color(1,1,1);
    ior_ = 1.45;
}

Color GlassMaterial::shade(const ShaderInput &shader_input) const
{
    Vector3 normal = Vector3(shader_input.normal);
    Vector3 direction = shader_input.ray.direction();
    //Vector3 reflected_direction = direction - normal
    //        * 2.0 * Vector3::dot( direction, normal);

    //using formulas described in "Fundamentals of Computer Graphics, 3rd edition", p. 304f

    double ior_in = 1.0;
    double ior_out = 1.45;
    //TODO determine if curently shaded point is on the front side or on the back side of the object
    double cos_theta = Vector3::dot(direction,normal);

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

    return shader_input.scene->color_along_ray(refracted, shader_input.current_recursion_depth +1,
                                                            shader_input.pix_i, shader_input.pix_j );

}

}
