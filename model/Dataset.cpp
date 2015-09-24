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

void Dataset::sortUserSimilarity(int usr){
	unordered_map<int,double>::iterator itSims = userSimilarity[usr].begin();
	vector<pair<int, double>> usrSim;

	for (auto itSim = userSimilarity[usr].begin(); itSim != userSimilarity[usr].end(); ++itSim){
		usrSim.push_back(*itSim);
	}

	sort(usrSim.begin(), usrSim.end(),[=](pair<int, double>& a, pair<int, double>& b){ return a.second > b.second;});

	userSimilarity[usr].clear();
	for(int i = 0;i < usrSim.size(); ++i){
		userSimilarity[usr].insert(usrSim[i]);
	}
}

void Dataset::sortItemSimilarity(int item){
	unordered_map<int,double>::iterator itSims = itemSimilarity[item].begin();
	vector<pair<int, double>> itemSim;

	for (auto itSim = itemSimilarity[item].begin(); itSim != itemSimilarity[item].end(); ++itSim){
		itemSim.push_back(*itSim);
	}

	sort(itemSim.begin(), itemSim.end(),[=](pair<int, double>& a, pair<int, double>& b){ return a.second > b.second;});

	itemSimilarity[item].clear();
	for(int i = 0;i < itemSim.size(); ++i){
		itemSimilarity[item].insert(itemSim[i]);
	}
}

void Dataset::printSolution(){
	cout << "UserId:ItemId,Prediction\n";
	for(auto itTargUsr = targetData.begin(); itTargUsr != targetData.end(); ++itTargUsr){
		for(auto itTargItem = targetData[itTargUsr->first].begin(); itTargItem != targetData[itTargUsr->first].end(); ++itTargItem){
			//Output submission
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
			cout << "," << itTargItem->second << "\n";
		}
	}
}

void Dataset::targetMerge(Dataset &d){
	for(auto itTargUsr = targetData.begin(); itTargUsr != targetData.end(); ++itTargUsr){
		for(auto itTargItem = targetData[itTargUsr->first].begin(); itTargItem != targetData[itTargUsr->first].end(); ++itTargItem){
			targetData[itTargUsr->first][itTargItem->first] = (itTargItem->second + d.targetData[itTargUsr->first][itTargItem->first])/2;
		}
	}
}
