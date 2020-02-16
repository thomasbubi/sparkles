#include "scene.h"

namespace sparkles {

    Scene::Scene()
    {

    }

    void Scene::render(std::vector<unsigned char>& image)
    {
        //initial fill vector woth red pixels
        for(unsigned int i=0; i<resolution_x_*resolution_y_*4; i+=4){
            image[i]=255;
            image[i+1]=127;
            image[i+2]=0;
            image[i+3]=255;
        }

        for(unsigned int j=0; j<resolution_y_; j++){
            for(unsigned int i=0; i< resolution_x_; i++){

            }
        }
    }

}
