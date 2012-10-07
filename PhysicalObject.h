#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <string>
#include <vector>
#include <math.h>

#include "Object.h"

using namespace std;

struct point
{
    double x, y;
};

class PhysicalObject : virtual public Object
{
    protected:
        float           mass;
        vect            vel;
        vect            acc;
        double          angle;
        double          angularVel;
        vector<point>   points;         //The actual position of the points
        vector<point>   relativePoints; //The position of the points relative to the original position
    public:
        PhysicalObject();
        ~PhysicalObject();

        virtual void        run();
        vector<point>       getPoints();
        void                setVel(double, double);
        bool                getActivePhys();
        virtual void        recalculateRelativePoints() = 0;
};

#endif // PHYSICALOBJECT_H
