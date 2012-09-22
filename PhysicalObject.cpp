#include "PhysicalObject.h"

PhysicalObject::PhysicalObject()
{
    type += 10000;

    acc.x = 0;
    acc.y = 0;
    vel.x = 0;
    vel.y = 0;
}

PhysicalObject::~PhysicalObject()
{

}

void PhysicalObject::run()
{

    //Calculate the position
    vel.x += acc.x;
    vel.y += acc.y;
    if( vel.x >= 1) vel.x = 0.999;
    if( vel.y >= 1) vel.y = 0.999;
    pos.x += vel.x;
    pos.y += vel.y;

    recalculateRelativePoints();

    //Calculate the angle
    angle += angularVel / 100;
    while( angle >= 360 )
    {
        angle = angle - 360;
    }

    //Using the following formula, calculate the location of the rectangles points
    //x' = x cos theta - y sin theta
    //y' = x sin theta + y cos theta

    for(int i = 0; i < points.size(); i++)
    {
        point pCalc;
        pCalc.x = relativePoints[i].x - pos.x;
        pCalc.y = relativePoints[i].y - pos.y;
        double c = cos(angle);
        double s = sin(angle);
        points[i].x = pos.x + pCalc.x * cos(angle) - pCalc.y * sin(angle);
        points[i].y = pos.y + pCalc.x * sin(angle) + pCalc.y * cos(angle);
    }
}

void PhysicalObject::setVel(double x, double y)
{
    vel.x = x;
    vel.y = y;
}

bool PhysicalObject::getActivePhys()
{

    return true;
}

vector<point> PhysicalObject::getPoints()
{
    return points;
}
