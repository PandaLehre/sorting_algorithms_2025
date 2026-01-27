#ifndef BOGOSORT_H
#define BOGOSORT_H

#include <stddef.h>


int is_sorted(const float *a, size_t n);
void shuffle(float *a, size_t n);
void bogosort(float *a, size_t n);

#endif