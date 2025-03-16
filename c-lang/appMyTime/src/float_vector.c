#include "../includes/float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct float_vector {
    int capacity;
    int size;
    float *data;
};

bool _FloatVector_isFull(const FVector *vec) {
    return vec->size == vec-> capacity;
}