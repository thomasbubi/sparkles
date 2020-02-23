#ifndef SHADELESSMATERIAL_H
#define SHADELESSMATERIAL_H

#include "material.h"

namespace sparkles {

class ShadelessMaterial : public Material
{
    Color color_;
public:
    ShadelessMaterial(const Color& color);
    Color shade(const Ray& ray, const Vector3& intersection_point, const Vector3& normal) const;
};

}

#endif // SHADELESSMATERIAL_H
