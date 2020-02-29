#ifndef MIXMATERIAL_H
#define MIXMATERIAL_H

#include "material.h"

namespace sparkles {

class MixMaterial : public Material
{
    Material* material_a_;
    Material* material_b_;
    double mix_value_;
public:
    inline MixMaterial(Material* mat_a, Material* mat_b, double value){
        material_a_ = mat_a;
        material_b_ = mat_b;
        mix_value_ = value > 1.0 ? 1.0 : value < 0.0 ? 0 : value;
    }
    inline virtual ~MixMaterial(){
        delete material_a_;
        delete material_b_;
    }
    inline Color shade(
        const Ray& ray,
        const Vector3& intersection_point,
        const Vector3& normal,
        unsigned int current_recursion_depth,
        unsigned int max_recursion_depth
            ) const {
        return  material_a_->shade(ray, intersection_point, normal, current_recursion_depth, max_recursion_depth) * (1-mix_value_) +
                material_b_->shade(ray, intersection_point, normal, current_recursion_depth, max_recursion_depth) * mix_value_;

    }
};

}

#endif // MIXMATERIAL_H
