#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/input.h"
#include "../include/engConvert.h"


void handleInput(int argc, char *argv[], long double *inputResistance, float *precision, long double **removalValues, int *removalValuesArraySize, int *lowerLimit, int *upperLimit) {
    //printf("Entering handleInput()\n");
    /*printf("Input is being handled\n");

    printf("Check if the first two function parameters are properly pass\n");

    printf("The number of arguments is: %d\n", argc);
    */ //check the first two arguments are passed properly
    

    //start handling input
    long double input = 0.0;
    char modifier;
    for ( int i = 0; i < argc; i++ ) {
        //printf("The %dth arguments is %s \n", i, argv[i]);


        //handle user input resistance
        if ( !strcmp( "-i", argv[i]) ) {
			//printf("Input detected\n");
            sscanf( argv[i+1], "%Lf%c", &input, &modifier);
			input = engConvert( input, modifier) ;
            //printf("The user input resistance has been read as %.1Lf\n", input);
            *inputResistance = input;
            if (*inputResistance <= 0) {
                printf("Input resistance must be greater than 0\n");
                exit(-1);
            }
		}
        //handle user input precision
        else if ( !strcmp("-p", argv[i]) ) {
			sscanf( argv[i+1], "%f", &(*precision));
            if (*precision < 0 || *precision > 100) {
                printf(" Precision must be a postive integer representing 0 to 100 percent\n");
                exit(-1);
            }
		}

        
        //handle resistors the user doesn't have
        else if ( !strcmp("-r", argv[i]) ) {

            //determine which indices of argv[] hold the removal values:
            int removeStartVal = 0;
            int removeEndVal = 0;
            int removeArraySize = 0;
			removeStartVal = i+1;
			for (int j = 1; ((i+j)<argc) && (strncmp("-", argv[i+j], 1) != 0); j++) {
				//printf("Detect\n");
				removeEndVal = j+i;
			}
			removeArraySize = removeEndVal - removeStartVal+1;
            

            //pass back the array size to the main function
            *removalValuesArraySize = removeArraySize;
            //allocate array on the heap
            *removalValues = (long double*)malloc(removeArraySize*sizeof(long double));
            if (*removalValues == NULL) {
                exit(-1);
            }
            //convert argv[] (chars) to long doubles with possible engineering notation
            for ( int j = 0; j < removeArraySize; j++ ) {
                long double tempVal;
                char tempMod;
                sscanf(argv[removeStartVal+j], "%Lf%c", &tempVal, &tempMod);
                //value read in
                //printf("\nThe value read from the array is %.1Lf\n", engConvert(tempVal, tempMod));
                *(*removalValues+j) = engConvert(tempVal, tempMod);\
                //printf("The value inside of the double pointer is %.1Lf", *(*removalValues+j));
                tempMod = 'a';
            }

		}

        else if ( !strcmp("-ul", argv[i]) ) {
            if (atoi(argv[i+1]) > 4) {
                printf("Upper limit greater than 4 not supported\n");
                exit(-1);
            }
            *upperLimit = atoi(argv[i+1]);
        }
        else if ( !strcmp("-ll", argv[i]) ) {
            if (atoi(argv[i+1]) < 1) {
                printf("Lower limit less than 1 not supported\n");
                exit(-1);
            }
            *lowerLimit = atoi(argv[i+1]);
        }
    }

    //printf("Exiting handleInput()\n\n");
}