/*
 * Game.h
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#ifndef GAME_H_
#define GAME_H_

#include "../state/State.h"
#include "SDL_video.h"
#include "SDL_events.h"

#define ICON "res/tex/test.png"

class Game
{
public:
	virtual ~Game();

	State* getCurrentState();
	int startGame();
	bool isInitialized();
	template<class T> void activateState();
	int getFPS();

	static Game* getInstance();
private:
	Game();
	bool init();
	
	SDL_Surface *screen;
	SDL_Event ev;
	State *curState;
	bool initialized;
	double fps;
	double aFPS;
	int aCount;
	
	static Game* instance;
};

#endif /* GAME_H_ */
