#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <chrono>
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
    double t_max_;//far clipping plane
    double t_min_;//near clipping plane
    unsigned int max_recursion_depth_;
    Color background_color_;

    inline void fill_pixel(
            std::vector<unsigned char>& image,
            unsigned int i, unsigned int j,
            unsigned char r, unsigned char g, unsigned char b, unsigned char a){
        unsigned int array_pos = ( j * resolution_x_ + i ) * 4;
        image[ array_pos] = r;
        image[ array_pos + 1] = g;
        image[ array_pos + 2] = b;
        image[ array_pos + 3] = a;
    }

    inline void fill_pixel(
            std::vector<unsigned char>& image,
            unsigned int i, unsigned int j,
            Color& color){
        unsigned int array_pos = ( j * resolution_x_ + i ) * 4;
        image[ array_pos]     = static_cast<unsigned char>( color.r() * 255 );
        image[ array_pos + 1] = static_cast<unsigned char>( color.g() * 255 );
        image[ array_pos + 2] = static_cast<unsigned char>( color.b() * 255 );
        image[ array_pos + 3] = static_cast<unsigned char>( color.a() * 255 );
    }
    void print_time(const std::chrono::duration<double>& render_time);

public:
    Scene();
    inline void add_object(Intersectable* obj){ objects_.push_back(obj); }
    //this function allows for recursive ray tracing, e.g. for reflection & refraction
    //using recursion instead of iteration for this yields in cleaner code
    Color color_along_ray(const Ray& ray, unsigned int recursion_depth);
    void render(std::vector<unsigned char>& image);
    inline void set_resolution(unsigned int res_x, unsigned int res_y){
        resolution_x_ = res_x;
        resolution_y_ = res_y;
        camera_.setResolution(res_x, res_y);
    }
    inline void set_camera( const PerspectiveCamera& cam){ camera_ = cam; }
    inline void set_recursion_depth( unsigned int number_of_recursions){
        max_recursion_depth_ = number_of_recursions;
    }
    inline void set_background_color(const Color& bg_color){ background_color_ = bg_color; }
    inline void use_alpha_transparency(){ use_alpha_transparency_ = true; }
};

}

#endif // SCENE_H
