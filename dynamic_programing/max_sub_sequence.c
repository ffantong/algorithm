#include "../pub_include.h"

/*
´íÎó£¬²»¿ÉÐÐ
*/
void max_sub_sequence(int * array, int len){
    int ** temp = malloc(sizeof(int *) * len);
    for(int i = 0; i < len; i++) {
        temp[i] = malloc(sizeof(int) * (len + 1));
        memset(temp[i], 0, sizeof(int) * (len + 1));
    }
    int min = array[0], sub_array_count = 1;
    temp[0][0] = 1;
    temp[0][1] = min;
    for(int i = 1; i < len; i++) {
        if(array[i] >= min) {
            for(int j = 0; j < sub_array_count; j++) {
                if(temp[j][temp[j][0]] <= array[i]) {
                    temp[j][0] = temp[j][0] + 1;
                    temp[j][temp[j][0]] = array[i];
                }
            }
        }else {
            min = array[i];
            temp[sub_array_count][1] = min;
            temp[sub_array_count++][0] = 1;
        }
    }
    for(int i = 0; i < sub_array_count; i++) {
        printf("%d:", temp[i][0]);
        for(int j = 1; j <= temp[i][0]; j++){
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < len; i++) {
        free(temp[i]);
    }
    free(temp);
}

void test_max_sub_sequence(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    max_sub_sequence(array, len);
}
