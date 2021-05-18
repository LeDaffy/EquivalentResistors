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
	

	float p1, p2;
	long double sR1, s2R1, s2R2;
	searchSingles(inputResistance, precision, &arrayPointer, arraySize, &sR1, &p1);
	searchDoubleSeries(inputResistance, precision, &arrayPointer, arraySize, &s2R1, &s2R2, &p2);
	if ( p1 < p2 ) {		
		printSingle(sR1, p1, precision);
		printDoubleSeries(s2R1, s2R2, p2, precision);
	} else {
		printDoubleSeries(s2R1, s2R2, p2, precision);
		printSingle(sR1, p1, precision);
	}




	free(arrayPointer);
	arrayPointer = NULL;
	return EXIT_SUCCESS;
}