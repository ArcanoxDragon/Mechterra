/*
 * ControlButton.cpp
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#include "../game/Game.h"
#include "ControlButton.h"
#include "SDL_mouse.h"
#include "SDL_opengl.h"
#include "SDL_events.h"
#include <iostream>
using std::cout;
using std::endl;

ControlButton::ControlButton(int id, void (*onClick)()) :
		Control()
{
	this->id = id;
	this->down = false;
	this->onClick = onClick;
}

ControlButton::ControlButton(int id, int x, int y, int width, int height, void (*onClick)()) :
		Control(x, y, width, height)
{
	this->id = id;
	this->down = false;
	this->onClick = onClick;
}

ControlButton::ControlButton() :
		Control()
{
	this->id = 0;
	this->down = false;
	this->onClick = NULL;
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
	
	if (!down)
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

bool ControlButton::isMouseInside()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return (x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height);
}

void ControlButton::tick()
{
	vector<SDL_Event> *events = Game::getInstance()->getEventsThisFrame();
	for (UINT i = 0; i < events->size(); i++)
	{
		SDL_Event event = (*events)[i];
		if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (isMouseInside())
					{
						this->down = true;
					}
					else
					{
						this->down = false;
					}
				}
				else
				{
					this->down = false;
					if (isMouseInside())
						if (this->onClick != NULL)
							this->onClick();
				}
			}
		}
	}
}

