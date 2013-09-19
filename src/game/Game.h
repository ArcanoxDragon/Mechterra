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

#include <vector>
#include "SDL_events.h"
using std::vector;

class Game
{
public:
	virtual ~Game();

	State* getCurrentState();
	int startGame();
	bool isInitialized();
	template<class T> void activateState();
	int getFPS();
	vector<SDL_Event>* getEventsThisFrame();

	static Game* getInstance();
private:
	Game();
	bool init();
	static int tickThread(void*);
	
	SDL_Surface *screen;
	State *curState;
	vector<SDL_Event> *events;
	bool initialized;
	bool running;
	bool eventLock;
	double fps;
	double aFPS;
	long lastFPS;
	int aCount;
	
	static Game* instance;
};

#endif /* GAME_H_ */
