#ifndef COLOR_H
#define COLOR_H

#include <iostream>

namespace sparkles {

class Color
{
    double r_;
    double g_;
    double b_;
    double a_;
public:
    inline Color(){
        r_ = 0;
        g_ = 0;
        b_ = 0;
        a_ = 1;
    }
    inline Color(double r, double g, double b){
        r_ = r;
        g_ = g;
        b_ = b;
        a_ = 1;
    }
    inline Color(double r, double g, double b, double a){
        r_ = r;
        g_ = g;
        b_ = b;
        a_ = a;
    }
    inline double r(){ return r_; }
    inline double g(){ return g_; }
    inline double b(){ return b_; }
    inline double a(){ return a_; }
    inline void clamp(){
        r_ = r_ > 1 ? 1 : r_ < 0 ? 0 : r_;
        g_ = g_ > 1 ? 1 : g_ < 0 ? 0 : g_;
        b_ = b_ > 1 ? 1 : b_ < 0 ? 0 : b_;
        a_ = a_ > 1 ? 1 : a_ < 0 ? 0 : a_;
    }

    inline Color operator+ (const Color& col){
        Color c = Color( r_ + col.r_, g_ + col.g_, b_ + col.b_, a_ + col.a_);
        c.clamp();
        return c;
    }

    inline Color operator+= (const Color& col){
        r_ += col.r_;
        g_ += col.g_;
        b_ += col.b_;
        a_ += col.a_;
        this->clamp();
        return *this;
    }

    inline Color operator- (const Color& col){
        Color c = Color( r_ - col.r_, g_ - col.g_, b_ - col.b_, a_ - col.a_);
        c.clamp();
        return c;
    }

    inline Color operator-= (const Color& col){
        r_ -= col.r_;
        g_ -= col.g_;
        b_ -= col.b_;
        a_ -= col.a_;
        this->clamp();
        return *this;
    }

    inline Color operator* (const Color& col){
        Color c = Color( r_ * col.r_, g_ * col.g_, b_ * col.b_, a_ * col.a_);
        return c;
    }

    inline Color operator*= (const Color& col){
        r_ *= col.r_;
        g_ *= col.g_;
        b_ *= col.b_;
        a_ *= col.a_;
        return *this;
    }

    inline Color operator* (const double& scalar){
        Color c = Color( r_ * scalar, g_ * scalar, b_ * scalar, a_ * scalar);
        c.clamp();
        return c;
    }

    inline Color operator*= (const double& scalar){
        r_ *= scalar;
        g_ *= scalar;
        b_ *= scalar;
        a_ *= scalar;
        this->clamp();
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Color& col){
        stream << "(r:" << col.r_ << " g:" << col.g_ << " b:" << col.b_ << " a:" << col.a_ << ")";
        return stream;
    }
};

}

#endif // COLOR_H
