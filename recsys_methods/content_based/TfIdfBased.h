/*
 * TfIdfBased.h
 *
 *  Created on: 23/10/2015
 *      Author: blpadmin
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <cmath>
#include "../../model/Dataset.h"
#include "../Similarity.h"

using namespace std;

#ifndef RECSYS_METHODS_CONTENT_BASED_IRBASED_H_
#define RECSYS_METHODS_CONTENT_BASED_IRBASED_H_

class TfIdfBased {
public:
	TfIdfBased(Dataset &d);
	virtual ~TfIdfBased();
	void predictTarget(double minTfIdf, int maxTarget);
private:
	Dataset &data;
};

#endif /* RECSYS_METHODS_COLABORATIVE_FILTRING_USERBASED_H_ */
