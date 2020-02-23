#ifndef SPHERE_H
#define SPHERE_H

#include "intersectable.h"

namespace sparkles {

class Sphere : public Intersectable
{
    Vector3 position_;
    double radius_;
public:
    Sphere(const Vector3& position, double radius, const Color& color);
    double intersect(const Ray &ray);
    inline std::string get_class_name() const { return "Sphere"; }
    inline Vector3 get_normal_at_t(const Ray& ray, double t) {
        //todo argument Ray should be const
        //Vector3 n = Vector3(0,0,0);//ray.at(t) - position_;
        Ray temp_ray = Ray(ray.origin(), ray.direction());
        Vector3 n = temp_ray.at(t) - position_;
        n.normalize();
        return n;
    };

};

}

#endif // SPHERE_H
