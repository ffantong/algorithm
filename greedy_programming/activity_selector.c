#include "../pub_include.h"

void activity_selector(int * starts, int *ends, int start, int end, int cur) {
    for(int i = start; i < end; i++) {
        if(starts[i] >= cur) {
            printf("%d\t", i);
            cur = ends[i];
        }
    }
    printf("\n");
}

void test_activity_selector(){
    int starts[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int ends[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    activity_selector(starts, ends, 0, 11, 0);
}
