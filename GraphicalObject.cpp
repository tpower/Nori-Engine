#include "GraphicalObject.h"

GraphicalObject::GraphicalObject()
{
    type += 1000;
    layer = 0;
    image = SDL_LoadBMP( "image.bmp" );
}

GraphicalObject::~GraphicalObject()
{

}

void GraphicalObject::draw(SDL_Surface* screen)
{

}

int GraphicalObject::getLayer()
{
    return layer;
}
