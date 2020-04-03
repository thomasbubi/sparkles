#ifndef SCENEHELPERS_H
#define SCENEHELPERS_H

#endif // SCENEHELPERS_H

#include "scene.h"

namespace sparkles {

Scene* create_glass_scene( unsigned int width, unsigned int height, bool use_aa, std::string filename );
Scene *create_cornell_box_scene( unsigned int width, bool use_aa, std::string filename );

}
