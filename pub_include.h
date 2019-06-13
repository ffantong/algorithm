#ifndef PUB_INC
#define PUB_INC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "tree/tree_pup.h"
#include "sort/sort_pub.h"
#include "dynamic_programing/dynamic_programing.h"
#include "greedy_programming/greddy_programming.h"
#include "graph/graph.h"

#define PRINT_ARRAY(array, len)         \
    for(int i = 0; i < len; i++) {      \
        printf("%d\t", array[i]);       \
    }
#define ARRAY_LEN(array) sizeof(array) / sizeof(int);

#define ARRAY {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}

int find_max_subarray(int* , int*, int*);
void test_find_max_subarray();

#endif
