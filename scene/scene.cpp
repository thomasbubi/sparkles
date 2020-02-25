#include "scene.h"

namespace sparkles {

Scene::Scene()
{
    camera_ = PerspectiveCamera();
    use_alpha_transparency_ = false;
    t_max_ = 1'000'000.0;
    t_min_ = 0.05;
    max_recursion_depth_ = 3;
}

Color Scene::color_along_ray(const Ray& ray, unsigned int i, unsigned int j, unsigned int recursion_depth, std::vector<unsigned char>& image)
{
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

    return nearest_object->material()->shade(ray, intersection_point, normal, recursion_depth, max_recursion_depth_);
}

void Scene::render(std::vector<unsigned char>& image)
{
    unsigned int number_of_threads = std::thread::hardware_concurrency();
    std::cout << "sparkles will calculate " << number_of_threads << " pixels parallel." << std::endl;

    auto time_begin = std::chrono::system_clock::now();

    for(unsigned int j=0; j<resolution_y_; j++){
        for(unsigned int i=0; i< resolution_x_; i++){

            const Ray view_ray = camera_.create_view_ray(i, j);
            Color c = color_along_ray(view_ray, i,j,0,image);
            fill_pixel(image,i,j,c);

        }
    }

    auto time_end = std::chrono::system_clock::now();
    std::chrono::duration<double> render_time = time_end - time_begin;
    std::cout << "rendering took " << render_time.count() << " seconds."  << std::endl;
}

}
