#include <iostream>
#include <string>
#include "external/lodepng.h"

int main(int argc, char* argv[])
{
    bool printed_dog = false;
    int width = 640;
    int height = 480;

    //iterate over the command-line arguments - http://www.cplusplus.com/articles/DEN36Up4/
    for(int i=1; i<argc; i++){
        std::string argument = argv[i];

        if(argument == "--dog"){
            std::cout << "woof, woof 🐶" << std::endl;
            printed_dog = true;
        }

        if( (argument == "--width" || argument == "-w") && (i+1 < argc) ){
            std::string next_argument = argv[i+1];
            int width_from_argument = std::stoi(next_argument);
            if(width_from_argument > 0){ width = width_from_argument; }
        }

        if( (argument == "--height" || argument == "-h") && (i+1 < argc) ){
            std::string next_argument = argv[i+1];
            int height_from_argument = std::stoi(next_argument);
            if(height_from_argument > 0){ height = height_from_argument; }
        }

    }

    //always print an animal emoji - if dog isn't desired, print a cat
    if(!printed_dog){
        std::cout << "meow 🐱" << std::endl;//
    }

    return 0;
}
