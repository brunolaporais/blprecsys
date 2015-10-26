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
Input::Input(Dataset &d, string rating, string target, string content):data(d) {
	ratingFile = rating;
	targetFile = target;
	contentFile = content;
	readRatings();
	readTargets();
	readContents();
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
			if(data.avgByItem.find(item) == data.avgByItem.end()){
				data.avgByItem[item] = rate;
			} else {
				data.avgByItem[item] += rate;
			}

			/*Hashmap test*/
			//cout << setprecision(11) << data.ratingsByItem[item][usr] << "\n";

			/*Show test
			cout << usr << "\n";
			cout << item << "\n";
			cout << setprecision(11) << rate << "\n";*/
			//cout << line << "\n";
		}
		inFile.close();

		/*Refresh avg by user*/
		unordered_map<int, double>::iterator itAvgUsr = data.avgByUser.begin();
		for(;itAvgUsr != data.avgByUser.end();++itAvgUsr){
			itAvgUsr->second = itAvgUsr->second / data.ratingsByUser[itAvgUsr->first].size();
			data.usrAvg += itAvgUsr->second;
		}
		data.usrAvg /= data.avgByUser.size();

		/*Refresh avg by item*/
		unordered_map<int, double>::iterator itAvgItem = data.avgByItem.begin();
		for(;itAvgItem != data.avgByItem.end();++itAvgItem){
			itAvgItem->second = itAvgItem->second / data.ratingsByItem[itAvgItem->first].size();
			data.itemAvg += itAvgItem->second;
		}
		data.itemAvg /= data.avgByItem.size();
	}
}

void Input::readTargets(){
	ifstream inFile(targetFile, ios::in | ios::app | ios::binary);
	string line;
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

			/*Insert new target*/
			data.targetData[usr][item] = 0.0;
		}
		inFile.close();
	}
}

void Input::readContents(){
	ifstream inFile(contentFile, ios::in | ios::app | ios::binary);
	string line, jsonText;
	Item auxItem;
	int item;
	if(inFile.is_open()){
		getline(inFile, line);
		while(getline(inFile, line)){
			if(line.empty()){
				break;
			}
			item = stoi(line.substr(1,line.find(",") - 1));
			jsonText = line.substr(line.find(",")+1,line.size());
			/*Insert new content*/
			auxItem = Item(jsonText);
			data.insertItem(item, auxItem);
		}
		inFile.close();
	}

	loadStopWords();
}

void Input::loadStopWords(){
	ifstream stopWords ("stopWords.txt");
	string line;
	char *aux = new char('0');
	if(stopWords.is_open()){
		while(getline(stopWords,line)){
			data.mapStopWords[line] = aux;
		}
	}else{
		cerr<< "stopWords.txt não encontrado no diretório ";
	}
	delete(aux);
}
