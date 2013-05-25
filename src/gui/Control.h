/*
 * Control.h
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#ifndef CONTROL_H_
#define CONTROL_H_

class Control
{
public:
	Control();
	Control(int, int, int, int);
	virtual ~Control();
	virtual void tick() = 0;
	virtual void render() = 0;
	
	void setLocation(int, int);
	void setSize(int, int);
	void getLocation(int&, int&);
	void getSize(int&, int&);
	
	int getX();
	int getY();
	int getWidth();
	int getHeight();
protected:
	int x;
	int y;
	int width;
	int height;
};

#endif /* CONTROL_H_ */
