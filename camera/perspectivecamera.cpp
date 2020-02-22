#include "perspectivecamera.h"

namespace sparkles {

PerspectiveCamera::PerspectiveCamera(const Vector3& pos, const Vector3& dir, double focal_length_in_mm)
{
    //will be set correctly later on
    resolution_x_ = 0;
    resolution_y_ = 0;
    aspect_ratio_ = 0;

    sensor_width_ = 0.036;//digital full frame camera
    sensor_height_ = 0.024;

    position_ = pos;
    direction_ = dir;
    up_ = Vector3(0,0,1);
    focal_length_ = focal_length_in_mm / 1000;//converting from mm (unit used in photography) to meters

    /* create orthonormal coordinate system for the camera with axes u, v, w
       v is pointing upwards, w ist the negative view direction,
     */
    axis_w_ = direction_ * -1;
    axis_w_.normalize();
    axis_u_ = Vector3::cross( axis_w_, up_ );
    axis_u_.normalize();
    axis_v_ = Vector3::cross(axis_u_, axis_w_);
    axis_v_.normalize();

}

Ray PerspectiveCamera::create_view_ray(unsigned int i, unsigned int j)
{

    // (u,v) are the coordinates in the image plane
    double r = sensor_width_ / 2;
    double l = -r;
    double b = sensor_height_ / 2;
    double t = -b;
    double u = l + (r - l) * (i + 0.5) / resolution_x_;
    double v = b + (t - b) * (j + 0.5) / resolution_y_;

    Vector3 view_ray_direction = axis_w_ * -focal_length_ + axis_u_ * u + axis_v_ * v;
    view_ray_direction.normalize();
    return Ray(position_, view_ray_direction);
}

}
