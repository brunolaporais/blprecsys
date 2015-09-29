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

void UserBased::predictTarget(int nbNumbers){
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
			iterNum = 0;

			unordered_map<int,double>::iterator itSim = data.userSimilarity[itTargUsr->first].begin();
			for(;itSim != data.userSimilarity[itTargUsr->first].end(); ++itSim){
				if(rating != 0){
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						++iterNum;
						numerator += itSim->second * (data.ratingsByUser[itSim->first][itTargItem->first] - data.avgByUser[itTargUsr->first]);
						/*if(itTargUsr->first == 28867 && itTargItem->first == 120863){
							cout << itSim->second << "*("
								<< data.ratingsByUser[itSim->first][itTargItem->first]
								<< "-" << data.avgByUser[itTargUsr->first]
								<< ")=" << numerator << "\n";
							getchar();
						}*/
						denominator += abs(itSim->second);
					}
				} else {
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						++iterNum;
						numerator += itSim->second * data.ratingsByUser[itSim->first][itTargUsr->second[itTargItem->first]];
						denominator += abs(itSim->second);
					}
				}

				//if(iterNum >= nbNumbers) break; /*Had been worse the solution*/
			}
			//cout << rating << "+=" << numerator << "/" << denominator << "\n";
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

			//cout << rating << "\n";
			rating = rating;
			data.targetData[itTargUsr->first][itTargItem->first] = rating;
			/*if(std::isnan(rating)) {
				cout<<"Erro!\n";
				getchar();
			}*/
			//if(itTargUsr->first == 15176 && itTargItem->first == 1119646) getchar();
		}
	}
	//data.printSolution();
}
