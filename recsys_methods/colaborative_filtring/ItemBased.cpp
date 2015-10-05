/*
 * ItemBased.cpp
 *
 *  Created on: Sep 24, 2015
 *      Author: brunolaporais
 */

#include "ItemBased.h"

ItemBased::ItemBased(Dataset &d):data(d)  {
	// TODO Auto-generated constructor stub

}

ItemBased::~ItemBased() {
	// TODO Auto-generated destructor stub
}

void ItemBased::predictTarget(int nbNumbers, int minItems, int minUsers){
	Similarity calcSim(data);
	double rating, numerator = 0.0, denominator = 0.0;
	int iterNum = 0;
	unordered_map<int,unordered_map<int,double> >::iterator itTargUsr = data.targetData.begin();
	for(;itTargUsr != data.targetData.end(); ++itTargUsr){
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
				calcSim.cosineByItem(itTargItem->first);
				rating = 0;
				numerator = 0.0;
				denominator = 0.0;
				iterNum = 0;
				unordered_map<int,double>::iterator itSim = data.itemSimilarity[itTargItem->first].begin();
				for(;itSim != data.itemSimilarity[itTargItem->first].end(); ++itSim){
					if(data.ratingsByUser[itTargUsr->first].find(itSim->first) != data.ratingsByUser[itTargUsr->first].end()){
						numerator += itSim->second * data.ratingsByItem[itSim->first][itTargUsr->first];
						/*cout << itSim->second << "*("
								<< data.ratingsByUser[itSim->first][itTargItem->first]
								<< "-" << data.avgByUser[itTargUsr->first]
								<< ")=" << numerator << "\n";*/
						denominator += abs(itSim->second);
						++iterNum;
					}
					if(iterNum >= nbNumbers && nbNumbers > 0) break;
				}
				if(numerator != 0) {
					rating = numerator / denominator;
				}
			}
			if(rating > 10) rating = 10;
			if(rating < 1) rating = 1;
			rating = rating;
			data.targetData[itTargUsr->first][itTargItem->first] = rating;
		}
	}
}
