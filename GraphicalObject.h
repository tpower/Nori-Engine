#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include "Object.h"

#include <SDL/SDL.h>

class GraphicalObject : virtual public Object
{
    protected:
        SDL_Surface    *image;
        int layer;

    public:
        GraphicalObject();
        ~GraphicalObject();

        virtual void draw(SDL_Surface* screen) = 0;
        int  getLayer();
};

#endif // GRAPHICALOBJECT_H_INCLUDED
