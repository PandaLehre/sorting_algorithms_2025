#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort1_bogo.h"
#include "../converter/array_converter.h"

int main(){
    //Sets Seed for randomizer based on current Time
    srand((unsigned)time(NULL));

    while(1){


        int chosenTestCase = 1;
        float *unsortedArray = NULL;
        size_t numbersOfElements = 0;
        const char *fileName = NULL;
        
        size_t countElementsSwitched = 0;
        size_t countsArrayChecked = 0;
        
        printf(
            "Gebe die entsprechende Zahl fuer die Test Datei an: \n"
            "1. floatTest.txt\n"
            "2. intTest.txt\n"
        );
        scanf("%d", &chosenTestCase);

        switch (chosenTestCase)
        {
        case 1:
            fileName = "../tests/floatTest.txt";
            break;
        case 2:
            fileName = "../tests/intTest.txt";
            break;
        default:
            break;
        }

        unsortedArray = textToFloatArray(fileName, &numbersOfElements);
        if(!unsortedArray) return 1;

        printf("Array Before: \n");
        for (size_t i = 0; i < numbersOfElements; i++)
        {
            printf("%.2f ", unsortedArray[i]);
        }
        printf("\n");

        bogosort(unsortedArray, numbersOfElements, &countElementsSwitched, &countsArrayChecked);
        printf("After \033[31m%zu\033[0m Shuffels and \033[31m%zu\033[0m Array Checkes (Bogo Sort): \n", countElementsSwitched, countsArrayChecked);
        for (size_t i = 0; i < numbersOfElements; i++)
        {
            printf("%.2f ", unsortedArray[i]);
        }
        printf("\n-------------------------------------\n");

    }
    return 0;
}