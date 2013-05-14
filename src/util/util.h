/*
 * util.h
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>
using std::string;

#define MILLIS_PER_SEC 1000.0f

int millis();
string itostr(int val);
string dtostr(double val);

#endif /* UTIL_H_ */
