#ifndef SPHERE_H
#define SPHERE_H

#include "intersectable.h"

namespace sparkles {

class Sphere : public Intersectable
{
    Vector3 position_;
    double radius_;
public:
    Sphere(const Vector3& position, double radius);
    double intersect(const Ray &ray);
};

}

#endif // SPHERE_H
