#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "Wall.h"
#include "Point.h"
#include <stdio.h>

#include <iostream>
#include <string>

#include "CameraControl.h"
#include "Maze.h"
#include "Terrain.h"
#include "SkyBox.h"
using namespace std;

CameraControl *c = new CameraControl();
Maze *maze = new Maze();
Terrain *terrain = new Terrain();
SkyBox *sky = new SkyBox();

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    sky->render();
    c->placeCamera();
    terrain->render();
    maze->render();

    glutSwapBuffers();
}

static void idle(void)
{
    glutPostRedisplay();
}


void arrowKeyListener(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            c->moveX(0.5);
            break;
        case GLUT_KEY_DOWN:
            c->moveX(-0.5);
            break;
        case GLUT_KEY_LEFT:
            c->moveY(0.5);
            break;
        case GLUT_KEY_RIGHT:
            c->moveY(-0.5);
            break;
        default:
            break;
    }
    cout<<"X ";
    cout<<c->position.x<<endl;

    cout<<"Y ";
    cout<<c->position.y<<endl;
}

void keysListener(unsigned char key, int x, int y)
{
    switch(key) {
        case 'w':
            c->moveX(0.5);
            break;
        case 's':
            c->moveX(-0.5);
            break;
        case 'a':
            c->moveY(0.5);
            break;
        case 'd':
            c->moveY(-0.5);
            break;

        case 'q':
            c->rotateY(-6);
            break;
        case 'e':
            c->rotateY(6);
            break;
        case 'r':
            c->rotateZ(6);
            break;
        case 'f':
            c->rotateZ(-6);
            break;

        case 'p':
            c->reset();
            break;
        case 'b':
            c->reset();
            c->birdsEyeView();
            break;

        default:
            break;
        }
        c->printInfo();
}

void constructMaze()
{
    //outer walls
    maze
    ->addXWalls("left",1,1,5,1)
    ->addYWalls("bottom",0.5,-1,5,-1)
    ->addYWalls("top",7.5,0,5,-1)
    ->addXWalls("right",1,-8,5,1)
    ;

    //small pieces on the outer walls
    maze
    ->setWallColor(1,0,0)
    ->addYWall("leftPiece",3.5,0)
    ->addXWall("topPiece",6.5,-2)

    ->addYWalls("rightPiece",6,-5.5,2,-1)
    ->addXWall("right1Piece",5,-5)
    ->addYWall("right2Piece",4,-5.5)
    ->addXWall("right3Piece",3.5,-6)
    ;

    //center piece
    maze
    ->setWallColor(0,0,1)
    ->addYWalls("centerBottom", 1.75, -1,4,-1)
    ->addXWall("centerSmall",2.75,-2)
    ->addXWall("centerSmall",2.25,-4.5)
    ->addYWall("centerSmall",2.75,-4)
    ->addXWalls("centerSmall",3.25,-3.5,2,1)
    ->addYWalls("centerSmall",4.75,-3,2,1)
    ;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3d Maze");
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    constructMaze();

    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    glutSpecialFunc(arrowKeyListener);
    glutKeyboardFunc(keysListener);


    glutMainLoop();

    return EXIT_SUCCESS;

}
