#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdarg.h>
#include <math.h>

long double series(int count, ...);
long double parallel(int count, ...);
void printParallel( long double arg1, long double arg2 );
void printSeries( long double arg1);
void printSpaces( int numSpaces );
long double notation( long double input, char modifier );
int precision( long double desired, long double actual, float precision );

long double series(int count, ...) {
    va_list args;

    va_start( args, count );

    long double sum = 0.0;

    for ( int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }

    va_end( args );
    return sum;
}

long double parallel(int count, ...) {
    va_list args;

    va_start( args, count );

    long double sum = 0.0;

    for ( int i = 0; i < count; i++ ) {
        sum += 1 / ( va_arg(args, double) );
    }

    va_end( args );

    return ( 1 / sum );
}

void printParallel( long double arg1, long double arg2 ) {
    printSpaces( 15 ); printf( "|----------|\n" );
    printSpaces( 15 ); printf( "|          |\n" );
    printf( "%17.1Lf\u03A9 %9.1Lf\u03A9\n", arg1, arg2 );
    printSpaces( 15 ); printf( "|          |\n" );
    printSpaces( 15 ); printf( "|----------|\n" );
}

void printSeries( long double arg1 ) {
    printSpaces( 20 ); printf( "|\n" );
    printSpaces( 20 ); printf( "|\n" );
    printf( "%22.1Lf\u03A9\n", arg1 );
    printSpaces( 20 ); printf( "|\n" );
    printSpaces( 20 ); printf( "|\n" );
}

void printSpaces( int numSpaces ) {
    for ( int i = 0; i < numSpaces; i++ ) {
        printf( " " );
    }
}


long double notation( long double input, char modifier ) { 
    if ( modifier == 'Y' )
        input *= 1000000000000000000000000.0;
    else if ( modifier == 'Z')
        input *= 1000000000000000000000.0;
    else if ( modifier == 'E' )
        input *= 1000000000000000000.0;
    else if ( modifier == 'P' )
        input *= 1000000000000000.0;
    else if ( modifier == 'T' )
        input *= 1000000000000.0;
    else if ( modifier == 'G' )
        input *= 1000000000.0;
    else if ( modifier == 'M' )
        input *= 1000000.0;
    else if ( modifier == 'k' )
        input *= 1000.0;
    else
        input *= 1;
    return input;
}


int precision( long double desired, long double actual, float precision ) {
    long double percentDiff = abs( desired - actual ) / ( desired + actual ) * 200;
    if ( percentDiff < precision )
        return 1;
    else
        return 0;
}

#endif