#include "../include/search.h"
#include "../include/print.h"
#include <stdio.h>
#include <math.h>

void searchSingles(long double input, float precision, long double **missingVals, int arraySize) {
    long double stdResistors[] = {
        1.0, 1.1, 1.2, 1.3, 1.5,
        1.6, 1.8, 2.0, 2.2, 2.4,
        2.7, 3.0, 3.3, 3.6, 3.9,
        4.3, 4.7, 5.1, 5.6, 6.2,
        6.8, 7.5, 8.2, 9.1,
    };

	int j = 1;
	long double singleClosest = 0;
	double lowestPrecision = 100;
	for (int i = 0; stdResistors[i%24]*j/10< input; i++) {
		if (i%24 == 0 && i!=0) { j*=10; }
        for (int k = 0; k<arraySize; k++) {
            if ( fabs(stdResistors[i%24]*j - *(*missingVals+k)) < .05) { 
                printf("Value of %.1Lf matches missing value of %.1Lf\n", stdResistors[i%24]*j, *(*missingVals+k));
                goto LOOPEND;
            }
        }
		//printf("%.1Lf\n", stdResistors[i%24]*j);
		double loopPrecision = calcPrecision(stdResistors[i%24]*j, input);
		if ( loopPrecision < precision  && loopPrecision < lowestPrecision) {
			singleClosest = stdResistors[i%24]*j;
			lowestPrecision = loopPrecision;
		}
        LOOPEND: 
        ;
	}
	printResistance(singleClosest);
	printf("\t");
	printf("%.2f%%\n",lowestPrecision);
    printSingle(singleClosest);   
}


void searchDoubleSeries(long double input, float precision) {

}