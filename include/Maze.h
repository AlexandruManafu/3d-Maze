#ifndef MAZE_H
#define MAZE_H

#include "Wall.h"
#include "Dimensions.h"
#include <list>

class Maze
{
    public:
        Maze();
        virtual ~Maze();
        void render();
        Maze* addXWall(string, double, double);
        Maze* addYWall(string, double, double);
        Maze* addXWalls(string, double, double, int,int);
        Maze* addYWalls(string, double, double, int,int);
        Dimensions wallSize;
        Color wallColor;
        Maze* setWallColor(double, double, double);
        list<Wall> walls;

    protected:

    private:
};

#endif // MAZE_H
