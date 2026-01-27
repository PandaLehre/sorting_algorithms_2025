#ifndef SORT1_BOGO_H
#define SORT1_BOGO_H

#include <stddef.h>


int is_sorted(const float *a, size_t n, size_t *checked);
void FisherYatesShuffle(float *a, size_t n, size_t *switched);
void bogosort(float *a, size_t n, size_t *switched, size_t *checked);

#endif