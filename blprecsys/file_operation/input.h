/*
 * inputFile.h
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "../model/dataset.h"

using namespace std;

#ifndef FILE_OPERATION_INPUT_H_
#define FILE_OPERATION_INPUT_H_

class inputFile {
public:
	inputFile(dataset &d, string rating, string target);
	virtual ~inputFile();
	void readRatings();
	void readTargets();
private:
	string ratingFile;
	string targetFile;
	dataset &save;
};

#endif /* FILE_OPERATION_INPUT_H_ */
