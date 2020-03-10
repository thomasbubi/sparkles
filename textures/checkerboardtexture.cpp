#include "checkerboardtexture.h"

namespace sparkles {

CheckerboardTexture::CheckerboardTexture()
{
    checker_size_ = 1.0;
    color_a_ = Color(1,1,1);
    color_b_ = Color(0,0,0);
}

CheckerboardTexture::CheckerboardTexture(double checker_size)
{
    checker_size_ = checker_size;
    color_a_ = Color(1,1,1);
    color_b_ = Color(0,0,0);
}

CheckerboardTexture::CheckerboardTexture(const Color &a, const Color &b, double checker_size)
{
    checker_size_ = checker_size;
    color_a_ = a;
    color_b_ = b;
}

Color CheckerboardTexture::get_value_at(double u, double v) const
{
    int uu = static_cast<int>( (1 / checker_size_) * (u - 1'000'000) );
    int vv = static_cast<int>( (1 / checker_size_) * (v - 1'000'000) );

    if(uu < 0) { uu *= -1; }
    if(vv < 0) { vv--; vv *= -1; }

    if(uu % 2 == 1 && vv % 2 == 0){
        return color_a_;
    } else if(uu % 2 == 0 && vv % 2 == 1){
        return color_a_;
    } else {
        return color_b_;
    }

}

}
