/*
 * ErrorValidation.h
 *
 *  Created on: Sep 23, 2015
 *      Author: brunolaporais
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../file_operation/Input.h"
#include "../model/Dataset.h"
#include "../recsys_methods/colaborative_filtring/ItemBased.h"
#include "../recsys_methods/colaborative_filtring/UserBased.h"
#include "../recsys_methods/colaborative_filtring/MatrixFact.h"

#ifndef VALIDATION_ERRORVALIDATION_H_
#define VALIDATION_ERRORVALIDATION_H_

class ErrorValidation {
public:
	ErrorValidation();
	virtual ~ErrorValidation();
	void compareValidation(Dataset &correctData);
	void rmseValidation(Dataset &correctData);
	void targetsGenerate(Dataset &correctData);
	void ratingsGenerate(Dataset &correctData);
private:
	unordered_map<int, unordered_map<int, double> > targetSelected;
};

#endif /* VALIDATION_ERRORVALIDATION_H_ */
