#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

namespace sparkles {

class Vector3
{
public:
    inline Vector3() {
        x_ = 0.0;
        y_ = 0.0;
        z_ = 0.0;
    }

    inline Vector3(double x, double y, double z){
        x_ = x;
        y_ = y;
        z_ = z;
    }

    virtual inline ~Vector3(){}
    //getters & setters
    inline double x() const { return x_; }
    inline void set_x(double x) { x_ = x; }
    inline double y() const { return y_; }
    inline void set_y(double y) { y_ = y; }
    inline double z() const { return z_; }
    inline void set_z(double z) { z_ = z; }

    //operator overloading
    inline Vector3 operator+ (const Vector3& rhs){
        return Vector3( x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_ );
    }

    inline Vector3 operator+= (const Vector3& rhs){
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;
        return *this;
    }

    inline Vector3 operator- (const Vector3& rhs){
        return Vector3( x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_ );
    }

    inline Vector3 operator-= (const Vector3& rhs){
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        z_ -= rhs.z_;
        return *this;
    }

    inline Vector3 operator* (const double& scalar){
        return Vector3( x_ * scalar, y_ * scalar, z_ * scalar );
    }

    inline Vector3 operator*= (const double& scalar){
        x_ *= scalar;
        y_ *= scalar;
        z_ *= scalar;
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Vector3& vec){
        stream << "x:" << vec.x_ << " y:" << vec.y_ << " z:" << vec.z_;
        return stream;
    }

    //some vector math
    inline double abs2() {
        return x_*x_ + y_*y_ + z_*z_;
    }

    inline double abs(){
        return sqrt( this->abs2() );
    }

    inline void normalize(){
        double abs = this->abs();
        x_ /= abs;
        y_ /= abs;
        z_ /= abs;
    }

    inline Vector3 cross( const Vector3& lhs, const Vector3& rhs){
        return Vector3(
                lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_,
                -( lhs.x_ * rhs.z_ ) + lhs.z_ * rhs.x_,
                lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_
        );
    }

private:
    double x_;
    double y_;
    double z_;
};

}

#endif // VECTOR3_H
