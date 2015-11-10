/*
 * data.h
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "../util/Help.h"

using namespace std;
using namespace std::tr1;

#ifndef MODEL_DATA_H_
#define MODEL_DATA_H_

class Dataset {
public:
	Dataset();
	virtual ~Dataset();
	void cleanTarget();
	void sortUserSimilarity(int usr);
	void sortItemSimilarity(int item);
	void targetMerge(Dataset &d);
	void targetMerge(Dataset &d, int mergeType);
	void printSolution();
	void insertItem(int itemId, Item auxItem);
	double itemAvg, usrAvg;
	unordered_map<int,unordered_map<int,int> > ratingsByUser, ratingsByItem;
	unordered_map<int, double> avgByUser, avgByItem;
	unordered_map<int, int> usrMatrixID, itemMatrixID;
	unordered_map<int,unordered_map<int,double> > targetData, userSimilarity, itemSimilarity;
	unordered_map<int, Item> itemContent;
	unordered_map<string, unordered_map<int, double> > indexItem;
	unordered_map<int, unordered_map<string, double> > userModel;
	unordered_map<string, char*> mapStopWords;
};

#endif /* MODEL_DATA_H_ */
