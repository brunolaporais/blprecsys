/*
 * input.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: brunolaporais
 */

#include "input.h"

input::input(dataset &d, string rating, string target):data(d) {
	ratingFile = rating;
	targetFile = target;
	readRatings();
	readTargets();
}

input::~input() {
}

void input::readRatings(){
	ifstream inFile(ratingFile, ios::in | ios::app | ios::binary);
	string line, rateAux;
	int usr, item;
	double rate;
	if(inFile.is_open()){
		getline(inFile, line);
		while(getline(inFile, line)){
			usr = stoi(line.substr(1,line.find(":") - 1));
			item = stoi(line.substr(line.find(":") + 2,line.find(",") - line.find(":")));
			rateAux = line.substr(line.find(",") + 1,line.size());
			rateAux.replace(rateAux.find(","),1,".");
			rate = stod(rateAux);

			/*Insert new user (Items by user)*/
			unordered_map<int, unordered_map<int,double> >::iterator iterRatingByUser = data.ratingsByUser.find(usr);
			if(iterRatingByUser != data.ratingsByUser.end()){
				cout << "Erro ao inserir novo usuário";
			} else {
				data.ratingsByUser[usr][item] = rate;
			}

			/*Insert new item (Users by item)*/
			unordered_map<int, unordered_map<int,double> >::iterator iterRatingByItem = data.ratingsByItem.find(item);
			if(iterRatingByItem != data.ratingsByItem.end()){
				cout << "Erro ao inserir novo item";
			} else {
				data.ratingsByItem[item][usr] = rate;
			}

			iterRatingByUser = data.ratingsByUser.find(usr);

			cout << iterRatingByUser->first << "\n";

			/* Show test
			cout << usr << "\n";
			cout << item << "\n";
			cout << setprecision(11) << rate << "\n";*/
			cout << line << "\n";
			break;
		}
		inFile.close();
	}
}

void input::readTargets(){

}
