#ifndef CONTROLENGINE_H
#define CONTROLENGINE_H

#include "Engine.h"
#include "ControllableObject.h"

class ControlEngine : public Engine
{
    protected:
        SDL_Event event;
    public:
        ControlEngine();
        ~ControlEngine();

        void process(vector<Object*> objects);
        bool isTypeControllable(int type);
};

#endif // CONTROLENGINE_H
