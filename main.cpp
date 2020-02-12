#include <iostream>
#include <string>
#include <vector>
#include "external/lodepng.h"

int main(int argc, char* argv[])
{
    bool printed_dog = false;
    unsigned long width = 640;
    unsigned long height = 480;
    std::string filename = "output.png";

    //iterate over the command-line arguments - http://www.cplusplus.com/articles/DEN36Up4/
    for(int i=1; i<argc; i++){
        std::string argument = argv[i];

        if(argument == "--dog"){
            std::cout << "woof, woof 🐶" << std::endl;
            printed_dog = true;
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

    }

    unsigned int final_width = static_cast<unsigned int>(width);
    unsigned int final_height = static_cast<unsigned int>(height);

    std::vector<unsigned char> image(final_width * final_height * 4, 255);

    //conversion from string (command-liune argumewnts of width or height) yields an unsigned long
    //lodepng::encode expects a unsigned int though
    unsigned error = lodepng::encode( filename.c_str(), image, final_width, final_height );
    std::cout << "PNG error: " << lodepng_error_text( error ) << std::endl;

    //always print an animal emoji - if dog isn't desired, print a cat
    if(!printed_dog){
        std::cout << "meow 🐱" << std::endl;//
    }

    return 0;
}
