#include "scene.h"
#include <thread>
#include <vector>
#include "../external/lodepng.h"

namespace sparkles {

Scene::Scene()
{
    camera_ = PerspectiveCamera();
    use_alpha_transparency_ = false;
    t_max_ = 1'000'000.0;
    t_min_ = 0.05;
    max_recursion_depth_ = 3;
    background_color_ = Color(0.5,0.5,0.5);
    spp_glossy_ = 10;
    spp_diffuse_ = 100;
    use_aa_ = true;
    gamma_ = 2.2;
    filename_ = "output.png";
}

void Scene::print_time(const std::chrono::duration<double> &render_time)
{
    double render_time_in_seconds = render_time.count();

    std::string output = "rendering took ";

    if(render_time_in_seconds >= 60.0){
        int minutes = static_cast<int>( render_time_in_seconds / 60 );
        int seconds = static_cast<int>( fmod( render_time_in_seconds, 60.0 ) );
        output += std::to_string(minutes) + " minutes and " + std::to_string(seconds) +  " seconds.";
    } else {
        output += std::to_string(render_time_in_seconds) + " seconds";
    }

    std::cout << output << std::endl;
}

std::array<UV, 4> Scene::jitter_aa_samples() const
{
    UV top_left = UV( 0.5 * random_between_0_and_1(), 0.5 * random_between_0_and_1() );
    UV top_right = UV( 0.5 * random_between_0_and_1() + 0.5, 0.5 * random_between_0_and_1() );
    UV bottom_left = UV( 0.5 * random_between_0_and_1(), 0.5 * random_between_0_and_1() + 0.5 );
    UV bottom_right = UV( 0.5 * random_between_0_and_1() + 0.5, 0.5 * random_between_0_and_1() + 0.5 );

    return {top_left, top_right, bottom_left, bottom_right};
}

Color Scene::color_along_ray(const Ray& ray, unsigned int recursion_depth, unsigned int i, unsigned int j)
{
    if(recursion_depth > max_recursion_depth_) { return Color(0,0,0); }

    //store a pointer to the object with lowest distance in front of camera
    double t = t_max_;
    Intersectable* nearest_object;

    for(unsigned int o=0; o<objects_.size(); o++){
        Intersectable* temp_object = objects_[o];
        double temp_t =  temp_object->intersect(ray);
        //if temp_t is positive, the object is in front of camera so
        if( temp_t >= 0 && temp_t < t){
            nearest_object = temp_object;
            t = temp_t;
        }
    }

    //use t_min_ (the near clipping plane) only when camera ray is traced through the scene,
    //not when reflected rays are traced
    if( t <= (recursion_depth > 0 ? 0.000001 : t_min_) || t >= t_max_ ){
        //if no object was hit by ray, fill background with fully transparent pixels
        //fill_pixel( image, i, j, 0, 0, 0, use_alpha_transparency_ ? 0 : 255 );
        if( use_alpha_transparency_ ){
            Color bg = Color(
                        background_color_.r(),
                        background_color_.g(),
                        background_color_.b(),
                        recursion_depth == 0 ? 0 : 1
                    );
            return bg;
        } else {
            return background_color_;
        }
    }

    //change ray::at so copying view ray is not necessary
    Ray temp_ray = Ray( ray.origin(), ray.direction() );
    Vector3 intersection_point = temp_ray.at(t);
    Vector3 normal = nearest_object->get_normal_at_t(ray, t);
    bool is_front_face = Vector3::dot(ray.direction(), normal) < 0;

    struct ShaderInput args{this, ray, intersection_point, normal, is_front_face, recursion_depth, max_recursion_depth_, i,j};

    return nearest_object->material()->shade(args);
}

void Scene::render()
{
    unsigned int number_of_threads = std::thread::hardware_concurrency();
    std::cout << "sparkles will calculate " << number_of_threads << " pixels parallel." << std::endl;

    //initial fill image with white pixels and
    //set the std::vector containing the pixels to the right size
    std::vector<unsigned char> image( resolution_x_ * resolution_y_ * 4, 255 );

    auto time_begin = std::chrono::system_clock::now();

    for(unsigned int j=0; j<resolution_y_; j++){
        //print render progress in console - this line overwrites itself
        double progress = static_cast<int>( static_cast<double>(j) / static_cast<double>(resolution_y_) * 100 );
        std::cout << "rendered: " << progress << "%\r" << std::flush;

        for(unsigned int i=0; i< resolution_x_; i++){

            if(use_aa_){
                std::array<UV,4> uvs = this->jitter_aa_samples();
                Color pixel_color = Color(0,0,0);
                for(unsigned int aa_samples=0; aa_samples<4;aa_samples++){
                    const Ray view_ray = camera_.create_view_ray(i, j, uvs[aa_samples]);
                    pixel_color += color_along_ray(view_ray, 0, i, j);
                }
                pixel_color *= 0.25;
                pixel_color.set_a(1);
                fill_pixel( image, i, j, pixel_color );
            } else {
                UV uv = UV(0.5,0.5);
                const Ray view_ray = camera_.create_view_ray(i, j, uv);
                Color c = color_along_ray(view_ray, 0,i,j);
                fill_pixel( image, i, j, c );
            }


        }
    }

    auto time_end = std::chrono::system_clock::now();
    print_time( time_end - time_begin );

    //conversion from string (command-liune argumewnts of width or height) yields an unsigned long
    //lodepng::encode expects a unsigned int though
    unsigned error = lodepng::encode( filename_.c_str(), image, resolution_x_, resolution_y_ );
    std::cout << "PNG error: " << lodepng_error_text( error ) << std::endl;

}

}
