/*
 * MatrixFact.h
 *
 *  Created on: Oct 1, 2015
 *      Author: brunolaporais
 */

#include <tr1/unordered_map>
#include"../../model/Dataset.h"

#ifndef RECSYS_METHODS_COLABORATIVE_FILTRING_MATRIXFACT_H_
#define RECSYS_METHODS_COLABORATIVE_FILTRING_MATRIXFACT_H_

class MatrixFact {
public:
	MatrixFact(Dataset &d, int nLatFac);
	virtual ~MatrixFact();
	void predictTarget(int steps, double alpha, double beta);
	void genRandomMatrix();
private:
	Dataset &data;
	int numLatentFactors;
	unordered_map<int, unordered_map<int, double> > usrFactors, itemFactors;
};

#endif /* RECSYS_METHODS_COLABORATIVE_FILTRING_MATRIXFACT_H_ */
