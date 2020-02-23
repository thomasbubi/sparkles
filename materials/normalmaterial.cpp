#include "normalmaterial.h"

namespace sparkles {

NormalMaterial::NormalMaterial()
{

}

Color NormalMaterial::shade(const Ray &ray, const Vector3 &intersection_point, const Vector3 &normal) const
{
    double r = normal.x();
    double g = normal.y();
    double b = normal.z();
    return Color(r,g,b,1);
}

}
