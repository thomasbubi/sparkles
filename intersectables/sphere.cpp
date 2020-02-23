#include "sphere.h"

namespace sparkles {

Sphere::Sphere(const Vector3 &position, double radius, const Color& color) : Intersectable(color)
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

    if(discriminant <= 0) return -1'000'000;

    return (-b - sqrt(discriminant) ) / 2*a;
}

}
