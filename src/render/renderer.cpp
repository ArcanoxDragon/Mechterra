/*
 * renderer.cpp
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#include <iostream>
#include "../state/State.h"
#include "../game/Game.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "renderer.h"
using std::cout;
using std::endl;

void Renderer::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	State *curState = Game::getInstance()->getCurrentState();
	if (curState != NULL)
	{
		curState->render();
	}
	SDL_GL_SwapBuffers();
}

bool Renderer::init()
{
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		cout << "Error initializing OpenGL! " << gluErrorString(error) << endl;
		return false;
	}

	return true;
}
