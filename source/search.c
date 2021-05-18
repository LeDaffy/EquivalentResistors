#include "../include/search.h"
#include "../include/print.h"
#include <stdio.h>
#include <math.h>




void searchSingles(long double input, float precision, long double **missingVals, int arraySize, long double *oR1, float *outputPrecision) {
    
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
	for (int i = 0; stdResistors[i%24]*j/1.5< input; i++) {
		if (i%24 == 0 && i!=0) { j*=10; }
        for (int k = 0; k<arraySize; k++) {
            if ( fabs(stdResistors[i%24]*j - *(*missingVals+k)) < .05) { 
                //printf("Value of %.1Lf matches missing value of %.1Lf\n", stdResistors[i%24]*j, *(*missingVals+k));
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
    /*
    if(singleClosest != 0) {
        printResistance(singleClosest);
        printf("\t");
        printf("%.2f%%\n",lowestPrecision);
        printSingle(singleClosest);   
    } else {
        printf("No single resistor matches within precision range\n");
    }*/
    *outputPrecision = lowestPrecision;
    *oR1 = singleClosest;
}


void searchDoubleSeries(long double input, float precision, long double **missingVals, int arraySize, long double *oR1, long double *oR2, float *outputPrecision) {
    long double stdResistors[] = {
        1.0, 1.1, 1.2, 1.3, 1.5,
        1.6, 1.8, 2.0, 2.2, 2.4,
        2.7, 3.0, 3.3, 3.6, 3.9,
        4.3, 4.7, 5.1, 5.6, 6.2,
        6.8, 7.5, 8.2, 9.1,
    };
    long double R1, R2;
    long double lR1, lR2;
    int k1, k2;
    k1 = 1;
    k2 = 1;
    float lowestPrecision = 100;
    long double sum;
    for ( int i = 0; stdResistors[i%24]*k1/1.5 < input; i++ ) {
        if (i%24 == 0 && i != 0) { k1*=10; }
        R1 = stdResistors[i%24]*k1;
        for ( int l = 0; l < arraySize; l++ ) {
            if ( fabs(R1 - *(*missingVals+l)) < .05) { 
                //printf("Value of %.1Lf matches missing value of %.1Lf\n", R1, *(*missingVals+l));
                goto LOOP1RESET;
            }
        }
        for ( int j = 0; stdResistors[j%24]*k2/1.5 < input; j++ ) {
            if (j%24 == 0 && j != 0) { k2*=10; }
            R2 = stdResistors[j%24]*k2;
            for ( int l = 0; l < arraySize; l++ ) {
                if ( fabs(R2 - *(*missingVals+l)) < .05) { 
                    //printf("Value of %.1Lf matches missing value of %.1Lf\n", R2, *(*missingVals+l));
                    goto LOOP2RESET;
                }
            }
            //printf("%.1Lf + %.1Lf\n", R1, R2);
            if( calcPrecision(R1+R2, input) < lowestPrecision && calcPrecision(R1+R2, input) < precision ) {
                sum = R1 + R2;
                lR1 = R1;
                lR2 = R2;
                lowestPrecision = calcPrecision(R1+R2, input);
            }
            

            LOOP2RESET:
            ;
        }
        LOOP1RESET:
        R2 = 1.0;
        k2 = 1;
    }

    /*
    printResistance(lR1);
    printf(" + ");
    printResistance(lR2);
    printf(" = ");
    printResistance(sum);
    printf("\t %.1f%%\n", lowestPrecision);
    printDoubleSeries(lR1, lR2);*/
    *outputPrecision = lowestPrecision;
    *oR1 = lR1;
    *oR2 = lR2;
}