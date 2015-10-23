/*
 * Help.h
 *
 *  Created on: Oct 23, 2015
 *      Author: brunolaporais
 */

#include <vector>
#include <iostream>
#include <stdio.h>

#ifndef UTIL_HELP_H_
#define UTIL_HELP_H_

using namespace std;

namespace Help {
	vector<string> split(string s, const char &d);
	string strTrim(string s);
};

#endif /* UTIL_HELP_H_ */
