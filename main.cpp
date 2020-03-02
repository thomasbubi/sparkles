#include <iostream>
#include <string>
#include <vector>
#include "external/lodepng.h"
#include "math/vector3.h"
#include "scene/scene.h"
#include "camera/perspectivecamera.h"
#include "intersectables/plane.h"
#include "intersectables/sphere.h"
#include "intersectables/rectangle.h"
#include "materials/shadelessmaterial.h"
#include "materials/normalmaterial.h"
#include "materials/mixmaterial.h"
#include "materials/diffusematerial.h"

int main(int argc, char* argv[])
{
    bool print_dog = false;
    unsigned long width = 600;
    unsigned long height = 400;
    std::string filename = "output.png";
    bool use_alpha_background = false;

    //iterate over the command-line arguments - http://www.cplusplus.com/articles/DEN36Up4/
    for(int i=1; i<argc; i++){
        std::string argument = argv[i];

        if(argument == "--dog"){
            print_dog = true;
        }

        if( (argument == "--width" || argument == "-w") && (i+1 < argc) ){
            std::string next_argument = argv[i+1];
            unsigned long width_from_argument = std::stoul(next_argument);
            if(width_from_argument > 0){ width = width_from_argument; }
        }

        if( (argument == "--height" || argument == "-h") && (i+1 < argc) ){
            std::string next_argument = argv[i+1];
            unsigned long height_from_argument = std::stoul(next_argument);
            if(height_from_argument > 0){ height = height_from_argument; }
        }

        if( (argument == "--out" || argument == "-o") && (i+1 < argc) ){
            filename = argv[i+1];
        }

        if( (argument == "--alpha" || argument == "-a") ){
            use_alpha_background = true;
        }

    }

    unsigned int final_width = static_cast<unsigned int>(width);
    unsigned int final_height = static_cast<unsigned int>(height);

    //initial fill image with white pixels and
    //set the std::vector containing the pixels to the right size
    std::vector<unsigned char> image(final_width * final_height * 4, 255);

    sparkles::PerspectiveCamera camera(
        sparkles::Vector3(0,0.5,0.5),
        sparkles::Vector3(0,-1,0),
        35
    );

    sparkles::Plane* plane = new sparkles::Plane(
        sparkles::Vector3(0,0,0),
        sparkles::Vector3(0,0,1),
        //new sparkles::ShadelessMaterial( sparkles::Color(0.4,0.4,0.4) )
        new sparkles::NormalMaterial()
    );

    /*sparkles::Sphere* sphere = new sparkles::Sphere(
        sparkles::Vector3(-0.2,-2,0.5),
        0.5,
        new sparkles::MixMaterial(
            new sparkles::DiffuseMaterial(sparkles::Color(1,1,1)),
                    new sparkles::NormalMaterial(), 0.0
        )
    );*/
    sparkles::Rectangle* rect = new sparkles::Rectangle(
        sparkles::Vector3(0,-3,0.5),
        sparkles::Vector3(0,-1,0),
        1, 1,
        new sparkles::DiffuseMaterial(sparkles::Color(1,1,1))
    );

    sparkles::Scene scene{};
    scene.add_object(plane);
    scene.add_object(rect);
    scene.set_camera(camera);
    scene.set_resolution(final_width, final_height);
    if(use_alpha_background) scene.use_alpha_transparency();
    scene.render(image);

    //TEST
    //
    /*sparkles::Vector3* a = new sparkles::Vector3(1,2,3);
    sparkles::Vector3* b = new sparkles::Vector3(-7,8,9);
    //sparkles::Vector3 c = *a + *b;
    std::cout << sparkles::Vector3::cross(*a,*b) << std::endl;*/

    //conversion from string (command-liune argumewnts of width or height) yields an unsigned long
    //lodepng::encode expects a unsigned int though
    unsigned error = lodepng::encode( filename.c_str(), image, final_width, final_height );
    std::cout << "PNG error: " << lodepng_error_text( error ) << std::endl;

    //always print an animal emoji - if dog isn't desired, print a cat
    if(!print_dog){
        std::cout << "meow 🐱" << std::endl;//
    } else {
        std::cout << "woof, woof 🐶" << std::endl;
    }

    return 0;
}
