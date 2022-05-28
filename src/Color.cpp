#include "Color.h"

Color::Color(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color()
{
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

Color::~Color()
{
}

Color::setColor(string colorName){
    if(colorName == "ash gray")
    {
        red = 0.7;
        green = 0.75;
        blue = 0.71;
        return 0;
    }
    if(colorName.find("red") != colorName.npos)
        this->red = 1;
    if(colorName.find("green") != colorName.npos)
        this->green = 1;
    if(colorName.find("blue") != colorName.npos)
        this->blue = 1;
}
