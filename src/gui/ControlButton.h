/*
 * ControlButton.h
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#ifndef CONTROLBUTTON_H_
#define CONTROLBUTTON_H_

#include "Control.h"

class ControlButton: public Control
{
public:
	ControlButton(int, void (*)());
	ControlButton(int, int, int, int, int, void (*)());
	ControlButton();
	virtual ~ControlButton();
	virtual void render();
	virtual void tick();
	void getID();
private:
	bool isMouseInside();

	void (*onClick)();
	int id;
	bool down;
};

#endif /* CONTROLBUTTON_H_ */
