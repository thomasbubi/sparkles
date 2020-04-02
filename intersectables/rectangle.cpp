#include "rectangle.h"

namespace sparkles {

Rectangle::Rectangle(const Vector3& position, const Vector3& normal, double width, double height, Material* material) : Intersectable (material)
{
    position_ = position;
    normal_ = Vector3(normal);
    normal_.normalize();
    width_ = width;
    height_ = height;

    up_ = Vector3(0,0,1);
    double dot = Vector3::dot(normal_,up_);

    if( ( dot > 0.9999 && dot < 1.0001 ) || ( dot > -1.0001 && dot < -0.9999 ) ) {
        up_ = Vector3(0,1,1);
    }

    axis_u_ = Vector3::cross(up_, normal_);
    axis_w_ = normal_ * -1;
    axis_v_ = Vector3::cross(axis_u_,axis_w_);
    axis_u_.normalize();
    axis_v_.normalize();
    axis_u_ *= width_;
    axis_v_ *= height_;
}

double Rectangle::intersect(const Ray &ray) {
    //Rectangles are planar, so get t using the code from sparkles::Plane::intersect
    double dot_n_pos = Vector3::dot(normal_, position_);
    double dot_n_ori = Vector3::dot(normal_, ray.origin());
    double dot_n_dir = Vector3::dot(normal_, ray.direction());
    double t = (dot_n_pos - dot_n_ori) / dot_n_dir;
    //now check if the hitpoint is inside the Rectangle
    //we will check the distance between the intersection point and the axes of the Rectangle
    //we have set in the constructor (axis_u_, axis_v_)
    //http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html
    Ray temp_ray = Ray(ray.origin(), ray.direction());

    Vector3 intersection_point = temp_ray.at(t);

    Vector3 on_axis_u = position_ + axis_u_;
    double diff_u = Vector3::cross(on_axis_u - position_, position_-intersection_point).abs2() /
            (on_axis_u-position_).abs2();

    Vector3 on_axis_v = position_ + axis_v_;
    double diff_v = Vector3::cross(on_axis_v - position_, position_-intersection_point).abs2() /
            (on_axis_v-position_).abs2();

    //intersection_point is in Rectangle if distance to axis_u_ is smaller than the half
    //of the height and if distance to axis_v_ is smaller than half of the width
    //we use the squared values to avoid using sqrt() for slightly better performance
    if( std::abs(diff_u) < (height_/2)*(height_/2) &&
            std::abs(diff_v) < (width_/2)*(width_/2) ){
        return t;
    } else {
        return Intersectable::NO_INTERSECTION;
    }

}

}
