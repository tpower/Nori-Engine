#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Vector>

#include "PhysicalObject.h"

class Rectangle : public PhysicalObject
{
    protected:
        vect    dimensions;

    public:
        Rectangle(int, int, int, int);
        ~Rectangle();

        void                    run();
        void                    toggleActive(bool);
        void                    recalculateRelativePoints();
};

#endif // RECTANGLE_H
