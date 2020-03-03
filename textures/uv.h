#ifndef UV_H
#define UV_H


namespace sparkles {

class UV
{
    double u_;
    double v_;
public:
    inline UV(double u, double v){ u_ = u; v_ = v; }
    inline double u(){ return u_; }
    inline double v(){ return v_; }
};

}

#endif // UV_H
