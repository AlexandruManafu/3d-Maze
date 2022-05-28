#ifndef COLOR_H
#define COLOR_H

#include <string>
using namespace std;

class Color
{
    public:
        Color(float, float, float);
        Color();
        virtual ~Color();
        float red;
        float green;
        float blue;

        setColor(string);

    protected:

    private:
};

#endif // COLOR_H
