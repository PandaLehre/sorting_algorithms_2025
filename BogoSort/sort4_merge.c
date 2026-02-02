#include <stdlib.h>


void merge(float *array, size_t leftIndex, size_t middelIndex, size_t rightIndex, size_t *switched, size_t *checked)
{

    size_t size = rightIndex - leftIndex + 1;

    float *tmp = malloc(size * sizeof(tmp));
    if(!tmp) return;

    size_t i = leftIndex;
    size_t j = middelIndex + 1;
    size_t k = 0;


    while (i <= middelIndex && j <= rightIndex)
    {
        (*checked)++;

        if(array[i] <= array[j])
        {
            tmp[k++] = array[i++];
        }
        else
        {
            tmp[k++] = array[j++];
            (*switched)++;
        }
    while (i <= middelIndex) tmp[k++] = array[i++];
    while (j <= rightIndex) tmp[k++] = array[j++];

    for (size_t n = 0; n < size; n++)
    {
        array[leftIndex + n] = tmp[n];
    }

    free(tmp);

    }
}

void mergeSort(float *array, size_t leftIndex,size_t rightIndex, size_t *switched, size_t *checked)
{

    if (leftIndex >= rightIndex) return;

    size_t middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(array, leftIndex, middleIndex, switched, checked);

    mergeSort(array, middleIndex + 1, rightIndex, switched, checked);

    merge(array, leftIndex, middleIndex, rightIndex, switched, checked);


}