#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../camera/perspectivecamera.h"
#include "../intersectables/intersectable.h"

namespace sparkles {

class Scene
{
    PerspectiveCamera camera_;
    std::vector<Intersectable*> objects_;
    //std::vector<Lamp*> lamps_;
    unsigned int resolution_x_;
    unsigned int resolution_y_;
    bool use_alpha_transparency_;

public:
    Scene();
    inline void add_object(Intersectable* obj){ objects_.push_back(obj); }
    void render(std::vector<unsigned char>& image);
    inline void set_resolution(unsigned int res_x, unsigned int res_y){
        resolution_x_ = res_x;
        resolution_y_ = res_y;
    }
    inline void set_camera( const PerspectiveCamera& cam){ camera_ = cam; }
    inline void use_alpha_transparency(){ use_alpha_transparency_ = true; }
};

}

#endif // SCENE_H
