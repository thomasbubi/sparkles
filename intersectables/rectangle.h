#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "intersectable.h"

namespace sparkles {

class Rectangle : public Intersectable
{
    Vector3 normal_;
    double width_;
    double height_;
    Vector3 up_;
    Vector3 axis_u_;
    Vector3 axis_w_;
    Vector3 axis_v_;
public:
    Rectangle(const Vector3& position, const Vector3& normal, double width, double height, Material* material);
    double intersect(const Ray &ray);
    inline std::string get_class_name() const { return "Rectangle"; }
    inline Vector3 get_normal_at_t(const Ray& ray, double t) { return normal_; }
    Vector3 get_sample_point();

};

}

#endif // RECTANGLE_H
