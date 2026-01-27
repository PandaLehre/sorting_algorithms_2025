#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort1_bogo.h"
#include "../converter/array_converter.h"

int main(){
    //Sets Seed for randomizer based on current Time
    srand((unsigned)time(NULL));

    int chosenTestCase = 1;
    float *unsortedArray = NULL;
    size_t numbersOfElements = 0;
    const char *fileName = NULL;

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

    printf("Vorherhige Array: \n");
    for (size_t i = 0; i < numbersOfElements; i++)
    {
        printf("%.2f ", unsortedArray[i]);
    }
    printf("\n");

    bogosort(unsortedArray, numbersOfElements);
    printf("Nach Bogo Sort: \n");
    for (size_t i = 0; i < numbersOfElements; i++)
    {
        printf("%.2f ", unsortedArray[i]);
    }
    printf("\n");


    return 0;
}