#include "plane.h"

namespace sparkles {

Plane::Plane(const Vector3& position, const Vector3& normal)
{
    position_ = position;
    normal_ = normal;
}

double Plane::intersect(const Ray &ray)
{
    //t = (dot(n, p0) - dot(n, origin)) / dot(n, direction)
    double dot_n_pos = Vector3::dot(normal_, position_);
    double dot_n_ori = Vector3::dot(normal_, ray.origin());
    double dot_n_dir = Vector3::dot(normal_, ray.direction());
    double t = (dot_n_pos - dot_n_ori) / dot_n_dir;
    return t;
}

}
