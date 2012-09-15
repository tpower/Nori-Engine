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

        //Shapes need to be declared
        vect pos1 = pObj1->getPos();
        vect pos2 = pObj2->getPos();

        bool collides = false;


        //if they collide resolve the collision
        if(collides)
        {

        }
    }
}

bool PhysicsEngine::isTypePhysical(int type)
{
    if(type >= 10000) return true;
    return false;
}

