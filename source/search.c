#include "../include/search.h"
#include "../include/print.h"
#include "../include/operations.h"
#include <stdio.h>
#include <math.h>



void searchResistances( long double input, char modifier, float precision, long double **missingVals, int arraySize ) {
    long double stdResistors[] = {
        1.0, 1.1, 1.2, 1.3, 1.5,
        1.6, 1.8, 2.0, 2.2, 2.4,
        2.7, 3.0, 3.3, 3.6, 3.9,
        4.3, 4.7, 5.1, 5.6, 6.2,
        6.8, 7.5, 8.2, 9.1,
    };

    //printf("%c\n", modifier);
    if ( modifier != '0' ) {
        for ( int i = 0; i < 24; i++ ) {
            stdResistors[i] = stdResistors[i] / 1000;
        }
    }
    printf("\n");

    int k1 = 1;
    int k2 = 1;
    int k3 = 1;

    long double currentR1 = stdResistors[0];
    long double currentR2 = stdResistors[0];
    long double currentR3 = stdResistors[0];

    float singlePrecision = 100;
    float doubleSeriesPrecision = 100;
    float doubleParallelPrecision = 100;
    float tripleSeriesPrecision = 100;
    float tripleParallelPrecision = 100;
    float tripleMixSeriesPrecision = 100;
    float tripleMixParallelPrecision = 100;

    long double singleR1 = 0;
    long double doubleSeriesR1 = 0;
    long double doubleSeriesR2 = 0;
    long double doubleParallelR1 = 0;
    long double doubleParallelR2 = 0;
    long double tripleSeriesR1 = 0;
    long double tripleSeriesR2 = 0;
    long double tripleSeriesR3 = 0;
    long double tripleParallelR1 = 0;
    long double tripleParallelR2 = 0;
    long double tripleParallelR3 = 0;

    /*
        |-|
        R1R2
        |-|
         R3
    */
    long double tripleMixSeriesR1 = 100;
    long double tripleMixSeriesR2 = 100;
    long double tripleMixSeriesR3 = 100;

    /*
        |-|
        R1R3
        R2|
        |-|
    */
    long double tripleMixParallelR1 = 100;
    long double tripleMixParallelR2 = 100;
    long double tripleMixParallelR3 = 100;


    for (int i = 0; currentR1/5 < input; i++) {
        if (i%24 == 0 && i != 0) { k1*=10; }
        currentR1 = stdResistors[i%24]*k1;

        //goto loopend if its a missing value
        for ( int l = 0; l < arraySize; l++ ) {
            if ( fabs(currentR1 - *(*missingVals+l)) < .05) { 
                //printf("Value of %.1Lf matches missing value of %.1Lf\n", R1, *(*missingVals+l));
                goto ENDLOOP1;
            }
        }
        
        //find closest single resistor
        if (calcPrecision(currentR1, input) < singlePrecision && calcPrecision(currentR1, input) < precision) {
            singleR1 = currentR1;
            singlePrecision = calcPrecision(currentR1, input);
        }

        for (int j = 0; currentR2/5 < input; j++ ) {
            if (j%24 == 0 && j != 0) { k2*=10; }
            currentR2 = stdResistors[j%24]*k2;
            //goto loopend if its a missing value
            
            for ( int l = 0; l < arraySize; l++ ) {
                if ( fabs(currentR2 - *(*missingVals+l)) < .05) { 
                    //printf("Value of %.1Lf matches missing value of %.1Lf\n", R1, *(*missingVals+l));
                    goto ENDLOOP2;
                }
            }
            
            //find closest double series
            if( calcPrecision(series2(currentR1,currentR2), input) < doubleSeriesPrecision && calcPrecision(series2(currentR1, currentR2), input) < precision ) {
                doubleSeriesR1 = currentR1;
                doubleSeriesR2 = currentR2;
                doubleSeriesPrecision = calcPrecision(series2(currentR1,currentR2), input);
            }
            //find closest double parallel
            if( calcPrecision(parallel2(currentR1,currentR2), input) < doubleParallelPrecision && calcPrecision(parallel2(currentR1,currentR2), input) < precision ) {
                doubleParallelR1 = currentR1;
                doubleParallelR2 = currentR2;
                doubleParallelPrecision = calcPrecision(parallel2(currentR1,currentR2), input);
            }


            
            for (int k = 0; currentR3/5 < input; k++) {
                if (k%24 == 0 && k != 0) { k3*=10; }
                currentR3 = stdResistors[k%24]*k3;
                
                //printf("currentR1: %.1Lf \tcurrentR2: %.1Lf \t\tcurrentR3: %.1Lf\n", currentR1, currentR2, currentR3);

                //goto loopend if its a missing value
                
                for ( int l = 0; l < arraySize; l++ ) {
                    if ( fabs(currentR3 - *(*missingVals+l)) < .05) { 
                        //printf("Value of %.1Lf matches missing value of %.1Lf\n", R1, *(*missingVals+l));
                        goto ENDLOOP3;
                    }
                }
                
                
                //find closest triple series
                if( calcPrecision(series3(currentR1,currentR2, currentR3), input) < tripleSeriesPrecision && calcPrecision(series3(currentR1, currentR2, currentR3), input) < precision ) {
                    tripleSeriesR1 = currentR1;
                    tripleSeriesR2 = currentR2;
                    tripleSeriesR3 = currentR3;
                    tripleSeriesPrecision = calcPrecision(series3(currentR1,currentR2, currentR3), input);
                }

                //find closest triple parallel
                if( calcPrecision(parallel3(currentR1,currentR2, currentR3), input) < tripleParallelPrecision && calcPrecision(parallel3(currentR1, currentR2, currentR3), input) < precision ) {
                    tripleParallelR1 = currentR1;
                    tripleParallelR2 = currentR2;
                    tripleParallelR3 = currentR3;
                    tripleParallelPrecision = calcPrecision(parallel3(currentR1,currentR2, currentR3), input);
                }
                
                ENDLOOP3: ;
            }
            k3 = 1;
            currentR3 = 1;
            ENDLOOP2: ;
            
           //printf("currentR1: %.1Lf \tcurrentR2: %.1Lf \t\tcurrentR3: %.1Lf\n", currentR1, currentR2, currentR3);
        }
        k2 = 1;
        currentR2 = 1;
        ENDLOOP1: ;
    }

    printf("%Lf\n", singleR1);
    printf("%Lf+%Lf = %Lf\n", doubleSeriesR1, doubleSeriesR2, series2(doubleSeriesR1, doubleSeriesR2));
    printf("%Lf||%Lf = %Lf\n", doubleParallelR1, doubleParallelR2, parallel2(doubleParallelR1, doubleParallelR2));
    printf("%Lf+%Lf+%Lf = %Lf\n", tripleSeriesR1, tripleSeriesR2, tripleSeriesR3, series3(tripleSeriesR1, tripleSeriesR2, tripleSeriesR3));
    printf("%Lf||%Lf||%Lf = %Lf\n", tripleParallelR1, tripleParallelR2, tripleParallelR3, parallel3(tripleParallelR1, tripleParallelR2, tripleParallelR3));
}