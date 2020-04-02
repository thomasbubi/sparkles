#include <iostream>
#include <string>
#include <vector>
#include "external/lodepng.h"
#include "scene/scenehelpers.h"

int main(int argc, char* argv[])
{
    bool print_dog = false;
    unsigned long width = 600;
    unsigned long height = 600;
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
    std::vector<unsigned char> image( final_width * final_height * 4, 255 );

    /*sparkles::Scene* glass_scene = sparkles::create_glass_scene( final_width, final_height, use_alpha_background );
    glass_scene->render( image );
    delete glass_scene;*/

    //todo render cornell box with a height equal to the width
    sparkles::Scene* cornell_box_scene = sparkles::create_cornell_box_scene( final_width, final_height, use_alpha_background );
    cornell_box_scene->render( image );
    delete cornell_box_scene;

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
