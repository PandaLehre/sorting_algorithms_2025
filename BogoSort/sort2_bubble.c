#include <stdio.h>

#include "../converter/array_converter.h"



void swap(float *a, int pos1, int pos2){
    float tmp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = tmp;
}

void bubbleSort(float *a,  size_t n, size_t *switched, size_t *checked){
    for (size_t i = n; i > 1; i--)
    {
        for (size_t j = 0; j < n - 1; j++)
        {
            (*checked)++;

            if (a[j] > a[j+1])
            {
                swap(a, j, j+1);
                (*switched)++;
            }
            
        }
        
    }
}