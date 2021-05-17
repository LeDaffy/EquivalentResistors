#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/engConvert.h"
#include "../include/input.h"
#include "../include/operations.h"
#include "../include/print.h"
#include "../include/search.h"

int main (int argc, char *argv[]) {
	printf("\n\n\n");

	long double inputResistance = 0.0;
	float precision = 5.0;
	long double *arrayPointer = NULL;
	int arraySize = 0;
	int lowerLimit = 1;
	int upperLimit = 2;
	handleInput(argc, &argv[0], &inputResistance, &precision, &arrayPointer, &arraySize, &lowerLimit, &upperLimit);

	/*
	printf("\n");
	printf("\n");
	printf("Input resistance %.1Lf\n", inputResistance);
	printf("Input precision: %f\n", precision);
	printf("Upper limit is: %d\n", upperLimit);
	printf("Lower limit is: %d\n", lowerLimit);

	printf("\n");
	printf("Number of missing resistors: %d\n", arraySize);
	for (int i = 0; i < arraySize; i++) {
		printf("Missing resistor: %.1Lf\n", arrayPointer[i]);
	}*/

	searchSingles(inputResistance, precision, &arrayPointer, arraySize);




	free(arrayPointer);
	arrayPointer = NULL;
	return EXIT_SUCCESS;
}