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
        vect vel;
        vect acc;
        double          angle;
        double          angularVel;
        vector<point>   points;
        vector<point>   relativePoints;
    public:
        PhysicalObject();
        ~PhysicalObject();

        virtual void        run();
        vector<point>       getPoints();
        void                setVel(double, double);
        bool                getActivePhys();
};

#endif // PHYSICALOBJECT_H
