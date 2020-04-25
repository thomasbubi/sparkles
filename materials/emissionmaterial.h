#ifndef EMISSIONMATERIAL_H
#define EMISSIONMATERIAL_H

#include "material.h"

namespace sparkles {

class EmissionMaterial : public Material
{
    Color color_;
    double energy_;
public:
    EmissionMaterial(double energy);
    EmissionMaterial(const Color& color, double energy);
    Color shade( const ShaderInput& shader_input ) const;
    virtual inline std::string get_class_name() const {return "EmissionMaterial"; };
};

}

#endif // EMISSIONMATERIAL_H
