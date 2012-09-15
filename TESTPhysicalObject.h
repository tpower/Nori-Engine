#ifndef TESTPHYSICALOBJECT_H
#define TESTPHYSICALOBJECT_H

#include "GraphicalObject.h"
#include "Rectangle.h"

class TESTPhysicalObject : virtual public GraphicalObject, virtual public Rectangle
{
    private:

    public:
        TESTPhysicalObject(double, double, double, double);
        ~TESTPhysicalObject();

        void run();
        void draw(SDL_Surface* screen);

        void toggleActive(bool act);


};

#endif // TESTPHYSICALOBJECT_H
