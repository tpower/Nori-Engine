#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Object.h"
#include "Engine.h"

#include <fstream>

#include <SDL/SDL.h>

using namespace std;

class Game
{
    private:
        vector<Engine*> engines;
        vector<Object*> objects;
        ifstream        file;
        bool            running;

    public:
        Game();
        ~Game();

        void load(const char* file);
        void play();
};

#endif
