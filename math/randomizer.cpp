#include "randomizer.h"
#include <random>
#include <chrono>

namespace sparkles {

static unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count();
static std::mt19937 mersenne_twister(seed);
static std::uniform_real_distribution<double> uni(0.0,1.0);

Vector3 random_vector_on_unit_sphere()
{
    //this article by Cory Simon is very helpful
    //http://corysimon.github.io/articles/uniformdistn-on-sphere/
    double theta = 2 * M_PI * uni( mersenne_twister );
    double phi = acos( 1 - 2 * uni( mersenne_twister ));
    return Vector3( sin(phi) * cos(theta), sin(phi) * sin(theta), cos(phi));
}

Vector3 random_vector_in_unit_disk()
{
    double alpha = 2 * M_PI * uni( mersenne_twister );
    double radius = uni( mersenne_twister );

    return Vector3(radius * cos(alpha), radius * sin(alpha), 0);
}

double random_between_0_and_1()
{
    return uni( mersenne_twister );
}

}
