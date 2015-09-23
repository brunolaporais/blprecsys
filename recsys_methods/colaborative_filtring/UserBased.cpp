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
	unordered_map<int,unordered_map<int,double> >::iterator itTargUsr = data.targetData.begin();
	for(;itTargUsr != data.targetData.end(); ++itTargUsr){
		calcSim.cosineByUser(itTargUsr->first);
		unordered_map<int,double>::iterator itTargItem = data.targetData[itTargUsr->first].begin();
		for(;itTargItem != data.targetData[itTargUsr->first].end(); ++itTargItem){
			rating = data.avgByUser[itTargUsr->first];
			numerator = 0.0;
			denominator = 0.0;

			/*need test the best value*/
			data.cutSimilarityData(itTargUsr->first, nbNumbers);

			unordered_map<int,double>::iterator itSim = data.similarityData[itTargUsr->first].begin();
			for(;itSim != data.similarityData[itTargUsr->first].end(); ++itSim){
				if(rating != 0){
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						numerator += itSim->second * (data.ratingsByUser[itSim->first][itTargItem->first] - data.avgByUser[itTargUsr->first]);
						/*cout << itSim->second << "*("
								<< data.ratingsByUser[itSim->first][itTargItem->first]
								<< "-" << data.avgByUser[itTargUsr->first]
								<< ")=" << numerator << "\n";*/
						denominator += abs(itSim->second);
					}
				} else {
					if(data.ratingsByUser[itSim->first].find(itTargItem->first) != data.ratingsByUser[itSim->first].end()){
						numerator += itSim->second * data.ratingsByUser[itSim->first][itTargUsr->second[itTargItem->first]];
						denominator += abs(itSim->second);
					}
				}
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

			/*//Output submission
			cout << "UserId:ItemId,Prediction\n";
			cout << "u";
			cout.width(7);
			cout.fill('0');
			cout << itTargUsr->first;
			cout.clear();
			cout << ":i";
			cout.width(7);
			cout.fill('0');
			cout << itTargItem->first;
			cout.clear();
			cout << "," << rating << "\n";*/
			data.targetData[itTargUsr->first][itTargItem->first] = rating;
		}
	}
}
