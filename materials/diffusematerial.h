#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include "material.h"
#include "../textures/texture.h"

namespace sparkles {

class DiffuseMaterial : public Material
{
    Color color_;
    Texture* tex_;
public:
    DiffuseMaterial(const Color& color);
    Color shade(
        const Ray& ray,
        const Vector3& intersection_point,
        const Vector3& normal,
        unsigned int current_recursion_depth,
        unsigned int max_recursion_depth
    ) const;
    inline void set_texture(Texture* tex){ tex_ = tex; }
};

}

#endif // DIFFUSEMATERIAL_H
