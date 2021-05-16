#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "operations.h"

int main ( int argc, char *argv[] ) {
	
	long double * resistors;
	resistors = malloc(24 * sizeof(long double) );

	//set resistances
	{
		resistors[0] = 1.0;
		resistors[1] = 1.1;
		resistors[2] = 1.2;
		resistors[3] = 1.3;
		resistors[4] = 1.5;
		resistors[5] = 1.6;
		resistors[6] = 1.8;
		resistors[7] = 2.0;
		resistors[8] = 2.2;
		resistors[9] = 2.4;
		resistors[10] = 2.7;
		resistors[11] = 3.0;
		resistors[12] = 3.3;
		resistors[13] = 3.6;
		resistors[14] = 3.9;
		resistors[15] = 4.3;
		resistors[16] = 4.7;
		resistors[17] = 5.1;
		resistors[18] = 5.6;
		resistors[19] = 6.2;
		resistors[20] = 6.8;
		resistors[21] = 7.5;
		resistors[22] = 8.2;
		resistors[23] = 9.1;
	}
	long double input = 0.0;
	char modifier;
	for ( int i = 0; i < argc; i++ ) {
		if ( !strcmp( "-i", argv[i]) ) {
			sscanf( argv[i+1], "%Lf%c", &input, &modifier);
			//printf( "input: %Lf modifier: %c\n" , input, modifier );
			input = notation( input, modifier );
			//printf( "final calculated input: %.1Lf\n", input );
		}
	}

	if ( resistors[23] < input ) {
		resistors = realloc( resistors, 2*24*sizeof( long double ) );
		for ( int i = 0; i < 24; i++ ) {
			resistors[i+24] = resistors[i] * 10;
		}
	}


	for (int i = 0; i < 48; i++ ) {
		if ( i % 5 == 0 && i != 0 )
			printf( "%.1Lf\n", resistors[i] );
		else
			printf( "%.1Lf  ", resistors[i] );
	}
	free(resistors);
	return EXIT_SUCCESS;
}