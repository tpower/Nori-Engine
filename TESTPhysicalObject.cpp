#include "TESTPhysicalObject.h"
#include "Rectangle.cpp"
//^^^^^I Dont like that I did this

TESTPhysicalObject::TESTPhysicalObject(double x, double y, double vx, double vy, double av)
    : Rectangle::Rectangle(x, y, 50, 50)
{
    type = 11000;

    vel.x = vx;
    vel.y = vy;

    angularVel = av;
}

TESTPhysicalObject::~TESTPhysicalObject()
{

}

void TESTPhysicalObject::run()
{
    Rectangle::run();
}

void TESTPhysicalObject::draw(SDL_Surface *screen)
{
    SDL_Rect r1, r2, r3, r4, r5;
    //SDL_Rect test;

    r1.x = points[0].x; r2.x = points[1].x; r3.x = points[2].x; r4.x = points[3].x;
    r1.y = points[0].y; r2.y = points[1].y; r3.y = points[2].y; r4.y = points[3].y;

    //test.x = points[4].x;
    //test.y = points[4].y;

    r5.x = pos.x; r5.y = pos.y;

    SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &r1);
    SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &r2);
    SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &r3);
    SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &r4);

    //SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &test);

    SDL_BlitSurface(SDL_LoadBMP("dot.bmp"), NULL, screen, &r5);
}

void TESTPhysicalObject::toggleActive(bool act)
{

}
