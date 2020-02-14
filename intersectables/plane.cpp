#include "plane.h"

namespace sparkles {

Plane::Plane(const Vector3& position, const Vector3& normal)
{
    position_ = position;
    normal_ = normal;
}

double Plane::intersect(const Ray &ray)
{
    return -1.0;
}

}
