#ifndef RAY_H
#define RAY_H

#include "vector3.h"

namespace sparkles {

class Ray
{
public:
    inline Ray(const Vector3& origin, const Vector3& direction){
        origin_ = origin;
        direction_ = direction;
    }
    inline Ray(double ox, double oy, double oz, double dx, double dy, double dz){
        origin_ = Vector3(ox, oy, oz);
        direction_ = Vector3(dx, dy, dz);
    }
    virtual inline ~Ray(){}

    //getters and setters
    inline Vector3 origin() const { return origin_; }
    inline void set_origin(const Vector3 &origin) { origin_ = origin; }
    inline Vector3 direction() const { return direction_; }
    inline void set_direction(const Vector3 &direction) { direction_ = direction; }

    //get position at parameter t
    inline Vector3 at( double t) {
        return origin_ + direction_ * t;
    }

    //enable console printing
    inline friend std::ostream& operator<<(std::ostream& stream, const Ray& ray){
        stream << "--> Ray: o:" << ray.origin_ << " d:" << ray.direction_;
        return stream;
    }
private:
    Vector3 origin_;
    Vector3 direction_;
};

}

#endif // RAY_H
