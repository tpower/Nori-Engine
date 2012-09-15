#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "Engine.h"
#include "PhysicalObject.h"

#include "Rectangle.h"

#include <SDL/SDL.h>
#include <Vector>

class PhysicsEngine : public Engine
{
    private:
        void run(vector<PhysicalObject*>);
        void resolveCollisions(vector<PhysicalObject*>);
    public:
        PhysicsEngine();
        ~PhysicsEngine();

        void process(vector<Object*> objects);
        vector<PhysicalObject*>                 getPhysicalObjects(vector<Object*>);
        void                                    detectAndResolveCollisions(vector<PhysicalObject*> objects);
        bool                                    isTypePhysical(int type);

        void                                    detectRectangleRectangleCollision(PhysicalObject*, PhysicalObject*);
};


#endif // PHYSICSENGINE_H
