/*
 * Game.cpp
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#include <limits.h>
#include <math.h>
#include "Game.h"
#include "options.h"
#include "../render/renderer.h"
#include "../render/TextureLoader.h"
#include "../state/State.h"
#include "../state/StateMainMenu.h"
#include "../util/util.h"
#include "SDL.h"
#include "SDL_video.h"
#include "SDL_thread.h"
using std::max;
using std::min;

Game* Game::instance = NULL;

Game::Game()
{
	screen = NULL;
	curState = NULL;
	initialized = false;
	fps = 0.0f;
	aFPS = 0.0f;
	aCount = 0;
	running = false;
}

Game::~Game()
{
	delete curState;
	screen = NULL;
	curState = NULL;
	initialized = false;
}

State* Game::getCurrentState()
{
	return curState;
}

int Game::tickThread(void* game)
{
	Game *iGame = (Game*) game;
	while (iGame->running)
	{
		if (iGame->curState != NULL)
		{
			iGame->curState->tick();
		}
		SDL_Delay(1000.0f / 60.0f);
	}
	return 0;
}

int Game::startGame()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_OPENGL);

	if (!init())
	{
		SDL_Quit();
		return 1;
	}

	activateState<StateMainMenu>();
	running = true;
	int time;
	int diff = 0;
	SDL_Thread *threadTick = SDL_CreateThread(tickThread, this);
	if (threadTick == NULL)
	{
		SDL_Quit();
		return 1;
	}
	
	while (running)
	{
		time = millis();
		Renderer::render();
		SDL_Flip(screen);
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
				{
					running = false;
				}
			}
		}
		SDL_Delay(max(0.0f, (1000.0f / 60.0f) - max(diff, 0)));
		diff = millis() - time;
		aFPS += 1.0f / (diff / MILLIS_PER_SEC);
		aCount++;
		if (aCount >= 60)
		{
			fps = max(min(aFPS / (double) aCount, 1000.0), 0.0);
			aCount = 0;
			aFPS = 0;
		}
		SDL_WM_SetCaption(string("MechTerra - FPS: " + dtostr(fps)).c_str(), NULL);
	}

	SDL_WaitThread(threadTick, NULL);
	SDL_Quit();
	return 0;
}

template<class T>
void Game::activateState()
{
	if (curState != NULL)
	{
		delete curState;
		curState = NULL;
	}
	curState = new T();
	curState->init();
}

int Game::getFPS()
{
	return fps;
}

bool Game::init()
{
	SDL_WM_SetCaption("MechTerra", NULL);
	SDL_WM_SetIcon(loadImage(ICON), 0);
	if (!Renderer::init())
		return false;
	initialized = true;
	return true;
}

bool Game::isInitialized()
{
	return initialized;
}

Game* Game::getInstance()
{
	if (Game::instance == NULL)
	{
		Game::instance = new Game();
	}
	return Game::instance;
}

