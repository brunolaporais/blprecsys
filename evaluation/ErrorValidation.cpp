/*
 * ErrorValidation.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: brunolaporais
 */

#include "../evaluation/ErrorValidation.h"

ErrorValidation::ErrorValidation() {
	// TODO Auto-generated constructor stub
}

ErrorValidation::~ErrorValidation() {
	// TODO Auto-generated destructor stub
}

void ErrorValidation::rmseValidation(Dataset &correctData){
	double rmse = 0.0;
	int n = 0;
	Dataset data;
	/*Read data*/
	Input inp(data,"ratings.csv","targets.csv");
	//UserBased ub(data);
	ItemBased ib(data);
	for(int i = 250; i < 1000; i++){
		//ub.predictTarget(i);
		ib.predictTarget(i);
		rmse = 0;
		n = 0;
		for(auto itUsrTarget = data.targetData.begin(); itUsrTarget != data.targetData.end(); ++itUsrTarget){
			for(auto itItemTarget = data.targetData[itUsrTarget->first].begin(); itItemTarget != data.targetData[itUsrTarget->first].end(); ++itItemTarget){
				//if(abs(correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] - itItemTarget->second) > 1){
					//cout << itUsrTarget->first << ":" << itItemTarget->first << " ";
					//cout << rmse << "+=" << correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] << "-" << itItemTarget->second << "\n";
				//}
				//if(std::isnan(rmse)) getchar();
				rmse += pow(correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] - itItemTarget->second,2);
				++n;
			}
		}
		rmse /= n;
		rmse = sqrt(rmse);
		cout << i << "-RMSE: " << rmse << "\n";
		//getchar();
	}
}

void ErrorValidation::targetsGenerate(Dataset &correctData){
	int n = 0;
	cout << "UserId:ItemId\n";
	for(auto itUsrTarget = correctData.ratingsByUser.begin(); itUsrTarget != correctData.ratingsByUser.end(); ++itUsrTarget){
		if(n >= 80000) break;
		for(auto itItemTarget = correctData.ratingsByUser[itUsrTarget->first].begin(); itItemTarget != correctData.ratingsByUser[itUsrTarget->first].end(); ++itItemTarget){
			if(n >= 80000) break;
			if((rand() % 10 + 1) > 7){
				targetSelected[itUsrTarget->first][itItemTarget->first] = 0.0;
				cout << "u";
				cout.width(7);
				cout.fill('0');
				cout << itUsrTarget->first;
				cout.clear();
				cout << ":i";
				cout.width(7);
				cout.fill('0');
				cout << itItemTarget->first;
				cout.clear();
				cout << "\n";
				n++;
			}
		}
	}
	ratingsGenerate(correctData);
}

void ErrorValidation::ratingsGenerate(Dataset &correctData){
	cout << "UserId:ItemId,Prediction\n";
	for(auto itUsrTarget = correctData.ratingsByUser.begin(); itUsrTarget != correctData.ratingsByUser.end(); ++itUsrTarget){
		for(auto itItemTarget = correctData.ratingsByUser[itUsrTarget->first].begin(); itItemTarget != correctData.ratingsByUser[itUsrTarget->first].end(); ++itItemTarget){
			if(targetSelected[itUsrTarget->first].find(itItemTarget->first) != targetSelected[itUsrTarget->first].end()) continue;
			cout << "u";
			cout.width(7);
			cout.fill('0');
			cout << itUsrTarget->first;
			cout.clear();
			cout << ":i";
			cout.width(7);
			cout.fill('0');
			cout << itItemTarget->first;
			cout.clear();
			cout << "," << itItemTarget->second << "\n";
		}
	}
}
