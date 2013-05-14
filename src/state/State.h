/*
 * State.h
 *
 *  Created on: May 13, 2013
 *      Author: Brian
 */

#ifndef STATE_H_
#define STATE_H_

class State
{
public:
	State();
	virtual ~State() = 0;
	virtual void render() = 0;
	virtual void tick() = 0;
	virtual void init() = 0;
};

#endif /* STATE_H_ */
