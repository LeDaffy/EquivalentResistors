#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdarg.h>
#include <math.h>




double calcPrecision( long double desired, long double actual) {
    double percentDiff = (double)fabs( desired - actual ) / ( desired + actual ) * 200;
    return percentDiff;
}

#endif