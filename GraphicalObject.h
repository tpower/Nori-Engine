#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include "Object.h"

#include <SDL/SDL.h>

class GraphicalObject : public Object
{
    protected:
        int layer;

    public:
        GraphicalObject();
        ~GraphicalObject();

        void draw(SDL_Surface* screen);
        int  getLayer();
};

#endif // GRAPHICALOBJECT_H_INCLUDED
