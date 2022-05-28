#ifndef TERRAIN_H
#define TERRAIN_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Terrain
{
    public:
        Terrain();
        virtual ~Terrain();
        void render();

    protected:

    private:
};

#endif // TERRAIN_H
