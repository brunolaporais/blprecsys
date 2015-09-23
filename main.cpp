#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "file_operation/Input.h"
#include "model/Dataset.h"
#include "recsys_methods/Similarity.h"

using namespace std;

int main(int argc, char *argv[]) {
	Dataset data;
	Input inp(data, argv[1], argv[2]);

	Similarity sim(data);
	sim.cosineByUser(26762);
}
