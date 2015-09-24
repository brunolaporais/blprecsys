/*
 * ItemBased.h
 *
 *  Created on: Sep 24, 2015
 *      Author: brunolaporais
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <cmath>
#include "../../model/Dataset.h"
#include "../Similarity.h"

#ifndef RECSYS_METHODS_ITEMBASED_H_
#define RECSYS_METHODS_ITEMBASED_H_

class ItemBased {
public:
	ItemBased(Dataset &d);
	virtual ~ItemBased();
	void predictTarget(int nbNumbers);
private:
	Dataset &data;
};

#endif /* RECSYS_METHODS_ITEMBASED_H_ */
