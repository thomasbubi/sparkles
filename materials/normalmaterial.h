#ifndef NORMALMATERIAL_H
#define NORMALMATERIAL_H

#include "material.h"

namespace sparkles {

class NormalMaterial : public Material
{
public:
    NormalMaterial();
    Color shade(
        const Ray& ray,
        const Vector3& intersection_point,
        const Vector3& normal,
        unsigned int current_recursion_depth,
        unsigned int max_recursion_depth
    ) const;
};

}

#endif // NORMALMATERIAL_H
