#include "Terrain.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Terrain::Terrain()
{
    //ctor
}

Terrain::~Terrain()
{
    //dtor
}

void Terrain::render()
{
    glPushMatrix();

    glColor3f(0,0.5,0);
    glScalef(1000, 1000, 1);
    glTranslatef(0, 0, -1.25);

    glutSolidCube(1);

    glPopMatrix();
}
