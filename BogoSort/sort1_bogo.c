#include "sort1_bogo.h"
#include <stdlib.h>
#include <time.h>

//-------------------- Check Sorted --------------------//
int is_sorted(const float *a, size_t n, size_t *checked){
    (*checked)++;
    if(n < 2) return 1;
    for (size_t i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i+1]) return 0;
    }
    return 1;
}

//-------------------- Shuffle --------------------//
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

//Fisher-Yates-Shuffle
void FisherYatesShuffle(float *a, size_t n, size_t *switched){
    if(n < 2) return;

    for (size_t i = n-1; i > 0; i--)
    {
        size_t randPos = (size_t)rand() % (size_t)(i + 1);

        swap(&a[i], &a[(int)randPos]);
    }
    (*switched)++;
    
}

//-------------------- Logical Order --------------------//
void bogosort(float *a, size_t n, size_t *switched, size_t *checked){

    while(!is_sorted(a, n, checked)){
        FisherYatesShuffle(a, n, switched);
    }
}