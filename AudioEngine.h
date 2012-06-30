#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include "Engine.h"
#include "AudibleObject.h"
#include "SDL/SDL_mixer.h"

class AudioEngine : public Engine
{
    protected:

    public:
        AudioEngine();
        ~AudioEngine();

        void process(vector<Object*> objects);
        bool isTypeAudible(int type);
};

#endif // AUDIOENGINE_H
