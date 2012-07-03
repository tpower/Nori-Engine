#include "Object.h"

Object::Object()
{
    type = 0;
    setPos(0, 0, 0, 0);
}

Object::~Object()
{

}

void Object::setPos(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;
}

void toggleActive(bool act)
{

}
