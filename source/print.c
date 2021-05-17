#include "include/print.h"


void printResistors( long double resistance, int spaces ) { 
    wchar_t Omega = 0x03A9;
    wchar_t Overline = 0x203E;
    setlocale(LC_CTYPE, "");
    printSpaces(spaces); wprintf(L" |\n");
    printSpaces(spaces); wprintf(L"|%lc|\n", Overline );
    printSpaces(spaces); wprintf(L"| |\n");
    printSpaces(spaces); wprintf(L"%.1Lf%lc\n", resistance, Omega);
    printSpaces(spaces); wprintf(L"| |\n");
    printSpaces(spaces); wprintf(L"|_|\n");
    printSpaces(spaces); wprintf(L" |\n");
}