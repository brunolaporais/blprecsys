/*
 * Item.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: brunolaporais
 */

#include "Item.h"

Item::Item() {

}

Item::Item(string jsonText) {
	loadJson(jsonText);
}

Item::~Item() {
	// TODO Auto-generated destructor stub
}

void Item::loadJson(string jsonText){
	if(jsonText.empty()) return;

	size_t posAux;
	int intAux;
	string strAux;
	posAux = jsonText.find("\\\",\"");
	if(posAux != string::npos){
		strAux = jsonText.substr(posAux+2,jsonText.size());
		jsonText = jsonText.replace(posAux,jsonText.find("\\\",\"")+1,"\"");
		jsonText.append(strAux);
	}
	json::Value input = json::Deserialize(jsonText.c_str());
	json::Object jsonObject = input.ToObject();
	if (input.GetType() == json::NULLVal){
		cerr << "Erro no arquivo JSON!";
		return;
	}
	if(jsonObject["Response"].ToString() == "False") return;

	//vector<string>
	genre = Help::split(jsonObject["Genre"].ToString(), ',');
	director = Help::split(jsonObject["Director"].ToString(), ',');
	actors = Help::split(jsonObject["Actors"].ToString(), ',');

	//string
	title = jsonObject["Title"].ToString();
	rated = jsonObject["Rated"].ToString();
	released = jsonObject["Released"].ToString();
	writer = jsonObject["Writer"].ToString();
	plot = jsonObject["Plot"].ToString();
	language = jsonObject["Language"].ToString();
	country = jsonObject["Country"].ToString();

	//int
	strAux = jsonObject["Year"].ToString();
	if (isdigit(strAux[0])){
	    year = stoi(strAux);
	}

	strAux = jsonObject["Runtime"].ToString();
	strAux = strAux.substr(0,strAux.find(" "));
	if (isdigit(strAux[0])){
		runtime = stoi(strAux);
	}

	strAux = jsonObject["Awards"].ToString();
	if (isdigit(strAux[0])){
		awards = stoi(strAux);
	}

	strAux = jsonObject["imdbVotes"].ToString();
	if (isdigit(strAux[0])){
		imbdVotes = stoi(strAux);
	}

	//double
	strAux = jsonObject["imdbRating"].ToString();
	if (isdigit(strAux[0])){
		imbdRatings = stod(strAux);
	}
}
