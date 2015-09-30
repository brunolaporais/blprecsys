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
	if(data.userSimilarity[usr].size() > 0) return;

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

	/*Atualiza Consine*/
	unordered_map<int,double>::iterator itCalcCosine = numeratorCosineByUser.begin();
	for(;itCalcCosine != numeratorCosineByUser.end(); ++itCalcCosine){
		if(itCalcCosine->second != 0){
			cosine = itCalcCosine->second / (sqrt(userDenominator) * sqrt(denominatorCosineByUser[itCalcCosine->first]));
		}
		data.userSimilarity[usr][itCalcCosine->first] = cosine;
		//Cosine test
		/*cout << itCalcCosine->first << " -> " << itCalcCosine->second
				<< "/(" << sqrt(userDenominator) << "*"
				<< sqrt(denominatorCosineByUser[itCalcCosine->first]) << ") = ";
		cout << cosine << "\n";*/
	}
	//data.sortUserSimilarity(usr);
}

void Similarity::cosineByItem(int item){
	if(data.itemSimilarity.find(item) != data.itemSimilarity.end()) return;

	double cosine, itemDenominator;
	unordered_map<int,double> numeratorCosineByItem;
	unordered_map<int,double> denominatorCosineByItem;
	unordered_map<int,double> cosineByItem;

	unordered_map<int,int>::iterator itUsr = data.ratingsByItem[item].begin();
	for(;itUsr != data.ratingsByItem[item].end(); ++itUsr){

		unordered_map<int,int>::iterator itItem = data.ratingsByUser[itUsr->first].begin();
		/*Denominator calculator for the item*/
		itemDenominator += pow(itUsr->second - data.avgByItem[item],2);
		for(;itItem != data.ratingsByUser[itUsr->first].end(); itItem++){
			/*Denominator calculator*/
			if(denominatorCosineByItem.find(itItem->first) == denominatorCosineByItem.end()){
				unordered_map<int,int>::iterator itDenominator = data.ratingsByItem[itItem->first].begin();
				for(;itDenominator != data.ratingsByItem[itItem->first].end(); ++itDenominator){
					denominatorCosineByItem[itItem->first] += pow((itDenominator->second - data.avgByItem[itItem->first]),2);
				}
			}

			/*Numerator calculator*/
			if(numeratorCosineByItem.find(itItem->first) != numeratorCosineByItem.end()){
				numeratorCosineByItem[itItem->first] += (itUsr->second - data.avgByItem[item]) * (itItem->second - data.avgByItem[itItem->first]);
			} else {
				numeratorCosineByItem[itItem->first] = (itUsr->second - data.avgByItem[item]) * (itItem->second - data.avgByItem[itItem->first]);
			}
		}
	}

	/*Atualiza Consine*/
	unordered_map<int,double>::iterator itCalcCosine = numeratorCosineByItem.begin();
	for(;itCalcCosine != numeratorCosineByItem.end(); ++itCalcCosine){
		if(itCalcCosine->second != 0){
			cosine = itCalcCosine->second / (sqrt(itemDenominator) * sqrt(denominatorCosineByItem[itCalcCosine->first]));
		}
		data.itemSimilarity[item][itCalcCosine->first] = cosine;
		/*//Cosine test
		 cout << itCalcCosine->first << " -> " << itCalcCosine->second
				<< "/(" << sqrt(itemDenominator) << "*"
				<< sqrt(denominatorCosineByItem[itCalcCosine->first]) << ") = ";
		cout << cosine << "\n";*/
	}
	//data.sortItemSimilarity(item);
}
