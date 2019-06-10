#include "../pub_include.h"

static void shell_sort_1(int *array, int len, int step) {
    int element;
    int k;
    for(int i = 0; i < len - step; i++) {
        for(int j = step + i; j < len; j += step) {
            element = array[j];
            for(k = j - step; k >= 0; k -= step) {
                if(element < array[k]) {
                    array[k + step] = array[k];
                }else {
                    break;
                }
            }
            array[k + step] = element;
        }
    }
}

void shell_sort(int *array, int len) {
    int step = len;
    do{
        step = step / 2;
        shell_sort_1(array, len, step);
    }while(step > 1);
}

void test_shell_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    shell_sort(array, len);
    PRINT_ARRAY(array, len);
}
