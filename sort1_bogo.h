#ifndef BOGOSORT_H
#define BOGOSORT_H

#include <stddef.h>


int is_sorted(const int *a, size_t n);
void shuffle(int *a, size_t n);
void bogosort(int *a, size_t n);

#endif