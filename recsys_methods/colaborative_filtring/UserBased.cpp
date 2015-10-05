/*
 * userBased.cpp
 *
 *  Created on: 22/09/2015
 *      Author: blpadmin
 */

#include "UserBased.h"

UserBased::UserBased(Dataset &d):data(d) {
	// TODO Auto-generated constructor stub
}

UserBased::~UserBased() {
	// TODO Auto-generated destructor stub
}

void UserBased::predictTarget(int nbNumbers, int minItems, int minUsers){
	time_t endTime;
	time_t startTime;
	Similarity calcSim(data);
	double rating, numerator = 0.0, denominator = 0.0;
	int iterNum = 0;
	unordered_map<int,unordered_map<int,double> >::iterator itTargUsr = data.targetData.begin();

	for(;itTargUsr != data.targetData.end(); ++itTargUsr){
		calcSim.cosineByUser(itTargUsr->first);

		unordered_map<int,double>::iterator itTargItem = data.targetData[itTargUsr->first].begin();
		for(;itTargItem != data.targetData[itTargUsr->first].end(); ++itTargItem){
			if(data.ratingsByUser[itTargUsr->first].size() <= minItems &&
				data.ratingsByItem[itTargItem->first].size() <= minUsers){
				rating = data.itemAvg;
			} else if(data.ratingsByUser[itTargUsr->first].size() <= minItems){
				rating = data.avgByItem[itTargItem->first];
			} else if(data.ratingsByItem[itTargItem->first].size() <= minUsers){
				rating = data.avgByUser[itTargUsr->first];
			} else {
				rating = data.avgByUser[itTargUsr->first];
				numerator = 0.0;
				denominator = 0.0;
				iterNum = 0;

				unordered_map<int,double>::iterator itSim = data.userSimilarity[itTargUsr->first].begin();
				for(;itSim != data.userSimilarity[itTargUsr->first].end(); ++itSim){
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						numerator += itSim->second * (data.ratingsByUser[itSim->first][itTargItem->first] - data.avgByUser[itTargUsr->first]);
						/*if(itTargUsr->first == 28867 && itTargItem->first == 120863){
							cout << itSim->second << "*("
								<< data.ratingsByUser[itSim->first][itTargItem->first]
								<< "-" << data.avgByUser[itTargUsr->first]
								<< ")=" << numerator << "\n";
							getchar();
						}*/
						denominator += abs(itSim->second);
						++iterNum;
					}
					if(iterNum >= nbNumbers && nbNumbers > 0) break;
				}
				if(numerator != 0) {
					rating += numerator / denominator;
				}
			}
			if(rating > 10) rating = 10;
			if(rating < 1) rating = 1;
			rating = rating;
			data.targetData[itTargUsr->first][itTargItem->first] = rating;
		}
	}
}
