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
	void cutSimilarityData(int usr, int nbNumbers);
	double itemAvg, usrAvg;
	unordered_map<int,unordered_map<int,int> > ratingsByUser, ratingsByItem;
	unordered_map<int, double> avgByUser, avgByItem;
	unordered_map<int,unordered_map<int,double> > targetData, similarityData;
};

#endif /* MODEL_DATA_H_ */
