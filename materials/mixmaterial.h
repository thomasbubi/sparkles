#ifndef MIXMATERIAL_H
#define MIXMATERIAL_H

#include "material.h"
#include "../textures/texture.h"

namespace sparkles {

class MixMaterial : public Material
{
    Material* material_a_;
    Material* material_b_;
    double mix_value_;
    Texture* mask_;
    Color rgb_to_bw_;
public:
    inline MixMaterial(Material* mat_a, Material* mat_b){
        material_a_ = mat_a;
        material_b_ = mat_b;
        mix_value_ = 0.5;
    }
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
        double pixel_value = mix_value_;
        if(mask_){
            Color col = mask_->get_value_at(intersection_point.x(), intersection_point.y());
            pixel_value = col.r() * 1/3 + col.g() * 1/3 + col.b() * 1/3;
            //todo use rgb_to_bw_
        }
        return  material_a_->shade(ray, intersection_point, normal, current_recursion_depth, max_recursion_depth) * (1-pixel_value) +
                material_b_->shade(ray, intersection_point, normal, current_recursion_depth, max_recursion_depth) * pixel_value;

    }
    inline void set_mask(Texture* mask){
        mask_ = mask;
        rgb_to_bw_ = Color(1/3, 1/3, 1/3);
    }
    inline void set_mask(Texture* mask, const Color& rgb_to_bw){
        mask_ = mask;
        rgb_to_bw_ = rgb_to_bw;
    }
};

}

#endif // MIXMATERIAL_H
