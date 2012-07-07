#include "ControlEngine.h"

ControlEngine::ControlEngine()
{

}

ControlEngine::~ControlEngine()
{

}

void ControlEngine::process(vector<Object*> objects)
{
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            exit(0);
        }

        vector<ControllableObject*> controllableObjects;
        for(int i = 0; i < (int)objects.size(); i++)
        {
            int type = objects[i]->getType();

            if(isTypeControllable(type))
                controllableObjects.push_back(dynamic_cast<ControllableObject*>(objects[i]));
        }

        for(int i = 0; i < (int)controllableObjects.size(); i++)
        {
            controllableObjects[i]->process(event);
        }
    }
}

bool ControlEngine::isTypeControllable(int type)
{
    if(type >= 10000) type -= 10000;
    if(type >= 1000)  type -= 1000;
    if(type >= 100)   type -= 100;
    if(type >= 10)    return true;
    return false;
}
