#include "CameraControl.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
using namespace std;

CameraControl::CameraControl()
{
    reset();
}

CameraControl::~CameraControl()
{
    reset();
}

void CameraControl::reset()
{
    pitch = 0;
    yaw = 0;
    roll = 0;
    position = *(new Point(0.0,0.0,0.0));
    lookingAt = *(new Point(1.0,0.0,0.0));
}

double CameraControl::degreesToRadians(double degrees)
{
    return degrees*3.14159/180;
}

void CameraControl::moveX(double step)
{
    double yawRad = degreesToRadians(yaw);
    double pitchRad = degreesToRadians(pitch);

    position.x += step * cos(yawRad);
    lookingAt.x += step * cos(yawRad);

    position.y -= step * sin(yawRad);
    lookingAt.y -= step * sin(yawRad);

    //position.z -= step * sin(pitchRad);
    //lookingAt.z -= step * sin(pitchRad);
}

void CameraControl::moveZ(double step)
{
    position.z += step;
}

void CameraControl::moveY(double step)
{
    //this->position.y += step;
    //this->lookingAt.y += step;
    double yawRad = degreesToRadians(yaw - 90);
    double pitchRad = degreesToRadians(pitch);

    position.x += step * cos(yawRad);
    lookingAt.x += step * cos(yawRad);

    position.y -= step * sin(yawRad);
    lookingAt.y -= step * sin(yawRad);

    //position.z -= step * sin(pitchRad);
    //lookingAt.z -= step * sin(pitchRad);
}

void CameraControl::rotateY(double step)
{
    yaw += step;
}

void CameraControl::rotateZ(double step)
{
    pitch += step;
}

void CameraControl::rotateX(double step)
{
    roll += step;
}

void CameraControl::switchXDirection()
{
    lookingAt.x = -lookingAt.x;
}

void CameraControl::placeCamera()
{
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(
          this->position.x, this->position.y, this->position.z, /* look from camera XYZ */
          this->lookingAt.x, this->lookingAt.y, this->lookingAt.z,  /* look at the origin */
          0, 0, 1); /* positive Y up vector */

    // Set Perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 0.1, 100);

    //glTranslatef(position.x,position.y,position.z);

    glRotated(pitch,1,0,0);
    glRotated(yaw,0,1,0);
    glRotated(roll,0,0,1);

    //glTranslatef(-position.x, -position.y, -position.z);

    glMatrixMode(GL_MODELVIEW);
}

void CameraControl::printInfo()
{
        cout<<"X ";
        cout<<position.x<<endl;

        cout<<"Y ";
        cout<<position.y<<endl;

        cout<<"Looking X ";
        cout<<lookingAt.x<<endl;

        cout<<"Looking Y ";
        cout<<lookingAt.y<<endl;


        cout<<"Angle Z Pitch ";
        cout<<pitch<<endl;

        cout<<"Angle Y Yaw ";
        cout<<yaw<<endl;

        cout<<"Angle X Roll ";
        cout<<roll<<endl;
}

void CameraControl::birdsEyeView(){
    position.z = 20;
    pitch = 0;
}




