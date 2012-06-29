#include "Game.h"

Game::Game()
{
    // engines.push_back(dynamic_cast<Engine*>(new GraphicsEngine()));
    running = false;
}

Game::~Game()
{

}

void Game::load(const char* fileName)
{
    if(file)
    {
        file.close();
    }

    file.open(fileName);

    if(file)
    {
        // load implementation to be added later
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
