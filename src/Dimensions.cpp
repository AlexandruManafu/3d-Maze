#include "Dimensions.h"

Dimensions::Dimensions(double width, double length, double height)
{
    this->width = width;
    this->length = length;
    this->height = height;
}

Dimensions::Dimensions()
{
    this->width = 1;
    this->length = 1;
    this->height = 1;
}

Dimensions::~Dimensions()
{
    //dtor
}
