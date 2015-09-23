/*
 * data.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include "Dataset.h"

Dataset::Dataset() {
	usrAvg = 0.0;
	itemAvg = 0.0;
}

Dataset::~Dataset() {
	// TODO Auto-generated destructor stub
}

void Dataset::cutSimilarityData(int usr, int nbNumbers){
	unordered_map<int,double>::iterator itSims = similarityData[usr].begin();
	vector<pair<int, double>> usrSim;

	if(similarityData[usr].size() <= nbNumbers) return;

	for (auto itSim = similarityData[usr].begin(); itSim != similarityData[usr].end(); ++itSim){
		usrSim.push_back(*itSim);
	}

	sort(usrSim.begin(), usrSim.end(),[=](pair<int, double>& a, pair<int, double>& b){ return a.second > b.second;});

	similarityData[usr].clear();
	for(int i = 0; i < nbNumbers && i < usrSim.size(); ++i){
		similarityData[usr].insert(usrSim[i]);
	}
}
