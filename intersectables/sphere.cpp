#include "sphere.h"

namespace sparkles {

Sphere::Sphere(const Vector3 &position, double radius, Material* material) : Intersectable(material)
{
    position_ = position;
    radius_ = radius;
}

double Sphere::intersect(const Ray &ray)
{
    //solving the intersection between ray and sphere uses
    //calculating the discriminant
    Vector3 origin_minus_position = ray.origin() - position_;
    double a = Vector3::dot(ray.direction(), ray.direction());
    double b = 2 * Vector3::dot(ray.direction(), origin_minus_position);
    double c = Vector3::dot(origin_minus_position, origin_minus_position) - radius_*radius_;

    double discriminant = b*b - 4*a*c;

    if(discriminant <= 0) return Intersectable::NO_INTERSECTION;

    return (-b - sqrt(discriminant) ) / 2*a;
}


Vector3 Sphere::get_sample_point(){
    return position_ + random_vector_on_unit_sphere() * radius_;
}

}
