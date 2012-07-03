#include "Game.h"

//Objects to load
#include "TESTGraphicalObject.h"
#include "TESTAudioObject.h"

//Engines to load
#include "GraphicsEngine.h"
#include "AudioEngine.h"

Game::Game()
{
    engines.push_back(dynamic_cast<Engine*>(new GraphicsEngine()));
    engines.push_back(dynamic_cast<Engine*>(new AudioEngine()));
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
        file >> data;
        switch(data)
        {
            case 1:
                objects.push_back(new TESTGraphicalObject());
                break;
            case 2:
                objects.push_back(new TESTAudioObject());
                break;
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
        SDL_Delay(20);
    }
}
