
#include <stdio.h>

void swap(float *a, float *b, size_t *switched)
{
    float temp = *a;
    *a = *b;
    *b = temp;

    (*switched)++;
}

void heapify(float *a, size_t length, size_t i, size_t *switched, size_t *checked)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    (*checked)++;

    if(left < length && a[left] > a[largest]){
        largest = left;
    }
    if(right < length && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&a[i], &a[largest], switched);

        heapify(a, length, largest, switched, checked);
    }

}
void heapsrt(float *a,  size_t length, size_t *switched, size_t *checked)
{
    for(int i = (int)length / 2 - 1; i >= 0; i--){
        heapify(a, length, i, switched, checked);
    }
    for(int i = (int)length - 1; i > 0; i--){
        swap(&a[i], &a[0], switched);
        heapify(a, i, 0, switched, checked);
    }
}