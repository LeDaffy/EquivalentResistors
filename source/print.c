#include "../include/print.h"



void printResistance( long double resistance ) {
    if (resistance < 1000) { printf("%.1Lf\u03A9", resistance); }
    else if (resistance > 1000 && resistance < 1000000) { printf("%.0Lfk\u03A9", resistance/1000); }
    else if (resistance > 1000000 && resistance < 1000000000) { printf("%.0LfM\u03A9", resistance/1000000); }
    else if (resistance > 1000000000 && resistance < 1000000000000) { printf("%.0LfG\u03A9", resistance/1000000000); }
    else if (resistance > 1000000000000 && resistance < 1000000000000000) { printf("%.0LfT\u03A9", resistance/1000000000000); }
    else { printf("%.0Lf\u03A9", resistance); }
}

void printSingle( long double resistance) {
    printf("###########\n");
    printf("#    \u2022    #\n");
    printf("#    |    #\n");
    printf("#    |    #\n");
    printf("#   |\u203E|   #\n");
    printf("#   | |   #\n");
    printf("#  ");
    printResistance(resistance);
    printf("   #\n");
    printf("#   | |   #\n");
    printf("#   |_|   #\n");
    printf("#    |    #\n");
    printf("#    |    #\n");
    printf("#    \u2022    #\n");
    printf("###########\n");
}