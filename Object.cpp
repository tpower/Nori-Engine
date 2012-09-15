#include "Object.h"

Object::Object()
{
    type = 0;
    setPos(0, 0);
}

Object::~Object()
{

}

void Object::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
void toggleActive(bool act)
{

}
