#include "Point.h"

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Point::Point(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::~Point()
{
    //dtor
}
