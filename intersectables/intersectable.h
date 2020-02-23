#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "../math/ray.h"
#include "../materials/color.h"

namespace sparkles {

class Intersectable
{
    //AABB bounding_box_;
protected:
    Color color_;
public:
    Intersectable(const Color& color);
    virtual double intersect(const Ray& ray) = 0;
    virtual std::string get_class_name() const = 0;
    virtual Vector3 get_normal_at_t( const Ray& ray, double t) = 0;
    inline Color color(){ return color_; }
};

}

#endif // INTERSECTABLE_H
