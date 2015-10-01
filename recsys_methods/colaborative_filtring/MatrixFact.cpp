/*
 * MatrixFact.cpp
 *
 *  Created on: Oct 1, 2015
 *      Author: brunolaporais
 */

#include "MatrixFact.h"

MatrixFact::MatrixFact(Dataset &d, int nLatFac):data(d) {
	numLatentFactors = nLatFac;
}

MatrixFact::~MatrixFact() {
	// TODO Auto-generated destructor stub
}

double vectorProduct(unordered_map<int, double> v1, unordered_map<int, double> v2){
	double product;
	for(int i = 0; i < v1.size(); ++i) {
		product += v1[i] * v2[i];
	}
	return product;
}

void MatrixFact::predictTarget(int steps, double alpha, double beta) {
	genRandomMatrix();
	double eij, e;
	for(int s = 0; s < steps; ++s){
		for(auto itUsr = data.ratingsByUser.begin(); itUsr != data.ratingsByUser.end(); ++itUsr){
			for(auto itItem = data.ratingsByUser[itUsr->first].begin(); itItem != data.ratingsByItem[itUsr->first].end(); ++itItem){
				if(itItem->second > 0){
					eij = itItem->second - vectorProduct(usrFactors[itUsr->first], itemFactors[itItem->first]);
					for(int k = 0; k < numLatentFactors; ++k){
						usrFactors[itUsr->first][k] = usrFactors[itUsr->first][k] + alpha *
								(2 * eij * itemFactors[k][itItem->first] - beta * usrFactors[itUsr->first][k]);
						itemFactors[k][itItem->first] = itemFactors[k][itItem->first] + alpha *
								(2 * eij * usrFactors[itUsr->first][k] - beta * itemFactors[k][itItem->first]);
					}
				}
			}
		}
		e = 0;
		for(auto itUsr = data.ratingsByUser.begin(); itUsr != data.ratingsByUser.end(); ++itUsr){
			for(auto itItem = data.ratingsByUser[itUsr->first].begin(); itItem != data.ratingsByItem[itUsr->first].end(); ++itItem){
				if(itItem->second > 0){
					e = e + pow(itItem->second - vectorProduct(usrFactors[itUsr->first], itemFactors[itItem->first]), 2);
					for(int k = 0; k < numLatentFactors; ++k){
						e = e + (beta/2) * (pow(usrFactors[itUsr->first][k],2) + pow(itemFactors[k][itItem->first],2));
					}
				}
			}
		}
		if(e < 0.001) break;
	}
	for(auto itTargUsr = data.targetData.begin(); itTargUsr != data.targetData.end(); ++itTargUsr){
		for(auto itTargItem = data.targetData[itTargUsr->first].begin(); itTargItem != data.targetData[itTargUsr->first].end(); ++itTargItem){
			itTargItem->second = vectorProduct(usrFactors[itTargUsr->first], itemFactors[itTargItem->first]);
		}
	}
}

void MatrixFact::genRandomMatrix() {
	for(auto itUsr = data.ratingsByUser.begin(); itUsr != data.ratingsByUser.end(); ++itUsr){
		for(int i = 0; i < numLatentFactors; ++i){
			usrFactors[itUsr->first][i] = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
		}
	}
	for(auto itItem = data.ratingsByItem.begin(); itItem != data.ratingsByItem.end(); ++itItem){
		for(int i = 0; i < numLatentFactors; ++i){
			usrFactors[i][itItem->first] = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
		}
	}
}
