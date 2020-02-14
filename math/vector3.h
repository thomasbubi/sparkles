#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

namespace sparkles {

class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double z);
    virtual ~Vector3();
    //getters & setters
    inline double x() const { return x_; }
    inline void set_x(double x) { x_ = x; }
    inline double y() const { return y_; }
    inline void set_y(double y) { y_ = y; }
    inline double z() const { return z_; }
    inline void set_z(double z) { z_ = z; }

private:
    double x_;
    double y_;
    double z_;
};

}

#endif // VECTOR3_H
