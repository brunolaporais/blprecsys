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

/*
 * targetMerge: Merge the results of item and user based.
 * mergeType: 1 - Dataset in parameter is the item based, 2 - Otherwise.
 */
void Dataset::targetMerge(Dataset &data, int mergeType){
	for(auto itTargUsr = targetData.begin(); itTargUsr != targetData.end(); ++itTargUsr){
		for(auto itTargItem = targetData[itTargUsr->first].begin(); itTargItem != targetData[itTargUsr->first].end(); ++itTargItem){
			if(mergeType == 1){
				if(userSimilarity[itTargUsr->first].size() > data.itemSimilarity[itTargItem->first].size()) {
					targetData[itTargUsr->first][itTargItem->first] = data.targetData[itTargUsr->first][itTargItem->first];
				}
			} else {
				if(itemSimilarity[itTargUsr->first].size() > data.userSimilarity[itTargItem->first].size()) {
					targetData[itTargUsr->first][itTargItem->first] = data.targetData[itTargUsr->first][itTargItem->first];
				}
			}
		}
	}
}

/*
 * indexItem: Index the terms on item and update the user model
 */
void Dataset::insertItem(int itemId, Item auxItem){
	string allText;
	itemContent[itemId] = auxItem;
	for(string s : auxItem.genre){
		allText.append(s);
		allText.append(" ");
	}
	for(string s : auxItem.actors){
		allText.append(s);
		allText.append(" ");
	}
	for(string s : auxItem.director){
		allText.append(s);
		allText.append(" ");
	}
	allText.append(auxItem.title);
	allText.append(" ");
	allText.append(auxItem.rated);
	allText.append(" ");
	allText.append(auxItem.released);
	allText.append(" ");
	allText.append(auxItem.writer);
	allText.append(" ");
	//allText.append(auxItem.plot);
	//allText.append(" ");
	allText.append(auxItem.language);
	allText.append(" ");
	allText.append(auxItem.country);
	allText.append(" ");
	Help::toLowerCase(allText);
	Help::removeAccents(allText);
	//Update the term frequency on item map
	for(string word : Help::split(allText, ' ')){
		if(mapStopWords.find(word) == mapStopWords.end()){
			if(indexItem.find(word) == indexItem.end()){
				indexItem[word][itemId] = 1;
			} else {
				indexItem[word][itemId] += 1;
			}
		}
	}
}
