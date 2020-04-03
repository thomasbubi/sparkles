#include <iostream>
#include <string>
#include "scene/scenehelpers.h"

int main(int argc, char* argv[])
{
    bool print_dog = false;
    unsigned long width = 600;
    unsigned long height = 400;
    std::string filename = "output.png";
    bool use_alpha_background = false;
    bool use_antialiasing = false;

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

        if( (argument == "--aa") ){
            use_antialiasing = true;
        }

        if( (argument == "--alpha" || argument == "-a") ){
            use_alpha_background = true;
        }

    }

    unsigned int final_width = static_cast<unsigned int>(width);
    unsigned int final_height = static_cast<unsigned int>(height);

    /*sparkles::Scene* glass_scene = sparkles::create_glass_scene( final_width, final_height, use_antialiasing, filename );
    glass_scene->render( image );
    delete glass_scene;*/

    //todo render cornell box with a height equal to the width
    sparkles::Scene* cornell_box_scene = sparkles::create_cornell_box_scene( final_width, use_antialiasing, filename );
    cornell_box_scene->render( );
    delete cornell_box_scene;

    //always print an animal emoji - if dog isn't desired, print a cat
    if(!print_dog){
        std::cout << "meow 🐱" << std::endl;//
    } else {
        std::cout << "woof, woof 🐶" << std::endl;
    }

    return 0;
}
