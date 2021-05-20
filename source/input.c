#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/input.h"
#include "../include/engConvert.h"
#include "../include/resistor.h"


void handleInput2( int argc, char *argv[], resistance *inputResistance, float *precision, resistance **removalArray, int *arraySize) {
    char mods[] = {'0', 'k', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y'};
    //inputResistance->modifier = '0';
	//inputResistance->resistance = 0.0;
    for ( int i = 0; i < argc; i++ ) {
        //handle user input resistance
        if ( !strcmp( "-i", argv[i]) ) {
			//printf("Input detected\n");
            sscanf( argv[i+1], "%Lf%c", &(inputResistance->resistance), &(inputResistance->modifier));
            //check invalid input
		    *inputResistance = normalizeResistor(*inputResistance);			
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
            int removeStartVal, removeEndVal, removeArraySize;
			removeStartVal = i+1;
			for (int j = 1; ((i+j)<argc) && (strncmp("-", argv[i+j], 1) != 0); j++) {
				removeEndVal = j+i;
			}
			removeArraySize = removeEndVal - removeStartVal+1;

			//pass back the array size to the main function
            *arraySize = removeArraySize;
            //allocate array on the heap
            *removalArray = (resistance*)malloc(removeArraySize*sizeof(resistance));
            if (*removalArray == NULL) {
                exit(-1);
            }
            //convert argv[] (chars) to long doubles with possible engineering notation
            for ( int j = 0; j < removeArraySize; j++ ) {
				//initialize resistors
				(*removalArray+j)->resistance = 0.0;
				(*removalArray+j)->modifier = '0';
				sscanf(argv[removeStartVal+j], "%Lf%c", &((*removalArray+j)->resistance), &((*removalArray+j)->modifier));
				*(*removalArray+j) = normalizeResistor(*(*removalArray+j));
            }
		}
    }
}