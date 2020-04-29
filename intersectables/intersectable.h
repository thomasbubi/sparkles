#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "../math/ray.h"
#include "../materials/material.h"
#include "../math/randomizer.h"

namespace sparkles {

class Intersectable
{
    //AABB bounding_box_;
protected:
    Material* material_;
    Vector3 position_;
public:
    inline Intersectable(Material* material){ material_ = material; }
    inline ~Intersectable(){ delete material_; }
    virtual double intersect(const Ray& ray) = 0;
    virtual inline std::string get_class_name() const {return ""; };
    virtual Vector3 get_normal_at_t( const Ray& ray, double t) = 0;
    virtual Vector3 get_sample_point() = 0;
    inline Material* material(){ return material_; }
    inline Vector3 position() const { return position_; }//todo check for unnecessary copying
    constexpr static double NO_INTERSECTION = -1'000'000'000'000;
};

}

#endif // INTERSECTABLE_H
