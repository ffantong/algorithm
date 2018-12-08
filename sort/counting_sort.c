#include "../pub_include.h"

void counting_sort(int *array, int len) {
    int max = array[0], min = array[0];
    for(int i = 1; i < len; i++) {
        if(array[i] > max) {
            max = array[i];
        }
        if(array[i] < min) {
            min = array[i];
        }
    }
    int tmp[max - min];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < len; i++) {
        tmp[array[i] - min]++;
    }
    int index = 0;
    for(int i = 0; i <= max - min; i++) {
        if(tmp[i] > 0) {
            for(int j = 0; j < tmp[i]; j++) {
                array[index++] = i + min;
            }
        }
    }
}

void test_counting_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    counting_sort(array, len);
    PRINT_ARRAY(array, len);
}
