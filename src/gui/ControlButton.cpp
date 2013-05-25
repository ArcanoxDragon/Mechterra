/*
 * ControlButton.cpp
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#include "ControlButton.h"
#include "SDL_mouse.h"
#include "SDL_opengl.h"
#include <iostream>
using std::cout;
using std::endl;

ControlButton::ControlButton(int id) :
		Control()
{
	this->id = id;
}

ControlButton::ControlButton(int id, int x, int y, int width, int height) :
		Control(x, y, width, height)
{
	this->id = id;
}

ControlButton::ControlButton() :
		Control()
{
	this->id = 0;
}

ControlButton::~ControlButton()
{
	
}

void ControlButton::render()
{
	glColor4f(0.f, 0.f, 0.f, 1.f);
	glBegin(GL_QUADS);
	{
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
	}
	glEnd();
	
	glColor4f(1.f, 1.f, 1.f, 1.f);
	glBegin(GL_QUADS);
	{
		glVertex2f(x + 2, y + 2);
		glVertex2f(x + width - 2, y + 2);
		glVertex2f(x + width - 2, y + height - 2);
		glVertex2f(x + 2, y + height - 2);
	}
	glEnd();
}

void ControlButton::tick()
{
	cout << "tick" << endl;
}

