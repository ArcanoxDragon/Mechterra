/*
 * Control.cpp
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#include "Control.h"

Control::Control()
{
	x = 0;
	y = 0;
	width = 24;
	height = 24;
}

Control::Control(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Control::~Control()
{
}

void Control::setLocation(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Control::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Control::getLocation(int &x, int &y)
{
	x = this->x;
	y = this->y;
}

void Control::getSize(int &width, int &height)
{
	width = this->width;
	height = this->height;
}

int Control::getX()
{
	return x;
}

int Control::getY()
{
	return y;
}

int Control::getWidth()
{
	return width;
}

int Control::getHeight()
{
	return height;
}

void Control::tick()
{
}

void Control::render()
{
}

