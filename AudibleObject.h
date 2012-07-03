#ifndef AUDIBLEOBJECT_H
#define AUDIBLEOBJECT_H

#include "SDL/SDL_mixer.h"
#include "Object.h"

#include <vector>

using namespace std;

class AudibleObject : public Object
{
    protected:

    public:
        AudibleObject();
        ~AudibleObject();

        virtual void processSound() = 0;
};

#endif // AUDIBLEOBJECT_H
