/*
 * Item.h
 *
 *  Created on: Oct 23, 2015
 *      Author: brunolaporais
 */

#include <iostream>
#include <stdio.h>
#include <vector>

#include "../lib/json.h"
#include "../util/Help.h"

#ifndef MODEL_ITEM_H_
#define MODEL_ITEM_H_

using namespace std;

class Item {
public:
	vector<string> genre, actors, director;
	string title, rated, released, writer,
		plot, language,	country;
	int year, runtime, awards, imbdVotes;
	double imbdRatings;
	Item();
	Item(string jsonText);
	virtual ~Item();
	void loadJson(string jsonText);
};

#endif /* MODEL_ITEM_H_ */
