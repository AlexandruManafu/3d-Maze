#ifndef WALL_H
#define WALL_H

#include "Point.h"
#include "Dimensions.h"
#include "Color.h"
#include <string>
using namespace std;

class Wall
{
    public:
        Wall(string, Dimensions, Point, Color);
        virtual ~Wall();
        render();
        Point position;
        Dimensions size;
        string id;
        Color color;

    protected:

    private:
};

#endif // WALL_H
