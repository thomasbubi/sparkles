#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../camera/perspectivecamera.h"
#include "../intersectables/intersectable.h"

namespace sparkles {

class Scene
{
    PerspectiveCamera camera_;
    //https://stackoverflow.com/questions/2160920/why-cant-we-declare-a-stdvectorabstractclass
    //todo: use smart pointers here instead of raw pointers
    std::vector<Intersectable*> objects_;
    //std::vector<Lamp*> lamps_;
    unsigned int resolution_x_;
    unsigned int resolution_y_;
    bool use_alpha_transparency_;

    void fill_pixel(std::vector<unsigned char>& image, unsigned int i, unsigned int j, unsigned char r, unsigned char g, unsigned char b, unsigned char a){
        unsigned int array_pos = ( j * resolution_x_ + i ) * 4;
        image[ array_pos] = r;
        image[ array_pos + 1] = g;
        image[ array_pos + 2] = b;
        image[ array_pos + 3] = a;
    }
public:
    Scene();
    inline void add_object(Intersectable* obj){ objects_.push_back(obj); }
    void render(std::vector<unsigned char>& image);
    inline void set_resolution(unsigned int res_x, unsigned int res_y){
        resolution_x_ = res_x;
        resolution_y_ = res_y;
        camera_.setResolution(res_x, res_y);
    }
    inline void set_camera( const PerspectiveCamera& cam){ camera_ = cam; }
    inline void use_alpha_transparency(){ use_alpha_transparency_ = true; }
};

}

#endif // SCENE_H
