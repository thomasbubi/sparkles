#include "scene.h"

namespace sparkles {

    Scene::Scene()
    {
        camera_ = PerspectiveCamera();
        use_alpha_transparency_ = false;
    }

    void Scene::render(std::vector<unsigned char>& image)
    {

        double t_max = 1'000'000;

        for(unsigned int j=0; j<resolution_y_; j++){
            for(unsigned int i=0; i< resolution_x_; i++){

                Ray view_ray = camera_.create_view_ray(i, j);

                //store a pointer to the object with lowest distance in front of camera
                double t = t_max;
                Intersectable* nearest_object;

                for(unsigned int o=0; o<objects_.size(); o++){
                    Intersectable* temp_object = objects_[o];
                    double temp_t =  temp_object->intersect(view_ray);
                    //if temp_t is positive, the object is in front of camera so
                    if( temp_t >= 0 && temp_t < t){
                        nearest_object = temp_object;
                        t = temp_t;
                    }
                }

                if( t < 0 || t >= t_max ){
                    //no object was hit by ray, fill background with fully transparent pixels
                    fill_pixel( image, i, j, 0, 0, 0, use_alpha_transparency_ ? 0 : 255 );
                    continue;
                }

                if(nearest_object->get_class_name() == "Plane"){
                    fill_pixel( image, i, j, 255, 0, 0, 255);
                }

                if(nearest_object->get_class_name() == "Sphere"){
                    fill_pixel( image, i, j, 255, 255, 0, 255);
                }



            }
        }
    }

}
