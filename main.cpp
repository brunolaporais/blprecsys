#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "evaluation/ErrorValidation.h"
#include "file_operation/Input.h"
#include "model/Dataset.h"
#include "recsys_methods/colaborative_filtring/ItemBased.h"
#include "recsys_methods/colaborative_filtring/UserBased.h"

using namespace std;

int main(int argc, char *argv[]) {
	Dataset dataUsr,dataItem;
	/*Read data2*/
	Input inpUsr(dataUsr, argv[1], argv[2]);
	Input inpItem(dataItem, argv[1], argv[2]);

	//UserBased ub(dataUsr);
	//ub.predictTarget(999999);
	//ItemBased ib(dataItem);
	//ib.predictTarget(30);
	ErrorValidation valid;
	valid.rmseValidation(dataUsr);
	//valid.targetsGenerate(data2);
	//dataUsr.targetMerge(dataItem, 100, 300);
	//dataUsr.printSolution();
}
