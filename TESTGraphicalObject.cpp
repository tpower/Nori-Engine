#include "TESTGraphicalObject.h"

TESTGraphicalObject::TESTGraphicalObject()
{
    layer = 3;
}

void TESTGraphicalObject::draw(SDL_Surface *screen)
{
    SDL_BlitSurface(image, NULL, screen, &pos);
}

void TESTGraphicalObject::toggleActive(bool act)
{

}
