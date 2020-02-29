#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "../math/ray.h"
#include "../materials/material.h"

namespace sparkles {

class Intersectable
{
    //AABB bounding_box_;
protected:
    Material* material_;
public:
    inline Intersectable(Material* material){ material_ = material; }
    inline ~Intersectable(){ delete material_; }
    virtual double intersect(const Ray& ray) = 0;
    virtual std::string get_class_name() const = 0;
    virtual Vector3 get_normal_at_t( const Ray& ray, double t) = 0;
    inline Material* material(){ return material_; }
    constexpr static double NO_INTERSECTION = -1'000'000'000'000;
};

}

#endif // INTERSECTABLE_H
