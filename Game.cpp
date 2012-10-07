#include "Game.h"

//Objects to load
#include "TESTGraphicalObject.h"
#include "TESTAudioObject.h"
#include "TESTControllableObject.h"
#include "TESTPhysicalObject.h"
#include "TESTSmallerObject.h"

//Engines to load
#include "GraphicsEngine.h"
#include "AudioEngine.h"
#include "ControlEngine.h"
#include "PhysicsEngine.h"

Game::Game()
{
    engines.push_back(dynamic_cast<Engine*>(new GraphicsEngine()));
    engines.push_back(dynamic_cast<Engine*>(new AudioEngine()));
    engines.push_back(dynamic_cast<Engine*>(new ControlEngine()));
    engines.push_back(dynamic_cast<Engine*>(new PhysicsEngine()));

    running = false;
}

Game::~Game()
{

}

void Game::load(const char* fileName)
{
    int data;
    if(file)
    {
        file.close();
    }

    file.open(fileName);

    if(file)
    {
        // load implementation to be added later
        while( file >> data )
        {
            //Storage Variables
            double x, y, vx, vy, av;
            switch(data)
            {
                case 1:
                    file >> x >> y;
                    objects.push_back(new TESTGraphicalObject(x, y));
                    break;
                case 2:
                    objects.push_back(new TESTAudioObject());
                    break;
                case 3:
                    objects.push_back(new TESTControllableObject());
                    break;
                case 4:
                    file >> x >> y >> vx >> vy >> av;
                    objects.push_back(new TESTPhysicalObject(x, y, vx, vy, av));
                    break;
                case 5:
                    file >> x >> y >> vx >> vy >> av;
                    objects.push_back(new TESTSmallerObject(x, y, vx, vy, av));
                    break;
            }
        }

        running = true;
    }
}



void Game::play()
{
    while(running)
    {
        for(int i = 0; i < (int)engines.size(); i++)
        {
            engines[i]->process(objects);
        }
        SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
        SDL_Delay(20);
    }
}
