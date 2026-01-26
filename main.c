#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort1_bogo.h"

const MAX_LINES = 10;
const MAX_LINE_LEN = 256;

int main(){
    //Sets Seed for randomizer based on current Time
    srand(time(NULL));

    //Reads File and gives char array back
    FILE *file = fopen("tests/small_input.txt", "r");
    if (file == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }
    char linesOutput[MAX_LINES][MAX_LINE_LEN];
    size_t lineCount = 0;

    while (lineCount < MAX_LINES && fgets(linesOutput[lineCount], MAX_LINE_LEN, file)) {
        lineCount++;
    }
    fclose(file);

    //Test Output
    for (size_t i = 0; i < lineCount; i++) {
        printf("Zeile %zu: %s", i, linesOutput[i]);
    }

    return 0;
}