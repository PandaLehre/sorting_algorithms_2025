#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort1_bogo.h"

void print_array(const int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    int myNumbers[] = {5, 3, 2, 7};
    size_t n = sizeof(myNumbers) / sizeof(myNumbers[0]);

    printf("TEST 1: Bereits sortiert\n");
    print_array(myNumbers, n);

    bogosort(myNumbers, n);

    printf("Ergebnis:\n");
    print_array(myNumbers, n);
    printf("\n");

    return 0;
}