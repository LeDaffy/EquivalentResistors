#include "../include/engConvert.h"

long double engConvert(long double input, char modifier) {
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