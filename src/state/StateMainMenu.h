/*
 * StateMainMenu.h
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#ifndef STATEMAINMENU_H_
#define STATEMAINMENU_H_

#include "State.h"
#include "../gui/Control.h"
#include "SDL_opengl.h"
#include <vector>
using std::vector;

class StateMainMenu: public State
{
public:
	StateMainMenu();
	virtual ~StateMainMenu();
	void tick();
	void render();
	void init();
	void addControl(Control*);
private:
	vector<Control*> controls;
};

#endif /* STATEMAINMENU_H_ */
