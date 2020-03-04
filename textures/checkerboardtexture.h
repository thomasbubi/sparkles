#ifndef CHECKERBOARDTEXTURE_H
#define CHECKERBOARDTEXTURE_H

#include "texture.h"

namespace sparkles {

class CheckerboardTexture : public Texture
{
    double checker_size_;
    Color color_a_;
    Color color_b_;
public:
    CheckerboardTexture();
    CheckerboardTexture(double checker_size);
    CheckerboardTexture(const Color& a, const Color& b, double checker_size);
    virtual Color get_value_at(double u, double v) const;
};

}

#endif // CHECKERBOARDTEXTURE_H
