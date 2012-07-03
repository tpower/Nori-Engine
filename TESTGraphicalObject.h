#ifndef TESTGRAPHICALOBJECT_H
#define TESTGRAPHICALOBJECT_H

#include "GraphicalObject.h"

class TESTGraphicalObject : public GraphicalObject
{
    public:
        TESTGraphicalObject();
        void draw(SDL_Surface *screen);

        void toggleActive(bool);
};

#endif // TESTGRAPHICALOBJECT_H
