/*
 * StateMainMenu.cpp
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#include "../game/options.h"
#include "../util/util.h"
#include "State.h"
#include "StateMainMenu.h"
#include "SDL_opengl.h"
#include "../render/TextureLoader.h"

#include <iostream>
using std::cout;

GLuint tex = 0;

StateMainMenu::StateMainMenu()
{
	
}

StateMainMenu::~StateMainMenu()
{
	
}

void StateMainMenu::tick()
{
	
}

void StateMainMenu::render()
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(50.0f, 50.0f, 0.0f);
	glRotatef(((float) millis()) / 50.0f, 0, 0, 1);
	glTranslatef(-50.0f, -50.0f, 0.0f);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
		
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(100.0f, 0.0f);
		
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(100.0f, 100.0f);
		
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(0.0f, 100.0f);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
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
	
	tex = loadTexture("res/tex/test.png");
	cout << tex;
}

