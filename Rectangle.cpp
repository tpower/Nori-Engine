#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;
    dimensions.x = w;
    dimensions.y = h;

    angle = 0;
    angularVel = 0;


    point p1, p2, p3, p4;
    p1.x = pos.x - (dimensions.x / 2);
    p1.y = pos.y - (dimensions.y / 2);

    p2.x = pos.x + (dimensions.x / 2);
    p2.y = pos.y - (dimensions.y / 2);

    p3.x = pos.x - (dimensions.x / 2);
    p3.y = pos.y + (dimensions.y / 2);

    p4.x = pos.x + (dimensions.x / 2);
    p4.y = pos.y + (dimensions.y / 2);

    relativePoints.push_back(p1);
    relativePoints.push_back(p2);
    relativePoints.push_back(p3);
    relativePoints.push_back(p4);

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
}

Rectangle::~Rectangle()
{

}

void Rectangle::run()
{
    PhysicalObject::run();
    /*
    //Calculate the position
    vel.x += acc.x;
    vel.y += acc.y;
    pos.x += vel.x;
    pos.y += vel.y;

    //Calculate the angle
    angle += angularVel / 100;
    while( angle >= 360 )
    {
        angle = angle - 360;
    }

    //Using the following formula, calculate the location of the rectangles points
    //x' = x cos theta - y sin theta
    //y' = x sin theta + y cos theta

    vect p1Calc, p2Calc, p3Calc, p4Calc;

    p1Calc.x = -1 * (dimensions.x / 2);                             //x position relative to 0
    p1Calc.y = -1 * (dimensions.y / 2);                             //y position relative to 0
    p1.x = pos.x + p1Calc.x * cos(angle) - p1Calc.y * sin(angle);   //pos of rectangle + relative rotated x position
    p1.y = pos.y + p1Calc.x * sin(angle) + p1Calc.y * cos(angle);   //pos of rectangle + relative rotated y position

    p2Calc.x = (dimensions.x / 2);
    p2Calc.y = -1 * (dimensions.y / 2);
    p2.x = pos.x + p2Calc.x * cos(angle) - p2Calc.y * sin(angle);
    p2.y = pos.y + p2Calc.x * sin(angle) + p2Calc.y * cos(angle);

    p3Calc.x = -1 * (dimensions.x / 2);
    p3Calc.y = (dimensions.y / 2);
    p3.x = pos.x + p3Calc.x * cos(angle) - p3Calc.y * sin(angle);
    p3.y = pos.y + p3Calc.x * sin(angle) + p3Calc.y * cos(angle);

    p4Calc.x = (dimensions.x / 2);
    p4Calc.y = (dimensions.y / 2);
    p4.x = pos.x + p4Calc.x * cos(angle) - p4Calc.y * sin(angle);
    p4.y = pos.y + p4Calc.x * sin(angle) + p4Calc.y * cos(angle);
    */
}

void Rectangle::toggleActive(bool)
{

}


#endif
