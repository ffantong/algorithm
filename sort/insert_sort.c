#include "../pub_include.h"

void insert_sort(int * array, int len) {
    int element;
    int j;
    for(int i = 1; i < len; i++) {
        element = array[i];
        for(j = i; j > 0; j--) {
            if(array[j - 1] > element) {
                array[j] = array[j - 1];
            }else{
                break;
            }
        }
        array[j] = element;
    }
}

void test_insert_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    insert_sort(array, len);
    PRINT_ARRAY(array, len);
}
