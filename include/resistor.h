#ifndef RESISTOR_H
#define RESISTOR_H
typedef struct resistance {
    long double resistance;
    char modifier;
} resistance;

void printResistor2(resistance R1);
resistance normalizeResistor( resistance R1);
#endif