#include "pub_include.h"

int find_max_subarray(int * array, int* start, int* end){
    if(*start == *end) {
        return array[*end];
    }else {
        int mid = (*start + *end) / 2;
        int left_start = *start, left_end = mid;
        int max_left = find_max_subarray(array, &left_start, &left_end);
        int right_start = mid + 1, right_end = *end;
        int max_right = find_max_subarray(array, &right_start, &right_end);
        int sum = 0;
        int max_mid_right = -99999;
        int mid_start = mid, mid_end = mid + 1;
        for(int i = mid + 1; i < *end; i++) {
            sum += array[i];
            if(sum > max_mid_right) {
                max_mid_right = sum;
                mid_end = i;
            }
        }
        sum = 0;
        int max_mid_left = -99999;
        for(int i = mid; i >= *start; i--){
            sum += array[i];
            if(sum > max_mid_left) {
                max_mid_left = sum;
                mid_start = i;
            }else{
                break;
            }
        }
        int max_mid = max_mid_left + max_mid_right;
        if(max_left > max_right && max_left > max_mid) {
            printf("max(1): %d, left: %d, right: %d\n", max_left, left_start, left_end);
            *start = left_start;
            *end = left_end;
            return max_left;
        }else if(max_right > max_left && max_right > max_mid) {
            printf("max(2): %d, left: %d, right: %d\n", max_right, right_start, right_end);
            *start = right_start;
            *end = right_end;
            return max_right;
        }else{
            printf("max(3): %d, left: %d, right: %d\n", max_mid, mid_start, mid_end);
            *start = mid_start;
            *end = mid_end;
            return max_mid;
        }
    }
}

void test_find_max_subarray(){
    int array[] = ARRAY;
    int start = 0, end = sizeof(array) / sizeof(int) - 1;
    int max = find_max_subarray(array, &start, &end);
    printf("max(4): %d, left: %d, right: %d\n", max, start, end);
}
