#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "file_operation/input.h"
#include "model/dataset.h"

using namespace std;

int main(int argc, char *argv[]) {
	dataset data;
	input inp(data,"/media/brunolaporais/BACKUP/Shared/RecSys/ratings.csv",
		"/media/brunolaporais/BACKUP/Shared/RecSys/targets.csv");
}
