/*
 * Svd.h
 *
 *  Created on: Sep 29, 2015
 *      Author: brunolaporais
 */

#ifndef RECSYS_METHODS_COLABORATIVE_FILTRING_SVD_H_
#define RECSYS_METHODS_COLABORATIVE_FILTRING_SVD_H_

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include "../../model/Dataset.h"

class Svd {
public:
	Svd(Dataset &d);
	virtual ~Svd();
	void predictTarget();
private:
	Dataset &data;
};

#endif /* RECSYS_METHODS_COLABORATIVE_FILTRING_SVD_H_ */
