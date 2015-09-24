/*
 * data.h
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::tr1;

#ifndef MODEL_DATA_H_
#define MODEL_DATA_H_

class Dataset {
public:
	Dataset();
	virtual ~Dataset();
	void sortUserSimilarity(int usr);
	void sortItemSimilarity(int item);
	void printSolution();
	double itemAvg, usrAvg;
	unordered_map<int,unordered_map<int,int> > ratingsByUser, ratingsByItem;
	unordered_map<int, double> avgByUser, avgByItem;
	unordered_map<int,unordered_map<int,double> > targetData, userSimilarity, itemSimilarity;
};

#endif /* MODEL_DATA_H_ */
