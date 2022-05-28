#include "Wall.h"
#include "Point.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string>
using namespace std;

Wall::Wall(string id, Dimensions size, Point position, Color color)
{
    this->id = id;
    this->size = *(new Dimensions(size.width,size.length,size.height));
    this->position = *(new Point(position.x, position.y, position.z));
    this->color = *(new Color(color.red,color.green,color.blue));
}

Wall::~Wall()
{
    this->position = *(new Point(0,0,0));
}

Wall::render()
{
glPushMatrix();
    glColor3f(color.red, color.green, color.blue);
    glTranslatef(position.x, position.y, position.z);
    glScalef(size.length, size.width, size.height);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(1);
glPopMatrix();
}
