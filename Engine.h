#ifndef ENGINE_H
#define ENGINE_H
#include "Object.h"
#include <vector>

using namespace std;

class Engine
{
    protected:

    public:
        Engine();
        virtual ~Engine();

        virtual void process(vector<Object*> objects) = 0;
};

#endif
