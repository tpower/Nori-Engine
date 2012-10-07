#ifndef TESTSMALLEROBJECT_H_INCLUDED
#define TESTSMALLEROBJECT_H_INCLUDED

#include "GraphicalObject.h"
#include "Rectangle.h"

class TESTSmallerObject : virtual public GraphicalObject, virtual public Rectangle
{
    private:

    public:
        TESTSmallerObject(double, double, double, double, double);
        ~TESTSmallerObject();

        void run();
        void draw(SDL_Surface* screen);

        void toggleActive(bool act);


};

#endif // TESTSMALLEROBJECT_H_INCLUDED
