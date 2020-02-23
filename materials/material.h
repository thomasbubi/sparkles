#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include "../math/ray.h"

namespace sparkles {

class Material
{
public:
    inline Material(){};
    virtual Color shade(const Ray& ray, const Vector3& intersection_point, const Vector3& normal) const = 0;
};

}

#endif // MATERIAL_H
