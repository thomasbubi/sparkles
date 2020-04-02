#include "../math/vector3.h"
#include "../camera/perspectivecamera.h"
#include "../intersectables/plane.h"
#include "../intersectables/sphere.h"
#include "../intersectables/rectangle.h"
#include "../materials/shadelessmaterial.h"
#include "../materials/normalmaterial.h"
#include "../materials/mixmaterial.h"
#include "../materials/diffusematerial.h"
#include "../materials/glossymaterial.h"
#include "../materials/glassmaterial.h"
#include "../textures/checkerboardtexture.h"
#include "scenehelpers.h"

namespace sparkles {

Scene *create_glass_scene( unsigned int width, unsigned int height, bool use_aa )
{
    PerspectiveCamera camera(
        Vector3( 0, 0.5, 0.75 ),
        Vector3( 0, -1, 0 ),
        35
    );

    DiffuseMaterial* plane_mat  = new DiffuseMaterial( Color(1, 1, 0) );
    plane_mat->set_texture( new CheckerboardTexture() );

    Plane* plane = new Plane(
        Vector3( 0, 0, 0 ),
        Vector3( 0, 0, 1 ),
        //new ShadelessMaterial( Color(0.4,0.4,0.4) )
        plane_mat
    );

    //GlossyMaterial* sphere_mat = new GlossyMaterial(Color(0,1,1),0);
    GlassMaterial* sphere_mat = new GlassMaterial();

    //make glass balls hollow by putting another one with 96% of the outer radius inside
    //https://www.realtimerendering.com/blog/about-that-glass-ball/
    Sphere* sphere = new Sphere(
        Vector3(-0.7,-2,0.5),
        0.5,
        sphere_mat
    );
    Sphere* sphere_inner = new Sphere(
        Vector3( -0.7, -2, 0.5),
        0.48,
        sphere_mat
    );
    Sphere* sphere2 = new Sphere(
        Vector3( 0.7, -2, 0.5),
        0.5,
        sphere_mat
    );

    Sphere* sphere2_inner = new Sphere(
        Vector3(0.7,-2,0.5),
        0.48,
        sphere_mat
    );
    Rectangle* rect = new Rectangle(
        Vector3( 0.5, -3.5, 0.5 ),
        Vector3( 0, -1 ,0 ),
        1, 1,
        sphere_mat
    );

    Scene* scene = new Scene{};
    scene->add_object( plane );
    scene->add_object( sphere );
    scene->add_object( sphere_inner );
    scene->add_object( sphere2 );
    scene->add_object( sphere2_inner );
    scene->set_camera( camera );
    scene->set_resolution( width, height );
    scene->no_aa();

    if( use_aa ) scene->use_alpha_transparency();

    return scene;
}

Scene *create_cornell_box_scene( unsigned int width, unsigned int height, bool use_aa )
{

    PerspectiveCamera camera(
        Vector3( 0, 3.6, 1 ),
        Vector3( 0, -1, 0 ),
        50
    );


    Material* grey = new ShadelessMaterial( Color( 0.8, 0.8, 0.8 ) );
    Material* red = new ShadelessMaterial( Color( 0.8, 0, 0 ) );
    Material* green = new ShadelessMaterial( Color( 0, 0.8, 0 ) );
    Material* light_mat = new ShadelessMaterial( Color( 1, 1, 1 ) );
    Material* glass = new GlassMaterial( );

    Rectangle* bottom = new Rectangle(
        Vector3( 0, 0, 0 ),
        Vector3( 0, 0, 1 ),
        2, 2,
        grey
    );

    Rectangle* top = new Rectangle(
        Vector3( 0, 0, 2 ),
        Vector3( 0, 0, -1 ),
        2, 2,
        grey
    );

    Rectangle* back = new Rectangle(
        Vector3( 0, -1, 1 ),
        Vector3( 0, 1, 0 ),
        2, 2,
        grey
    );

    Rectangle* left = new Rectangle(
        Vector3( -1, 0, 1 ),
        Vector3( 1, 0, 0 ),
        2, 2,
        red
    );

    Rectangle* right = new Rectangle(
        Vector3( 1, 0, 1 ),
        Vector3( -1, 0, 0 ),
        2, 2,
        green
    );

    Sphere* sphere = new Sphere(
        Vector3( -0.4, 0.4, 0.25 ),
        0.25,
        glass
    );

    Rectangle* light = new Rectangle(
        Vector3( 0, 0, 1.999 ),
        Vector3( 0, 0, -1 ),
        0.3, 0.3,
        light_mat
    );

    Scene* scene = new Scene{};
    scene->add_object( bottom );
    scene->add_object( top );
    scene->add_object( back );
    scene->add_object( left );
    scene->add_object( right );
    scene->add_object( sphere );
    scene->add_object( light );
    scene->set_camera( camera );
    scene->set_resolution( width, height );
    scene->no_aa();

    if( use_aa ) scene->use_alpha_transparency();

    return scene;

}



}