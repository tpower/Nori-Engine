#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Engine.h"
#include "GraphicalObject.h"

#include <SDL/SDL.h>

class GraphicsEngine : public Engine
{
    protected:
        SDL_Surface* screen;

    public:
        GraphicsEngine();
        ~GraphicsEngine();

        void process(vector<Object*> objects);
        bool isTypeDrawable(int type);
        void sortByLayer(vector<GraphicalObject*>&);
};

#endif
