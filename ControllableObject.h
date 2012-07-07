#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

#include <SDL/SDL.h>

#include "Object.h"

class ControllableObject : virtual public Object
{
    protected:

    public:
        ControllableObject();
        ~ControllableObject();

        virtual void process(SDL_Event event) = 0;
};

#endif // CONTROLLABLEOBJECT_H
