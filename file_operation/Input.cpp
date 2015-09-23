/*
 * input.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include "Input.h"

Input::Input(Dataset &d, string rating, string target):data(d) {
	ratingFile = rating;
	targetFile = target;
	readRatings();
	readTargets();
}

Input::~Input() {
}

void Input::readRatings(){
	ifstream inFile(ratingFile, ios::in | ios::app | ios::binary);
	string line, rateAux;
	int usr, item;
	double rate;
	if(inFile.is_open()){
		getline(inFile, line);
		while(getline(inFile, line)){
			if(line.empty()){
				break;
			}
			usr = stoi(line.substr(1,line.find(":") - 1));
			item = stoi(line.substr(line.find(":") + 2,line.find(",") - line.find(":")));
			rateAux = line.substr(line.find(",") + 1,line.size());
			rateAux = rateAux.substr(0,rateAux.find(","));
			rate = stoi(rateAux);

			/*Insert new user (Items by user)*/
			data.ratingsByUser[usr][item] = rate;

			if(data.avgByUser.find(usr) == data.avgByUser.end()){
				data.avgByUser[usr] = rate;
			} else {
				data.avgByUser[usr] += rate;
			}

			/*Insert new item (Users by item)*/
			data.ratingsByItem[item][usr] = rate;

			/*Hashmap test*/
			//cout << setprecision(11) << data.ratingsByItem[item][usr] << "\n";

			/*Show test
			cout << usr << "\n";
			cout << item << "\n";
			cout << setprecision(11) << rate << "\n";*/
			//cout << line << "\n";
		}
		inFile.close();

		/*Refresh avg*/
		unordered_map<int, double>::iterator itAvg = data.avgByUser.begin();
		for(;itAvg != data.avgByUser.end();++itAvg){
			itAvg->second = itAvg->second / data.ratingsByUser[itAvg->first].size();
		}
	}
}

void Input::readTargets(){

}
