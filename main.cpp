#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "evaluation/ErrorValidation.h"
#include "file_operation/Input.h"
#include "model/Dataset.h"
#include "recsys_methods/colaborative_filtring/ItemBased.h"
#include "recsys_methods/colaborative_filtring/UserBased.h"

using namespace std;

int main(int argc, char *argv[]) {
	time_t endTime;
	time_t startTime;
	struct tm * timeinfo;
	time(&startTime);
	Dataset dataUsr,dataItem;
	/*Read data*/
	time(&startTime);
	Input inpUsr(dataUsr, argv[1], argv[2]);
	//Input inpItem(dataItem, argv[1], argv[2]);
	time(&endTime);
	endTime -= startTime;
	//timeinfo = localtime(&endTime);
	//cerr << "Tempo de leitura: "<< endTime << "\n";
	time(&startTime);

	/*Prediction*/
	UserBased ub(dataUsr);
	ub.predictTarget(999999, 5, 10);
	//ItemBased ib(dataItem);
	//ib.predictTarget(30);
	dataUsr.printSolution();

	/*Validation*/
	//ErrorValidation valid;
	//valid.compareValidation(dataUsr);
	//valid.targetsGenerate(dataItem);
	//dataUsr.targetMerge(dataItem, 100, 300);

	time(&endTime);
	endTime -= startTime;
	//timeinfo = localtime(&endTime);
	cerr << "Tempo de Predição: "<< endTime << "\n";
}
