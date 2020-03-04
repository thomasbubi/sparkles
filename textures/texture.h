#ifndef TEXTURE_H
#define TEXTURE_H

#include "../materials/color.h"

namespace sparkles {

class Texture
{
public:
    inline Texture(){};
    virtual Color get_value_at(double u, double v) const = 0;
};

}

#endif // TEXTURE_H
