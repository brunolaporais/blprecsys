/*
 * similarity.cpp
 *
 *  Created on: 22/09/2015
 *      Author: blpadmin
 */

#include "Similarity.h"

Similarity::Similarity(Dataset &d):data(d) {

}

Similarity::~Similarity() {
	// TODO Auto-generated destructor stub
}

void Similarity::cosineByUser(int usr){
	double cosine, userDenominator;
	unordered_map<int,double> numeratorCosineByUser;
	unordered_map<int,double> denominatorCosineByUser;
	unordered_map<int,double> cosineByUser;

	unordered_map<int,int>::iterator itItem = data.ratingsByUser[usr].begin();
	for(;itItem != data.ratingsByUser[usr].end(); ++itItem){

		unordered_map<int,int>::iterator itUsr = data.ratingsByItem[itItem->first].begin();
		/*Denominator calculator for the user*/
		userDenominator += pow(itItem->second - data.avgByUser[usr],2);
		for(;itUsr != data.ratingsByItem[itItem->first].end(); itUsr++){
			/*Denominator calculator*/
			if(denominatorCosineByUser.find(itUsr->first) == denominatorCosineByUser.end()){
				unordered_map<int,int>::iterator itDenominator = data.ratingsByUser[itUsr->first].begin();
				for(;itDenominator != data.ratingsByUser[itUsr->first].end(); ++itDenominator){
					denominatorCosineByUser[itUsr->first] += pow((itDenominator->second - data.avgByUser[itUsr->first]),2);
				}
			}

			/*Numerator calculator*/
			if(numeratorCosineByUser.find(itUsr->first) != numeratorCosineByUser.end()){
				numeratorCosineByUser[itUsr->first] += (itItem->second - data.avgByUser[usr]) * (itUsr->second - data.avgByUser[itUsr->first]);
			} else {
				numeratorCosineByUser[itUsr->first] = (itItem->second - data.avgByUser[usr]) * (itUsr->second - data.avgByUser[itUsr->first]);
			}
		}
	}

	/*Atualiza Consino*/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 */
	unordered_map<int,double>::iterator itCalcCosine = numeratorCosineByUser.begin();
	for(;itCalcCosine != numeratorCosineByUser.end(); ++itCalcCosine){
		cosine = itCalcCosine->second / (sqrt(userDenominator) * sqrt(denominatorCosineByUser[itCalcCosine->first]));
		cout << itCalcCosine->first << " -> " << itCalcCosine->second
				<< "/(" << sqrt(userDenominator) << "*"
				<< sqrt(denominatorCosineByUser[itCalcCosine->first]) << ") = ";
		cout << cosine << "\n";
	}
}

unordered_map<int,double> Similarity::cosineByItem(){

}
