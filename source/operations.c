#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdarg.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>




double calcPrecision( long double desired, long double actual) {
    double percentDiff = (double)fabs( desired - actual ) / ( desired + actual ) * 200;
    return percentDiff;
}

long double parallel2( long double R1, long double R2 ) {
    return ( 1 / (1/R1 + 1/R2) );
}

long double series2( long double R1, long double R2 ) {
    return ( (R1 + R2) );
}

long double parallel3( long double R1, long double R2, long double R3) {
    return ( 1 / ((1/R1) + (1/R2) + (1/R3)) );
}

long double series3( long double R1, long double R2, long double R3 ) {
    return ( R1 + R2 + R3 );
}

#endif