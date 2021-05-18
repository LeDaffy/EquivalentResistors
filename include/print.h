#ifndef PRINT_H
#define PRINT_H
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "operations.h"



void printResistance( long double resistance );
void printSingle( long double resistance, float precision, float minPrecision);
void printDoubleSeries( long double R1, long double R2, float precision, float minPrecision);
#endif