#include "TESTGraphicalObject.h"

TESTGraphicalObject::TESTGraphicalObject(int x, int y)
{
    pos.x = x;
    pos.y = y;
    layer = 3;
}

void TESTGraphicalObject::draw(SDL_Surface *screen)
{
    SDL_Rect newRect;
    newRect.x = pos.x; newRect.y = pos.y; newRect.w = 0; newRect.h = 0;
    SDL_BlitSurface(image, NULL, screen, &newRect);
}

void TESTGraphicalObject::toggleActive(bool act)
{

}
