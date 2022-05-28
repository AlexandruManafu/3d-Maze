#include "Maze.h"
#include "Color.h"

#include <iostream>

Maze::Maze()
{
    this->wallSize = *(new Dimensions());
    this->wallSize.length = 1.5;
    this->wallSize.width = 0.5;
    this->wallSize.height = 1.5;
    this->wallColor = *(new Color());
    wallColor.setColor("ash gray");
}

Maze::~Maze()
{
    //dtor
}

Maze* Maze::addXWall(string id, double x, double y)
{
    Point position = *(new Point(x,y,0));

    Wall newWall = *(new Wall(id, this->wallSize,position,wallColor));
    this->walls.push_back(newWall);

    return this;
}

Maze* Maze::addYWall(string id, double x, double y)
{
    Point position = *(new Point(x,y,0));

    Dimensions sizeForY = *(new Dimensions(wallSize.length,wallSize.width,wallSize.height));

    Wall newWall = *(new Wall(id, sizeForY,position,wallColor));
    this->walls.push_back(newWall);

    return this;
}

Maze* Maze::addXWalls(string id, double x, double y, int number, int direction)
{
    for(int i = 0;i<number;i++)
    {
        double distance = i*wallSize.length*direction;
        this->addXWall(id, x + distance, y);
    }
    return this;
}

Maze* Maze::addYWalls(string id, double x, double y, int number, int direction)
{
    for(int i = 0;i<number;i++)
    {
        double distance = i*wallSize.length*direction;
        this->addYWall(id, x, y + distance);
    }
    return this;
}

Maze* Maze::setWallColor(double red, double green, double blue)
{
    this->wallColor = *(new Color(red,green,blue));
    return this;
}

void Maze::render()
{
    list<Wall>::iterator itr;
    for (itr = this->walls.begin();
        itr != this->walls.end(); itr++)
    {
        itr->render();
    }
}
