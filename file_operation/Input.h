/*
 * input.h
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "../model/Dataset.h"

using namespace std;

#ifndef FILE_OPERATION_INPUT_H_
#define FILE_OPERATION_INPUT_H_

class Input {
public:
	Input(Dataset &d, string rating, string target);
	Input(Dataset &d, string rating, string target, string content);
	virtual ~Input();
	void readRatings();
	void readTargets();
	void readContents();
private:
	string ratingFile, targetFile, contentFile;
	Dataset &data;
};

#endif /* FILE_OPERATION_INPUT_H_ */
