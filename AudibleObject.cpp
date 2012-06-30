#include "AudibleObject.h"

AudibleObject::AudibleObject()
{
    for(int i = 0; i < (int)sounds.size(); i++)
    {
        sounds[i] = NULL;
    }
}

AudibleObject::~AudibleObject()
{
    for(int i = 0; i < (int)sounds.size(); i++)
    {
        Mix_FreeChunk(sounds[i]);
    }
}

void AudibleObject::processSound()
{

}
