/*
 * ErrorValidation.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: brunolaporais
 */

#include <ctime>
#include "../evaluation/ErrorValidation.h"

ErrorValidation::ErrorValidation() {
	// TODO Auto-generated constructor stub
}

ErrorValidation::~ErrorValidation() {
	// TODO Auto-generated destructor stub
}

void ErrorValidation::compareValidation(Dataset &correctData){
	double rmse = 0.0;
	int n = 0;
	Dataset dataUsr, dataItem;
	/*Read data*/
	Input inpUsr(dataUsr,"ratings.csv","targets.csv");
	Input inpItem(dataItem,"ratings.csv","targets.csv");
	UserBased ub(dataUsr);
	//MatrixFact mf(dataUsr,30);
	ItemBased ib(dataItem);
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 20; j++){
			//mf.predictTarget(10,0.0002,0.02);
			ub.predictTarget(0, i, j);
			//ib.predictTarget(0, i, j);
			//dataUsr.targetMerge(dataItem, 1);
			rmse = 0;
			n = 0;
			int count = 0;
			for(auto itUsrTarget = dataUsr.targetData.begin(); itUsrTarget != dataUsr.targetData.end(); ++itUsrTarget){
				for(auto itItemTarget = dataUsr.targetData[itUsrTarget->first].begin(); itItemTarget != dataUsr.targetData[itUsrTarget->first].end(); ++itItemTarget){
			//for(auto itUsrTarget = dataItem.targetData.begin(); itUsrTarget != dataItem.targetData.end(); ++itUsrTarget){
				//for(auto itItemTarget = dataItem.targetData[itUsrTarget->first].begin(); itItemTarget != dataItem.targetData[itUsrTarget->first].end(); ++itItemTarget){
					rmse += pow(correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] - itItemTarget->second,2);
					++n;
				}
			}
			rmse /= n;
			rmse = sqrt(rmse);
			cout << i << "/" << j << "-RMSE: " << rmse << "\n";
		}
	}
}

void ErrorValidation::contentValidation(Dataset &correctData){
	double rmse = 0.0;
	int n = 0, count;
	long double sysTime = 0;
	for(int i = 1; i <= 80; i++){
		sysTime = time(0);
		Dataset dataRb;
		/*Read data*/
		Input inpRb(dataRb, "ratings.csv", "targets.csv", "/mnt/SHARE/RecSys/pa2/content.csv");
		//Input inpRb(dataRb, "ratings.csv", "targets.csv", "/mnt/Shared/RecSys/pa2/content.csv");
		TfIdfBased tfb(dataRb);
		//tfb.predictTarget(i/10.0);
		tfb.predictTarget(10,i * 1000);
		rmse = 0;
		n = 0;
		count = 0;
		for(auto itUsrTarget = dataRb.targetData.begin(); itUsrTarget != dataRb.targetData.end(); ++itUsrTarget){
			for(auto itItemTarget = dataRb.targetData[itUsrTarget->first].begin(); itItemTarget != dataRb.targetData[itUsrTarget->first].end(); ++itItemTarget){
				rmse += pow(correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] - itItemTarget->second,2);
				++n;
			}
		}
		rmse /= n;
		rmse = sqrt(rmse);
		//cout << (i/10.0) <<"-RMSE: " << rmse << "\n";
		//cout << "RMSE: " << rmse;
		//cout << " - " << i * 1000 << " - " << time(0) - sysTime << "\n";
		cout << time(0) - sysTime << "\n";
	}
}

void ErrorValidation::rmseValidation(Dataset &correctData){
	double rmse = 0.0;
	int n = 0;
	Dataset dataUsr, dataItem;
	/*Read data*/
	Input inpUsr(dataUsr,"ratings.csv","targets.csv", "content.csv");
	Input inpItem(dataItem,"ratings.csv","targets.csv", "content.csv");
	UserBased ub(dataUsr);
	ItemBased ib(dataItem);
	//for(int i = 250; i < 1000; i++){
		ub.predictTarget(999999, 5, 10);
		ib.predictTarget(30, 5, 10);
		//dataUsr.targetMerge(dataItem, 200);
		rmse = 0;
		n = 0;
		for(auto itUsrTarget = dataUsr.targetData.begin(); itUsrTarget != dataUsr.targetData.end(); ++itUsrTarget){
			for(auto itItemTarget = dataUsr.targetData[itUsrTarget->first].begin(); itItemTarget != dataUsr.targetData[itUsrTarget->first].end(); ++itItemTarget){
				rmse += pow(correctData.ratingsByUser[itUsrTarget->first][itItemTarget->first] - itItemTarget->second,2);
				++n;
			}
		}
		rmse /= n;
		rmse = sqrt(rmse);
		cout << 1 << "-RMSE: " << rmse << "\n";
		getchar();
	//}
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
