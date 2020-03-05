#ifndef GLOSSYMATERIAL_H
#define GLOSSYMATERIAL_H

#include "material.h"

namespace sparkles {

class GlossyMaterial : public Material
{
    Color color_;
    double roughness_;
public:
    GlossyMaterial(const Color& color, double roughness);
    Color shade(
        const Ray& ray,
        const Vector3& intersection_point,
        const Vector3& normal,
        unsigned int current_recursion_depth,
        unsigned int max_recursion_depth
    ) const;
};

}

#endif // GLOSSYMATERIAL_H
