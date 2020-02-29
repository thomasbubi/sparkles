#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include "material.h"

namespace sparkles {

class DiffuseMaterial : public Material
{
    Color color_;
public:
    DiffuseMaterial(const Color& color);
    Color shade(
        const Ray& ray,
        const Vector3& intersection_point,
        const Vector3& normal,
        unsigned int current_recursion_depth,
        unsigned int max_recursion_depth
    ) const;
};

}

#endif // DIFFUSEMATERIAL_H
