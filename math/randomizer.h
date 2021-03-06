#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "vector3.h"

namespace sparkles {
    Vector3 random_vector_on_unit_sphere();
    Vector3 random_vector_on_unit_disk();
    //todo random_vector_on_unit_disk should be overloaded so it returns a UV
    double random_between_0_and_1();
}

#endif // RANDOMIZER_H
