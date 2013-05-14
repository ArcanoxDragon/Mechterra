/*
 * util.cpp
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#include <time.h>
#include <string>
#include <stdio.h>
#include "util.h"
using std::string;

int millis()
{
	clock_t t = clock();
	return  (float) t / (float) CLOCKS_PER_SEC * MILLIS_PER_SEC;
}

string itostr(int val)
{
    char buff[14];
    return string(buff, sprintf(buff, "%d", val));
}

string dtostr(double val)
{
    char buff[14];
    return string(buff, sprintf(buff, "%.2f", val));
}
