#ifndef TESTAUDIOOBJECT_H
#define TESTAUDIOOBJECT_H

#include "AudibleObject.h"

class TESTAudioObject : public AudibleObject
{
    private:
        Mix_Chunk    *testSound;
    public:
        void processSound();

        void toggleActive(bool);
};

#endif // TESTAUDIOOBJECT_H
