#include "sphere.h"

namespace sparkles {

Sphere::Sphere(const Vector3 &position, double radius)
{
    position_ = position;
    radius_ = radius;
}

double Sphere::intersect(const Ray &ray)
{
    return -1.0;
}

}
