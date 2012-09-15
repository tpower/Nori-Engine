#ifndef CIRCLE_H
#define CIRCLE_H

#include "PhysicalObject.h"

class Circle : public PhysicalObject
{
    protected:
        int radius;
    public:
        Circle(int, int, int);
        ~Circle();
};

#endif // CIRCLE_H
