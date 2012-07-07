#include "TESTControllableObject.h"

TESTControllableObject::TESTControllableObject()
{
    play = false;
}

TESTControllableObject::~TESTControllableObject()
{

}

void TESTControllableObject::process(SDL_Event event)
{
    play = false;
    if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                play = true;
            }
        }
}

void TESTControllableObject::processSound()
{
    if(play)
    {
        testSound = Mix_LoadWAV( "doh.wav");
        Mix_PlayChannel( -1, testSound, 0);
    }
}

void TESTControllableObject::toggleActive(bool act)
{

}
