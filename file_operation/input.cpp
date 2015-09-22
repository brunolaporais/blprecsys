/*
 * input.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include "input.h"

input::input(dataset &d, string rating, string target):save(d) {
	ratingFile = rating;
	targetFile = target;
	readRatings();
	readTargets();
}

input::~input() {
}

void input::readRatings(){
	ifstream inFile(ratingFile, ios::in | ios::app | ios::binary);
	string line;
	if(inFile.is_open()){
		while(getline(inFile, line)){
			cout << line << "\n";
		}
	}
}

void input::readTargets(){

}
