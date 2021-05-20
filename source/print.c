#include "../include/print.h"



void printResistance( long double resistance ) {
    if (resistance < 1000) { printf("%.2Lf\u03A9", resistance); }
    else if (resistance > 1000 && resistance < 1000000) { printf("%.2Lfk\u03A9", resistance/1000); }
    else if (resistance > 1000000 && resistance < 1000000000) { printf("%.2LfM\u03A9", resistance/1000000); }
    else if (resistance > 1000000000 && resistance < 1000000000000) { printf("%.2LfG\u03A9", resistance/1000000000); }
    else if (resistance > 1000000000000 && resistance < 1000000000000000) { printf("%.2LfT\u03A9", resistance/1000000000000); }
    else { printf("%.0Lf\u03A9", resistance); }
}

void printSingle( long double resistance, float precision, float minPrecision) {
    if ( precision < minPrecision ) {
        printResistance(resistance);
        printf("\t %.3f%%\n", precision);
        printf("###########\n");
        printf("     \u2022\n");
        printf("     |\n");
        printf("     |\n");
        printf("    |\u203E|\n");
        printf("    | |\n");
        printf("   ");
        printResistance(resistance);
        printf("\n");
        printf("    | |\n");
        printf("    |_|\n");
        printf("     |\n");
        printf("     |\n");
        printf("     \u2022\n");
        printf("###########\n\n");
    }
}

void printDoubleSeries( long double R1, long double R2, float precision, float minPrecision) {
    if ( precision < minPrecision ) {
        printResistance(R1);
        printf(" + ");
        printResistance(R2);
        printf(" = ");
        printResistance(R1+R2);
        printf("\t %.3f%%\n", precision);

        printf("###########\n");
        printf("     \u2022\n");
        printf("     |\n");
        printf("     |\n");
        printf("    |\u203E|\n");
        printf("    | |\n");
        printf("   ");
        printResistance(R1);
        printf("\n");
        printf("    | |\n");
        printf("    |_|\n");
        printf("     |\n");
        printf("    |\u203E|\n");
        printf("    | |\n");
        printf("   ");
        printResistance(R2);
        printf("\n");
        printf("    | |\n");
        printf("    |_|\n");
        printf("     |\n");
        printf("     |\n");
        printf("     \u2022     \n");
        printf("###########\n\n");
    }
}