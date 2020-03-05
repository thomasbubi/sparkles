#include "scene.h"
#include <thread>

namespace sparkles {

Scene::Scene()
{
    camera_ = PerspectiveCamera();
    use_alpha_transparency_ = false;
    t_max_ = 1'000'000.0;
    t_min_ = 0.05;
    max_recursion_depth_ = 3;
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

Color Scene::color_along_ray(const Ray& ray, unsigned int recursion_depth)
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


    if( t <= t_min_ || t >= t_max_ ){
        //if no object was hit by ray, fill background with fully transparent pixels
        //fill_pixel( image, i, j, 0, 0, 0, use_alpha_transparency_ ? 0 : 255 );
        return Color(0,0,0, use_alpha_transparency_ ? 0 : 1);
    }

    //change ray::at so copying view ray is not necessary
    Ray temp_ray = Ray( ray.origin(), ray.direction() );
    Vector3 intersection_point = temp_ray.at(t);
    Vector3 normal = nearest_object->get_normal_at_t(ray, t);

    struct ShaderInput args{this, ray, intersection_point, normal, recursion_depth, max_recursion_depth_};

    return nearest_object->material()->shade(args);
}

void Scene::render(std::vector<unsigned char>& image)
{
    unsigned int number_of_threads = std::thread::hardware_concurrency();
    std::cout << "sparkles will calculate " << number_of_threads << " pixels parallel." << std::endl;

    auto time_begin = std::chrono::system_clock::now();

    for(unsigned int j=0; j<resolution_y_; j++){
        for(unsigned int i=0; i< resolution_x_; i++){

            const Ray view_ray = camera_.create_view_ray(i, j);
            Color c = color_along_ray(view_ray, 0);
            fill_pixel(image,i,j,c);

        }
    }

    auto time_end = std::chrono::system_clock::now();
    print_time( time_end - time_begin );
}

}
