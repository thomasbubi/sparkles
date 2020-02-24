#include "normalmaterial.h"

namespace sparkles {

NormalMaterial::NormalMaterial()
{

}

Color NormalMaterial::shade(const Ray &ray, const Vector3 &intersection_point, const Vector3 &normal) const
{
    double r = 0.5 + normal.x() / 2;
    double g = 0.5 + normal.y() / 2;
    double b = 0.5 + normal.z() / 2;
    return Color(r,g,b,1);
}

}
