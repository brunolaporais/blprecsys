/*
 * similarity.h
 *
 *  Created on: 22/09/2015
 *      Author: blpadmin
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <cmath>
#include "../model/Dataset.h"

using namespace std;
using namespace std::tr1;

#ifndef RECSYS_METHODS_SIMILARITY_H_
#define RECSYS_METHODS_SIMILARITY_H_

class Similarity {
public:
	Similarity(Dataset &d);
	virtual ~Similarity();
	void cosineByUser(int usr);
	void cosineByItem(int item);
	void featuresTfIdf();
private:
	Dataset &data;
};

#endif /* RECSYS_METHODS_SIMILARITY_H_ */
