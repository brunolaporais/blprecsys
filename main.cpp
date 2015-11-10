#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "evaluation/ErrorValidation.h"
#include "file_operation/Input.h"
#include "model/Dataset.h"
#include "recsys_methods/colaborative_filtring/ItemBased.h"
#include "recsys_methods/colaborative_filtring/UserBased.h"
#include "recsys_methods/content_based/TfIdfBased.h"

using namespace std;

int main(int argc, char *argv[]) {
	//time_t endTime;
	//time_t startTime;
	//struct tm * timeinfo;
	//time(&startTime);
	//Dataset dataUsr,dataItem;
	/*Read data*/
	//time(&startTime);
	//Input inpUsr(dataUsr, argv[2], argv[3]);
	//Input inpItem(dataUsr, argv[2], argv[3]);
	//time(&endTime);
	//endTime -= startTime;
	//timeinfo = localtime(&endTime);
	//cerr << "Tempo de leitura: "<< endTime << "\n";
	//time(&startTime);

	/*Prediction*/
	//UserBased ub(dataUsr);
	//ub.predictTarget(0, 10, 8);
	//ItemBased ib(dataUsr);
	//ib.predictTarget(0, 10, 40);
	//dataUsr.printSolution();

	/*Validation*/
	//ErrorValidation valid;
	//valid.compareValidation(dataUsr);
	//valid.targetsGenerate(dataItem);
	//dataUsr.targetMerge(dataItem, 100, 300);

	//time(&endTime);
	//endTime -= startTime;
	//timeinfo = localtime(&endTime);
	//cerr << "Tempo de Predição: "<< endTime << "\n";

	/*
	 * Content Based
	 * */
	Dataset dataRb;
	Input inpRb(dataRb, argv[2], argv[3], argv[1]);
	//TfIdfBased tfb(dataRb);
	//tfb.predictTarget(4);
	//dataRb.printSolution();

	/*Validation*/
	ErrorValidation valid;
	valid.contentValidation(dataRb);
}
