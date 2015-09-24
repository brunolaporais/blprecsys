/*
 * userBased.cpp
 *
 *  Created on: 22/09/2015
 *      Author: blpadmin
 */

#include "ItemBased.h"

ItemBased::ItemBased(Dataset &d):data(d) {
	// TODO Auto-generated constructor stub
}

ItemBased::~ItemBased() {
	// TODO Auto-generated destructor stub
}

//Need to be done
void ItemBased::predictTarget(int nbNumbers){
	Similarity calcSim(data);
	double rating, numerator = 0.0, denominator = 0.0;
	int iterNum = 0;
	unordered_map<int,unordered_map<int,double> >::iterator itTargUsr = data.targetData.begin();
	for(;itTargUsr != data.targetData.end(); ++itTargUsr){
		calcSim.cosineByUser(itTargUsr->first);
		unordered_map<int,double>::iterator itTargItem = data.targetData[itTargUsr->first].begin();
		for(;itTargItem != data.targetData[itTargUsr->first].end(); ++itTargItem){
			rating = data.avgByUser[itTargUsr->first];
			numerator = 0.0;
			denominator = 0.0;

			data.sortItemSimilarity(itTargUsr->first);
			iterNum = 0;

			unordered_map<int,double>::iterator itSim = data.userSimilarity[itTargUsr->first].begin();
			for(;itSim != data.userSimilarity[itTargUsr->first].end(); ++itSim){
				if(rating != 0){
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						++iterNum;
						numerator += itSim->second * (data.ratingsByUser[itSim->first][itTargItem->first] - data.avgByUser[itTargUsr->first]);
						/*cout << itSim->second << "*("
								<< data.ratingsByUser[itSim->first][itTargItem->first]
								<< "-" << data.avgByUser[itTargUsr->first]
								<< ")=" << numerator << "\n";*/
						denominator += abs(itSim->second);
					}
				} else {
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						++iterNum;
						numerator += itSim->second * data.ratingsByUser[itSim->first][itTargUsr->second[itTargItem->first]];
						denominator += abs(itSim->second);
					}
				}
				if(iterNum >= nbNumbers) break;
			}
			if(numerator != 0){
				rating += numerator / denominator;
			}
			if(rating == 0){
				rating = data.avgByItem[itTargItem->first];
			}
			if(rating == 0){
				rating = data.itemAvg;
			}
			if(rating > 10) rating = 10;
			if(rating < 1) rating = 1;

			cout << rating << "\n";
			data.targetData[itTargUsr->first][itTargItem->first] = rating;
		}
	}
	data.printSolution();
}
