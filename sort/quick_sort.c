#include "../pub_include.h"

void quick_sort(int *array, int start, int end){
    if(end - start <= 1) {
        return;
    }
    int tag = array[start];
    int sub = start;
    for(int i = start + 1; i < end; i++) {
        if(array[i] < tag) {
            array[sub++] = array[i];
            array[i] = array[sub];
        }
    }
    array[sub] = tag;
    quick_sort(array, start, sub);
    quick_sort(array, sub + 1, end);
}

void test_quick_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    quick_sort(array, 0, len);
    PRINT_ARRAY(array, len);
}
