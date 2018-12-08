#include "../pub_include.h"

#define LEFT(x) 2*x+1;//获得左节点在数组中的下标
#define RIGHT(x) 2*(x+1);//获得右节点在数组中的下标

void max_heapify(int * array, int len, int idx) {
    int ele = array[idx];
    int max_idx = idx;
    int max = ele;
    int idx_tmp = LEFT(idx);
    if(idx_tmp < len && array[idx_tmp] > max) {
        max_idx = idx_tmp;
        max = array[idx_tmp];
    }
    idx_tmp = RIGHT(idx);
    if(idx_tmp < len && array[idx_tmp] > max) {
        max_idx = idx_tmp;
        max = array[idx_tmp];
    }
    if(max_idx != idx) {
        array[idx] = max;
        array[max_idx] = ele;
        max_heapify(array, len, max_idx);
    }
}

void build_heap(int * array, int len){
    for(int i = len/2; i >= 0; i--){
        max_heapify(array, len, i);
    }
}

void heap_sort(int * array, int len){
    build_heap(array, len);
    int tmp, tmp_len;
    for(int i = 0; i < len; i++) {
        tmp = array[0];
        tmp_len = len - i - 1;
        array[0] = array[tmp_len];
        array[tmp_len] = tmp;
        max_heapify(array, tmp_len, 0);
    }
}

void test_heap_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    heap_sort(array, len);
    PRINT_ARRAY(array, len);
}
