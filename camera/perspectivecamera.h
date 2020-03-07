#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "../math/vector3.h"
#include "../math/ray.h"
#include "../textures/uv.h"

namespace sparkles {

class PerspectiveCamera
{
    Vector3 position_;
    Vector3 direction_;
    Vector3 up_;
    Vector3 axis_u_;
    Vector3 axis_v_;
    Vector3 axis_w_;
    double aperture_;
    double focal_length_;
    double fov_;
    unsigned int resolution_x_;
    unsigned int resolution_y_;
    double sensor_width_;
    double sensor_height_;
    double aspect_ratio_;

public:
    inline PerspectiveCamera(){}
    PerspectiveCamera(const Vector3& pos, const Vector3& dir, double focal_length_in_mm);
    Ray create_view_ray(unsigned int i, unsigned int j, UV& uv);

    inline void setPosition(const Vector3 &position){ position_ = position; }

    inline void setResolution(unsigned int res_x, unsigned int res_y){
        resolution_x_ = res_x;
        resolution_y_ = res_y;
        aspect_ratio_ = resolution_x_ > 0 && resolution_y_ > 0 ? (float)resolution_x_ / (float)resolution_y_ : 1;
        sensor_height_ = sensor_width_ / aspect_ratio_;
    }
};

}

#endif // PERSPECTIVECAMERA_H
