#include "ray.h"

namespace sparkles {

Ray::Ray(const Vector3& origin, const Vector3& direction)
{
    origin_ = origin;
    direction_ = direction;
}

Ray::Ray(double ox, double oy, double oz, double dx, double dy, double dz)
{
    origin_ = Vector3(ox, oy, oz);
    direction_ = Vector3(dx, dy, dz);
}

Ray::~Ray()
{

}

}
