#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine()
{

}

PhysicsEngine::~PhysicsEngine()
{

}

void PhysicsEngine::process(vector<Object*> objects)
{
    vector<PhysicalObject*> PhysicalObjects;

    PhysicalObjects = getPhysicalObjects(objects);      //Isolate the object list to only contain physicalObjects
    detectAndResolveCollisions(PhysicalObjects);        //Collisions are detected and resolved
    run(PhysicalObjects);                               //Each object performs its own physics based on position, velocity, torque
}

vector<PhysicalObject*> PhysicsEngine::getPhysicalObjects(vector<Object*> objects)
{
    vector<PhysicalObject*> PhysicalObjects;
    for(int i = 0; i < (int)objects.size(); i++)
    {
        int type = objects[i]->getType();

        if(isTypePhysical(type) && dynamic_cast<PhysicalObject*>(objects[i])->getActivePhys())
            PhysicalObjects.push_back(dynamic_cast<PhysicalObject*>(objects[i]));
    }
    return PhysicalObjects;
}

void PhysicsEngine::run(vector<PhysicalObject*> PhysicalObjects)
{
    for(int i = 0; i < (int)PhysicalObjects.size(); i++)
    {
        PhysicalObjects[i]->run();
    }
}

void PhysicsEngine::detectAndResolveCollisions(vector<PhysicalObject*> PhysicalObjects)
{
    for(int i = 0, j = 1; j < (int)PhysicalObjects.size(); i++, j++)
    {
        PhysicalObject* pObj1 = PhysicalObjects[i];
        PhysicalObject* pObj2 = PhysicalObjects[j];

        vector<point> points1 = pObj1->getPoints();
        vector<point> points2 = pObj2->getPoints();

        for( int k = 0; k < points1.size(); k++)
        {
            for( int l = 0; l < points2.size(); l++)
            {
                /*
                point p, r, q, s;
                double t, u;
                p = points1[i];
                r.x = points1[i+1].x - points1[i].x;
                r.y = points1[i+1].y - points1[i].y;
                q = points2[j];
                s.x = points2[j+1].x - points2[j].x;
                s.y = points2[j+1].y - points2[j].y;

                double test1 = r.x * s.x + r.x * s.y;
                double test2 = r.y * s.x + r.y * s.y;
                */

                //Compare each edge of each shape
                point p1, p2, pp1, pp2;
                float slope1, slope2;
                p1 = points1[k];
                p2 = points1[(k+1) % points1.size()];
                pp1 = points2[l];
                pp2 = points2[(l+1) % points2.size()];

                //need to check for divide by 0
                if( p1.x - p2.x == 0)
                {
                    slope1 = -1;
                }
                else
                {
                    slope1 = (p1.y - p2.y) / (p1.x - p2.x);
                }
                if( pp1.x - pp2.x == 0)
                {
                    slope2 = -1;
                }
                else
                {
                    slope2 = (pp1.y - pp2.y) / (pp1.x - pp2.x);
                }
                if( slope1 == slope2 )
                {
                    /*
                    point testPoint;
                    testPoint.x = q.x - p.x;
                    testPoint.y = q.y - p.y;
                    double test3 = r.x * testPoint.x + r.x * testPoint.y;
                    double test4 = r.y * testPoint.x + r.y * testPoint.y;
                    */

                    //the lines are parallel

                    //Y = Slope * X + YIntersect
                    //Slope = (y1 - y2) / (x1-x2)
                    //Y-Intersect = Y1 - Slope * X1;
                    double intercept1, intercept2;
                    intercept1 = p1.y - slope1 * p1.x;
                    intercept2 = pp1.y - slope2 * pp1.x;

                    //Fix divide by zero error
                    double x = (intercept2 - intercept1) / (slope1 - slope2);
                    double y = x * slope1 + intercept1;

                    bool inXBounds1, inXBounds2, inYBounds1, inYBounds2;
                    inXBounds1 = inXBounds2 = inYBounds1 = inYBounds2 = false;
                    if( (x >= p1.x && x <= p2.x) || (x >= p2.x && x <= p1.x))
                    {
                        inXBounds1 = true;
                    }
                    if( (x >= pp1.x && x <= pp2.x) || (x >= pp2.x && x <= pp1.x))
                    {
                        inXBounds2 = true;
                    }
                    if( (y >= p1.y && y <= p2.y) || (y >= p2.y && y <= p1.y))
                    {
                        inYBounds1 = true;
                    }
                    if( (y >= pp1.y && y <= pp2.y) || (y >= pp2.y && y <= pp1.y))
                    {
                        inYBounds2 = true;
                    }

                    //this may miss the case where a large line is compared to a smaller line that it entirely eclipses
                    //if( pp1.y == slope1 * pp1.x + intercept1 ||  pp2.y == slope1 * pp2.x + intercept1)
                    if(inXBounds1 && inYBounds1 && inXBounds2 && inYBounds2)
                    {
                        //the lines are collinear
                        int test1 = 0;
                        test1++;
                    }
                    else
                    {
                        //the lines never intersect
                        int test2 = 0;
                        test2++;
                    }
                }
                else //Lines are not parallel and must intersect at point (x,y)
                {
                    double intercept1, intercept2;
                    intercept1 = p1.y - slope1 * p1.x;
                    intercept2 = pp1.y - slope2 * pp1.x;

                    if( slope1 == -1 )
                    {
                        //slope1 is infinite
                        bool inXBounds, inYBounds;
                        inXBounds = inYBounds = false;
                        double x = p1.x;
                        double y = slope2 * x + intercept2;
                        if( (x >= pp1.x && x <= pp2.x) || (x >= pp2.x && x <= pp1.x))
                        {
                            inXBounds = true;
                        }
                        if((y >= p1.y && y <= p2.y) || (y >= p2.y && y <= p1.y))
                        {
                            inYBounds = true;
                        }
                        if(inXBounds && inYBounds)
                        {
                            //they collide at (p1.x, y)
                            int test3 = 0;
                            test3++;
                        }
                    }
                    else if( slope2 == -1 )
                    {
                        //slope2 is infinite
                        bool inXBounds, inYBounds;
                        inXBounds = inYBounds = false;
                        double x = pp1.x;
                        double y = slope1 * x + intercept1;
                        if( (x >= p1.x && x <= p2.x) || (x >= p2.x && x <= p1.x))
                        {
                            inXBounds = true;
                        }
                        if((y >= pp2.y && y <= pp1.y) || (y >= pp1.y && y <= pp2.y))
                        {
                            inYBounds = true;
                        }
                        if(inXBounds && inYBounds)
                        {
                            //they collide at (p2.x, y)
                            int test4 = 0;
                            test4++;
                        }
                    }
                    else
                    {

                        double x = (intercept2 - intercept1) / (slope1 - slope2);
                        double y = x * slope1 + intercept1;

                        //Does point (x,y) lie on the actual line segments?
                        bool inXBounds1, inXBounds2, inYBounds1, inYBounds2;
                        inXBounds1 = inXBounds2 = inYBounds1 = inYBounds2 = false;
                        if( (x >= p1.x && x <= p2.x) || (x >= p2.x && x <= p1.x))
                        {
                            inXBounds1 = true;
                        }
                        if( (x >= pp1.x && x <= pp2.x) || (x >= pp2.x && x <= pp1.x))
                        {
                            inXBounds2 = true;
                        }
                        if( (y >= p1.y && y <= p2.y) || (y >= p2.y && y <= p1.y))
                        {
                            inYBounds1 = true;
                        }
                        if( (y >= pp1.y && y <= pp2.y) || (y >= pp2.y && y <= pp1.y))
                        {
                            inYBounds2 = true;
                        }

                        if(inXBounds1 && inYBounds1 && inXBounds2 && inYBounds2)
                        {
                            //The lines collide at the point (x,y)
                            int test5 = 0;
                            test5++;
                        }
                        else
                        {
                            //there is no actual collision
                            int test6 = 0;
                            test6++;
                        }
                    }
                }
            }
        }
    }
}

bool PhysicsEngine::isTypePhysical(int type)
{
    if(type >= 10000) return true;
    return false;
}

