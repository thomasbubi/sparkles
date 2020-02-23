cmake_minimum_required(VERSION 2.8)

project(sparkles)
add_executable(
    ${PROJECT_NAME}
    "math/ray.cpp"
    "intersectables/intersectable.cpp"
    "intersectables/plane.cpp"
    "intersectables/sphere.cpp"
    "external/lodepng.cpp"
    "camera/perspectivecamera.cpp"
    "scene/scene.cpp"
    "main.cpp"
)
