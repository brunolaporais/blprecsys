#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "file_operation/Input.h"
#include "model/Dataset.h"
#include "recsys_methods/colaborative_filtring/UserBased.h"
#include "validation/ErrorValidation.h"

using namespace std;

int main(int argc, char *argv[]) {
	Dataset data;
	/*Read data*/
	Input inp(data, argv[1], argv[2]);

	//UserBased ub(data);
	//ub.predictTarget(60);
	ErrorValidation valid;
	valid.rmseValidation(data);
}
