/*
 * Help.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: brunolaporais
 */

#include "Help.h"

using namespace std;
using namespace Help;

string Help::strTrim(string s){
	string aux = s;

	// remove white space in front
	if(isspace(aux[0])) aux = aux.substr(1,aux.size());

	// remove trailing white space
	if(isspace(aux[aux.size()-1])) aux = aux.substr(0,aux.size()-2);

	return aux;
}

vector<string> Help::split(string s, const char &d){
	vector<string> result;
	string buff = "";
	for(auto n:s){
		if(n != d) buff+=n;
		if(n == d && buff != ""){
			result.push_back(strTrim(buff));
			buff = "";
		}
	}
	if(buff != "") result.push_back(buff);
	return result;
}
