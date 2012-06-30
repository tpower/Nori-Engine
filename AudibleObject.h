#ifndef AUDIBLEOBJECT_H
#define AUDIBLEOBJECT_H

#include "SDL/SDL_mixer.h"
#include "Object.h"

#include <vector>

using namespace std;

class AudibleObject : public Object
{
    protected:
        vector<Mix_Chunk*>    sounds;

    public:
        AudibleObject();
        ~AudibleObject();

        void processSound();
};

#endif // AUDIBLEOBJECT_H
