#ifndef PLANE_H
#define PLANE_H

#include "intersectable.h"

namespace sparkles {

class Plane : public Intersectable
{
    Vector3 position_;
    Vector3 normal_;
public:
    Plane(const Vector3& position, const Vector3& normal);
    double intersect(const Ray& ray);
};

}

#endif // PLANE_H
