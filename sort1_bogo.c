#include "sort1_bogo.h"
#include <stdlib.h>
#include <time.h>

//-------------------- Check Sorted --------------------//
int is_sorted(const int *a, size_t n){
    for (size_t i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i+1]) return 0;
    }
    return 1;
}

//-------------------- Shuffle --------------------//
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Fisher-Yates-Shuffle
void FisherYatesShuffle(int *a, size_t n){
    if(n < 2) return;

    for (size_t i = n-1; i > 0; i--)
    {
        size_t randPos = (size_t)rand() % (size_t)(i + 1);

        swap(&a[i], &a[(int)randPos]);
    }
    
}

//-------------------- Logical Order --------------------//
void bogosort(int *a, size_t n){

    while(!is_sorted(a, n)){
        FisherYatesShuffle(a, n);
    }
}