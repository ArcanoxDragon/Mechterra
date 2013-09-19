/*
 * StateMainMenu.cpp
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#include "../game/Game.h"
#include "../game/options.h"
#include "../gui/Control.h"
#include "../gui/ControlButton.h"
#include "../util/util.h"
#include "State.h"
#include "StateMainMenu.h"
#include "SDL_opengl.h"
#include "../render/TextureLoader.h"

#include <iostream>
using std::cout;

StateMainMenu::StateMainMenu()
{
	controls = vector<Control*>();
}

StateMainMenu::~StateMainMenu()
{
	
}

void StateMainMenu::tick()
{
	for (UINT c = 0; c < controls.size(); c++)
	{
		controls[c]->tick();
	}
}

void StateMainMenu::render()
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	for (UINT c = 0; c < controls.size(); c++)
	{
		controls[c]->render();
	}
}

void StateMainMenu::addControl(Control *control)
{
	controls.push_back(control);
}

void StateMainMenu::init()
{
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1, -1);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	
	addControl(new ControlButton(1, 8, 8, 128, 32, &SDL_Quit));
}

