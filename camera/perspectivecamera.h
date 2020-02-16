#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "../math/vector3.h"
#include "../math/ray.h"

namespace sparkles {

class PerspectiveCamera
{
    Vector3 position_;
    Vector3 up_;
    double aperture_;
    double focal_length_;
    double fov_;
public:
    PerspectiveCamera();
    Ray create_view_ray(unsigned int i, unsigned int j);
    inline void setPosition(const Vector3 &position){ position_ = position; }
};

}

#endif // PERSPECTIVECAMERA_H
