#include "SkyBox.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


SkyBox::SkyBox()
{
    //ctor
}

SkyBox::~SkyBox()
{
    //dtor
}

void SkyBox::render()
{
    glClearColor(0.53,0.81,0.92,1);
}
