#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/engConvert.h"
#include "../include/input.h"

long double stdResistors[] = {
1.0, 1.1, 1.2, 1.3, 1.5,
1.6, 1.8, 2.0, 2.2, 2.4,
2.7, 3.0, 3.3, 3.6, 3.9,
4.3, 4.7, 5.1, 5.6, 6.2,
6.8, 7.5, 8.2, 9.1,
};

int main (int argc, char *argv[]) {
	printf("\n\n\n");

	long double inputResistance = 0.0;
	float precision = 5.0;
	long double *arrayPointer = NULL;
	int arraySize = 0;
	handleInput(argc, &argv[0], &inputResistance, &precision, &arrayPointer, &arraySize);


	/*
	//test if the values passed by reference changed
	printf("\n\n\n");
	printf("The value in main of inputResistance is: %.1Lf\n", inputResistance);
	printf("The value in main of precision is: %.1f\n", precision);
	printf("\n\n\n");

	printf("Outside of main, check if the array has been allocated properly.\n");

	printf("The size of the array is %d\n", arraySize);

	//printf("The elements of the array are: \n");
	for (int i = 0; i < arraySize; i++) {
		printf("%.1Lf\n", *(arrayPointer+i));
	}*/


	free(arrayPointer);
	arrayPointer = NULL;
	return EXIT_SUCCESS;
}