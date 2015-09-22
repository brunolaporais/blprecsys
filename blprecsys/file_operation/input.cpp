/*
 * inputFile.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include "input.h"

inputFile::inputFile(dataset &d, string rating, string target):save(d) {
	ratingFile = rating;
	targetFile = target;
	readRatings();
	readTargets();
}

inputFile::~inputFile() {
}

void inputFile::readRatings(){
	ifstream inFile(ratingFile, ios::in);
	string line;
	if(inFile.is_open()){
		while(getline(inFile, line)){
			getline(inFile,line);
		}
	}
}

void inputFile::readTargets(){

}
