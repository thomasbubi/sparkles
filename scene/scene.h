#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <array>
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
    std::vector<Intersectable*> light_sources_;
    unsigned int resolution_x_;
    unsigned int resolution_y_;
    bool use_alpha_transparency_;
    bool use_aa_;
    double t_max_;//far clipping plane
    double t_min_;//near clipping plane
    unsigned int max_recursion_depth_;
    unsigned int spp_glossy_;
    unsigned int spp_diffuse_;
    Color background_color_;
    double gamma_;
    std::string filename_;

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
        double gamma_exp = 1.0 / gamma_;
        double r = std::pow( color.r(), gamma_exp );
        double g = std::pow( color.g(), gamma_exp );
        double b = std::pow( color.b(), gamma_exp );

        image[ array_pos]     = static_cast<unsigned char>( r * 255 );
        image[ array_pos + 1] = static_cast<unsigned char>( g * 255 );
        image[ array_pos + 2] = static_cast<unsigned char>( b * 255 );
        image[ array_pos + 3] = static_cast<unsigned char>( color.a() * 255 );
    }
    void print_time(const std::chrono::duration<double>& render_time);
    std::array<UV,4> jitter_aa_samples() const;

public:
    Scene();
    inline void add_object(Intersectable* obj){
        objects_.push_back(obj);
        if(obj->material()->get_class_name() == "EmissionMaterial") light_sources_.push_back(obj);
    }
    //this function allows for recursive ray tracing, e.g. for reflection & refraction
    //using recursion instead of iteration for this yields in cleaner code
    Color color_along_ray(const Ray& ray, unsigned int recursion_depth, unsigned int i, unsigned int j);
    void render();

    inline unsigned int get_spp_glossy(){ return spp_glossy_; }
    inline unsigned int get_spp_diffuse(){ return spp_diffuse_; }

    inline std::vector<Intersectable*> const& get_light_sources() const {
        //see https://stackoverflow.com/a/21227582 for returning vectors that are members of a class
        return light_sources_;
    }

    inline void no_aa(){ use_aa_ = false; }

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
    inline void set_gamma(double new_gamma){ gamma_ = new_gamma; }
    inline void use_alpha_transparency(){ use_alpha_transparency_ = true; }
    inline void set_filename(const std::string& filename){ filename_ = filename; }
};

}

#endif // SCENE_H
