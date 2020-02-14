#include "vector3.h"

namespace sparkles {

Vector3::Vector3()
{
    x_ = 0.0;
    y_ = 0.0;
    z_ = 0.0;
}

Vector3::Vector3(double x, double y, double z)
{
    x_ = x;
    y_ = y;
    z_ = z;
}

Vector3::~Vector3()
{

}

}
