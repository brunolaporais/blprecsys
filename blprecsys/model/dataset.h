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

class dataset {
public:
	dataset();
	virtual ~dataset();
private:
	unordered_map<int,unordered_map<int,double> > ratingsByUser;
	unordered_map<int,unordered_map<int,double> > ratingsByItem;
	unordered_map<int,unordered_map<int,double> > targetData;
};

#endif /* MODEL_DATA_H_ */
