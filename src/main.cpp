/*
 * main.cpp
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mouse.h>
#include <SDL_video.h>
#include <SDL_timer.h>

#include "game/Game.h"
using namespace std;

int main(int argc, char *argv[])
{
	Game* game = Game::getInstance();
	int errCode = game->startGame();
	delete game;
	return errCode;
}
