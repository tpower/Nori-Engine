#include <iostream>

#include <SDL/SDL.h>

#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game game;
    game.load("Test.dat");
    game.play();

    return 0;
}
