#include <stdio.h>

#include "sort3_selection.h"

void swap(float *a, int pos1, int pos2){
    float tmp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = tmp;
}

void selectionsort(float *a,  size_t n, size_t *switched, size_t *checked){

    for (size_t i = 0; i < n - 2; i++)
    {
        size_t minIndex = i;

        for (size_t j = 0; j < n - 1; j++)
        {
            (*checked)++;
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        
        if(minIndex != i){
            (*switched)++;
            swap(a, i, minIndex);
        }
    }

}