#ifndef DIFFUSEMATERIAL_H
#define DIFFUSEMATERIAL_H

#include "material.h"
#include "../textures/texture.h"

namespace sparkles {

class DiffuseMaterial : public Material
{
    Color color_;
    Texture* tex_;//TODO use smart pointers here
public:
    DiffuseMaterial(const Color& color);
    Color shade( const ShaderInput& shader_input ) const;
    inline void set_texture(Texture* tex){ tex_ = tex; }
};

}

#endif // DIFFUSEMATERIAL_H
