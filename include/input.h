#ifndef INPUT_H
#define INPUT_H
#include "../include/resistor.h"

void handleInput(int argc, char *argv[], long double *inputResistance, float *precision, long double **removalValues, char **arrayCharPointer, int *removalValuesArraySize, int *lowerLimit, int *upperLimit, char *charModifier);

void handleInput2( int argc, char *argv[], resistance *inputResistance, float *precision, resistance **removalArray, int *arraySize);


#endif