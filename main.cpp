#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    bool printed_dog = false;

    //iterate over the command-line arguments - http://www.cplusplus.com/articles/DEN36Up4/
    for(int i=1; i<argc; i++){
        std::string argument = argv[i];
        if(argument == "--dog"){
            std::cout << "woof, woof 🐶" << std::endl;
            printed_dog = true;
        }
    }

    //always print an animal emojie - if dog isn't desired, print a cat
    if(!printed_dog){
        std::cout << "meow 🐱" << std::endl;//
    }

    return 0;
}
