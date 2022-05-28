#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H

#include <Point.h>
#include <math.h>

class CameraControl
{
    public:
        CameraControl();
        virtual ~CameraControl();
        void reset();
        void refresh();

        void rotateY(double);//yaw
        void rotateZ(double);//pitch
        void rotateX(double);//roll

        void moveX(double);
        void moveZ(double);
        void moveY(double);

        void switchXDirection();
        void placeCamera();
        void printInfo();

        Point position;
        Point lookingAt;

        double pitch;
        double yaw;
        double roll;

        double degreesToRadians(double);
        void birdsEyeView();


    protected:

    private:

};

#endif // CAMERACONTROL_H
