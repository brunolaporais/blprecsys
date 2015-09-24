/*
 * userBased.h
 *
 *  Created on: 22/09/2015
 *      Author: blpadmin
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <cmath>
#include "../../model/Dataset.h"
#include "../Similarity.h"

using namespace std;

#ifndef RECSYS_METHODS_COLABORATIVE_FILTRING_USERBASED_H_
#define RECSYS_METHODS_COLABORATIVE_FILTRING_USERBASED_H_

class ItemBased {
public:
	ItemBased(Dataset &d);
	virtual ~ItemBased();
	void predictTarget(int nbNumbers);
private:
	Dataset &data;
};

#endif /* RECSYS_METHODS_COLABORATIVE_FILTRING_USERBASED_H_ */
