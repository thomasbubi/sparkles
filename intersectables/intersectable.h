#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "../math/ray.h"

namespace sparkles {

class Intersectable
{
    //AABB bounding_box_;
public:
    Intersectable();
    virtual double intersect(const Ray& ray) = 0;
    virtual std::string get_class_name() const = 0;
};

}

#endif // INTERSECTABLE_H
