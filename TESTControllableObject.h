#ifndef TESTCONTROLLABLEOBJECT_H
#define TESTCONTROLLABLEOBJECT_H

#include "ControllableObject.h"
#include "AudibleObject.h"

class TESTControllableObject : public ControllableObject, public AudibleObject
{
    protected:
        bool play;
        Mix_Chunk    *testSound;
    public:
        TESTControllableObject();
        ~TESTControllableObject();

        void process(SDL_Event event);
        void toggleActive(bool act);
        void processSound();
};

#endif // TESTCONTROLLABLEOBJECT_H
