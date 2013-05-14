/*
 * StateMainMenu.h
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#ifndef STATEMAINMENU_H_
#define STATEMAINMENU_H_

#include "State.h"

class StateMainMenu: public State
{
public:
	StateMainMenu();
	virtual ~StateMainMenu();
	void tick();
	void render();
	void init();
};

#endif /* STATEMAINMENU_H_ */
