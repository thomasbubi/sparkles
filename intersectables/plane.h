#ifndef PLANE_H
#define PLANE_H

#include "intersectable.h"

namespace sparkles {

class Plane : public Intersectable
{
    Vector3 normal_;
public:
    Plane(const Vector3& position, const Vector3& normal, Material* material);
    double intersect(const Ray& ray);
    inline std::string get_class_name() const { return "Plane"; }
    inline Vector3 get_normal_at_t( const Ray& ray, double t) {return normal_; }
};

}

#endif // PLANE_H
