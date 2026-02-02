#include <stdio.h>

void insertionSort(int * array, int length){
    for (int i = 1; i < length; i++)
    {
        int cur = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > cur){
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = cur;
    }
}

int main(){
    int length = 11;
    int array [] = {10, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1};
    insertionSort(array, length);
    for(int i = 0; i < length; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}