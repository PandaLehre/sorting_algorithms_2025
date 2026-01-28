#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort3_selection.h"
#include "../converter/array_converter.h"

int main(){

    while(1){


        int chosenTestCase = 1;
        float *unsortedArray = NULL;
        size_t numbersOfElements = 0;
        const char *fileName = NULL;
        
        size_t countElementsSwitched = 0;
        size_t countsArrayChecked = 0;


        printf(
            "Gebe die entsprechende Zahl fuer eine bestimme Test Datei ein:\n"
            " 1. all_equal.txt\n"
            " 2. duplicates_heavy.txt\n"
            " 3. float_random.txt\n"
            " 4. float_reverse.txt\n"
            " 5. float_sorted.txt\n"
            " 6. large_random_20.txt\n"
            " 7. large_random_100.txt\n"
            " 8. large_random_1000.txt\n"
            " 9. large_sorted_100.txt\n"
            "10. medium_random_2.txt\n"
            "11. medium_random.txt\n"
            "12. medium_reverse.txt\n"
            "13. medium_sorted.txt\n"
            "14. single_element.txt\n"
            "15. small_duplicates.txt\n"
            "16. small_random.txt\n"
            "17. small_reverse.txt\n"
            "18. small_sorted.txt\n"
            "19. two_elements.txt\n"
            "> "
        );
        
        scanf("%d", &chosenTestCase);
        switch (chosenTestCase)
        {
            case 1: fileName = "../tests/all_equal.txt"; break;
            case 2: fileName = "../tests/duplicates_heavy.txt"; break;
            case 3: fileName = "../tests/float_random.txt"; break;
            case 4: fileName = "../tests/float_reverse.txt"; break;
            case 5: fileName = "../tests/float_sorted.txt"; break;
            case 6: fileName = "../tests/large_random_20.txt"; break;
            case 7: fileName = "../tests/large_random_100.txt"; break;
            case 8: fileName = "../tests/large_random_1000.txt"; break;
            case 9: fileName = "../tests/large_sorted_100.txt"; break;
            case 10: fileName = "../tests/medium_random_2.txt"; break;
            case 11: fileName = "../tests/medium_random.txt"; break;
            case 12: fileName = "../tests/medium_reverse.txt"; break;
            case 13: fileName = "../tests/medium_sorted.txt"; break;
            case 14: fileName = "../tests/single_element.txt"; break;
            case 15: fileName = "../tests/small_duplicates.txt"; break;
            case 16: fileName = "../tests/small_random.txt"; break;
            case 17: fileName = "../tests/small_reverse.txt"; break;
            case 18: fileName = "../tests/small_sorted.txt"; break;
            case 19: fileName = "../tests/two_elements.txt"; break;

            default:
            printf("Ungueltige Auswahl.\n");
            continue;
        }

        unsortedArray = textToFloatArray(fileName, &numbersOfElements);
        if(!unsortedArray) return 1;

        printf("Array Before: \n");
        for (size_t i = 0; i < numbersOfElements; i++)
        {
            printf("%.2f ", unsortedArray[i]);
        }
        printf("\n");

        selectionsort(unsortedArray, numbersOfElements, &countElementsSwitched, &countsArrayChecked);
        printf("After \033[31m%zu\033[0m Swaps and \033[31m%zu\033[0m Array Checkes (Selection Sort): \n", countElementsSwitched, countsArrayChecked);
        for (size_t i = 0; i < numbersOfElements; i++)
        {
            printf("%.2f ", unsortedArray[i]);
        }
        printf("\n-------------------------------------\n");

    }
    return 0;
}