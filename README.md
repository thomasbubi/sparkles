# sparkles
Just a simple Raytracer for learning purposes

## Documentation
Note: In sparkles, the z-axis points upward

### Command-line arguments
All command-line arguments are optional, sparkles provides default values
* `--width` or `-w` | the width of the final image, has to be followed by a positive integer number (e.g. `--width 1920`)
* `--height` or `-h` | the height of the final image, has to be followed by a positive integer number (e.g. `--height 1080`)
* `--out` or `-o` | the filename of the rendered image, has to be followed by the filename, (e.g. `--out sparkles_image.png`)
* `--alpha` or `-a` | when a camera ray doesn't hit any object in the scene, the pixel will be transparent
* `--dog` | instead of _meow_, sparkles does _woof,woof_

## Books
Some books that are very useful for writing a raytraycer and for learning math:
* Peter Shirley, _Ray Tracing in One Weekend_ ([available online](https://raytracing.github.io/books/RayTracingInOneWeekend.html))
* Peter Shirley, _Ray Tracing: the Next Week_ ([available online](https://raytracing.github.io/books/RayTracingTheNextWeek.html))
* Peter Shirley, _Ray Tracing: The Rest Of Your Life_ ([available online](https://raytracing.github.io/books/RayTracingTheRestOfYourLife.html))
* J. Ström, K. Åström, and T. Akenine-Möller, _Immersive Linear Algebra_ ([available online](http://immersivemath.com/ila/index.html))
* Matt Pharr, Wenzel Jakob, and Greg Humphreys, _Physically Based Rendering, Third Edition: from Theory to Implementation_ ([available online](http://www.pbr-book.org/))
* Steve Marschner, Peter Shirley, _Fundamentals of Computer Graphics, Third Edition_
* Andrew Glassner, _An Introduction to Ray Tracing_ ([available online](http://www.realtimerendering.com/raytracing/An-Introduction-to-Ray-Tracing-The-Morgan-Kaufmann-Series-in-Computer-Graphics-.pdf))
* Kevin Suffern, _Ray Tracing from the Ground Up_
* Andrew S. Glassner, _Principles of Digital Image Synthesis_ ([available online](http://realtimerendering.com/Principles_of_Digital_Image_Synthesis_v1.0.1.pdf))

## Papers
Pixar provides a huge number of Papers [online](http://graphics.pixar.com/library/):
* Per Christensen et al., _RenderMan: An Advanced Path Tracing Architecture for MovieRendering_ ([available online](http://graphics.pixar.com/library/RendermanTog2018/paper.pdf))
* Per Christensen, Wojciech Jarosz, _The Path to Path-Traced Movies_ ([available online](http://graphics.pixar.com/library/PathTracedMovies/paper.pdf))
* Ryusuke Villemin et al., _Art and Technology at Pixar, from Toy Story to today_ ([available online](http://graphics.pixar.com/library/SigAsia2015/paper.pdf))
* Per Christensen, Henrik Wann Jebsen, _High Quality Rendering using Ray Tracing and Photon Mapping_ ([available online](http://graphics.pixar.com/library/HQRenderingCourse/paper.pdf))
* Robert L. Cook, _Stochastic Sampling in Computer Graphics_ ([available online](http://graphics.pixar.com/library/StochasticSampling/paper.pdf))

## other Resources
* [Article series by Mike Farnsborough](http://renderspud.blogspot.com/2012/04/basic-ray-tracer-stage-1.html), [code](https://github.com/Tecla/Rayito)
* [_Debugging Your Renderer_ - article by Matt Pharr](https://pharr.org/matt/blog/2020/04/26/debugging-intro.html)
* [_The Center of the Pixel is (0.5,0.5)_ - article by Eric Haines](https://www.realtimerendering.com/blog/the-center-of-the-pixel-is-0-50-5/)