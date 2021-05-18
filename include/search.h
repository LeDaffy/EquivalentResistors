#ifndef SEARCH_H
#define SEARCH_H

void searchSingles(long double input, float precision, long double **missingVals, int arraySize, long double *oR1, float *outputPrecision);
void searchDoubleSeries(long double input, float precision, long double **missingVals, int arraySize, long double *oR1, long double *oR2, float *outputPrecision);

#endif