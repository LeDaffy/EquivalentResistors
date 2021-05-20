#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../include/engConvert.h"
#include "../include/input.h"
#include "../include/operations.h"
#include "../include/print.h"
#include "../include/search.h"
#include "../include/resistor.h"

int main (int argc, char *argv[]) {
	resistance inputResistance;
	float inputPrecision = 5.0;
	resistance *inputMissingResistors = NULL;
	int numMissingResistors = 0;
	handleInput2(argc, &argv[0], &inputResistance, &inputPrecision, &inputMissingResistors, &numMissingResistors);

	printf("Input resistance: ");
	printResistor2(inputResistance);
	printf("\t Minimum precision: %f %%\nMissing Resistors:\n", inputPrecision);
	for( int i = 0; i < numMissingResistors; i++ ) {
		printResistor2(*(inputMissingResistors+i));
		printf("\n");
	}
	printf("\n~~Equivalent Solutions~~\n");


	free(inputMissingResistors);
	inputMissingResistors = NULL;
	return EXIT_SUCCESS;
}