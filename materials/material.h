#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include "../math/ray.h"

namespace sparkles {

//forward declaring Scene here to avoid circular header dependency
class Scene;

struct ShaderInput {
    Scene* scene;
    const Ray& ray;
    Vector3& intersection_point;
    Vector3& normal;
    unsigned int current_recursion_depth;
    unsigned int max_recursion_depth;
};

class Material
{
public:
    inline Material(){};
    virtual Color shade( const ShaderInput& shader_input ) const = 0;
};

}

#endif // MATERIAL_H
