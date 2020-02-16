#ifndef RAY_H
#define RAY_H

#include "vector3.h"

namespace sparkles {

class Ray
{
public:
    Ray(const Vector3& origin, const Vector3& direction);
    Ray(double ox, double oy, double oz, double dx, double dy, double dz);
    virtual ~Ray();

    //getters and setters
    inline Vector3 origin() const { return origin_; }
    inline void set_origin(const Vector3 &origin) { origin_ = origin; }
    inline Vector3 direction() const { return direction_; }
    inline void set_direction(const Vector3 &direction) { direction_ = direction; }

    //get position at parameter t
    inline Vector3 at( double t) { return origin_ + direction_ * t; }
private:
    Vector3 origin_;
    Vector3 direction_;
};

}

#endif // RAY_H
