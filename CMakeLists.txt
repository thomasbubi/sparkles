cmake_minimum_required(VERSION 2.8)

project(sparkles)
add_executable(
    ${PROJECT_NAME}
    "math/randomizer.cpp"
    "textures/checkerboardtexture.cpp"
    "materials/shadelessmaterial.cpp"
    "materials/normalmaterial.cpp"
    "materials/diffusematerial.cpp"
    "materials/glossymaterial.cpp"
    "materials/glassmaterial.cpp"
    "intersectables/plane.cpp"
    "intersectables/sphere.cpp"
    "intersectables/rectangle.cpp"
    "external/lodepng.cpp"
    "camera/perspectivecamera.cpp"
    "scene/scene.cpp"
    "scene/scenehelpers.cpp"
    "main.cpp"
)
