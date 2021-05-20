#include <stdio.h>
#include <stdlib.h>
#include "../include/resistor.h"

void printResistor2(resistance R1) {
    if (R1.modifier != '0')
        printf("%Lf%c", R1.resistance, R1.modifier);
    else
        printf("%Lf", R1.resistance);
}

resistance normalizeResistor( resistance R1) {
    char mods[] = {'0', 'k', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y'};
    int modNum;
    for (int i = 0; i < 9; i++){
        if (mods[i] == R1.modifier)
            modNum = i;
    }
    while (R1.resistance > 1000) {
        if (R1.modifier == 'Y') { 
            printf("Input Overflow\n");
            exit(-1);
        }
        R1.resistance /= 1000;
        modNum++;
        if (modNum > 9)
            exit(-1);
        R1.modifier = mods[modNum];
    }
    while (R1.resistance < 1) {
        R1.resistance *= 1000;
        modNum--;
        R1.modifier = mods[modNum];
    }
    return R1;
}