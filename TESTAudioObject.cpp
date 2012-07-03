#include "TESTAudioObject.h"

void TESTAudioObject::processSound()
{
    testSound = Mix_LoadWAV( "doh.wav");
    Mix_PlayChannel( -1, testSound, 0);
}

void TESTAudioObject::toggleActive(bool act)
{

}
