/*
 * data.h
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include<stdio.h>
#include<iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

#ifndef MODEL_DATA_H_
#define MODEL_DATA_H_

class Dataset {
public:
	Dataset();
	virtual ~Dataset();
	unordered_map<int,unordered_map<int,int> > ratingsByUser;
	unordered_map<int,unordered_map<int,int> > ratingsByItem;
	unordered_map<int, double> avgByUser;
	unordered_map<int,unordered_map<int,double> > targetData;
};

#endif /* MODEL_DATA_H_ */
