#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort1_bogo.h"

const size_t MAX_LINES = 10;
const size_t MAX_LINE_LEN = 256;

int main(){
    //Sets Seed for randomizer based on current Time
    srand((unsigned)time(NULL));

    /*
    //Bogo Test
    int testArray[] = {7, 3, 2, 4, 1};
    size_t n = sizeof(testArray) / sizeof(testArray[0]);
    bogosort(testArray, n);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", testArray[i]);
    }
    printf("\n");
    */

    //Reads File and gives char array back
    FILE *file = fopen("tests/small_input.txt", "r");
    if (file == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }

    int numbersPerLine[MAX_LINES][MAX_LINE_LEN];
    size_t valuesPerLine[MAX_LINES];
    size_t numLines = 0;

    while (numLines < MAX_LINES) {
        size_t numValues = 0;

        while (numValues < MAX_LINE_LEN && fscanf(file, "%d", &numbersPerLine[numLines][numValues]) == 1) 
        {
            numValues++;
        }

        if (numValues == 0) break;

        valuesPerLine[numLines] = numValues;
        numLines++;

        fscanf(file, "%*[^\n]\n");
    }
    fclose(file);


    for (size_t i = 0; i < numLines; i++)
    {
        bogosort(numbersPerLine[i], valuesPerLine[i]);
    }
    


    //Test Output
    for (size_t i = 0; i < numLines; i++) {
        printf("Zeile %zu: ", i + 1);
        for (size_t j = 0; j < valuesPerLine[i]; j++) {
            printf("%d ", numbersPerLine[i][j]);
        }
        printf("\n");
    }





    return 0;
}