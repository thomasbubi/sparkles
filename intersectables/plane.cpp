#include "plane.h"

namespace sparkles {

Plane::Plane(const Vector3& position, const Vector3& normal, Material* material) : Intersectable (material)
{
    position_ = position;
    normal_ = normal;
}

double Plane::intersect(const Ray &ray)
{
    double dot_n_pos = Vector3::dot(normal_, position_);
    double dot_n_ori = Vector3::dot(normal_, ray.origin());
    double dot_n_dir = Vector3::dot(normal_, ray.direction());
    double t = (dot_n_pos - dot_n_ori) / dot_n_dir;
    return t;
}

Vector3 Plane::get_sample_point(){
    //method isn't really useful, but is mandatory when class inherits from Intersectable
    std::cout << "Plane::get_sample_point() | ";
    std::cout << "infinite planes should not be used as light sources | ";
    std::cout << "Please don't use this as long as it doesn't return anything useful." << std::endl;
    return position_;
}

}
