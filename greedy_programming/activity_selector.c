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

void activity_selector_dynamic(int * starts, int *ends, int len) {
    int * start = malloc(sizeof(int) * len);
    int * end = malloc(sizeof(int) * len);
    int * length = malloc(sizeof(int) * len);
    int ** routes = malloc(sizeof(int) * len);
    int max = 1, max_idx = 0;
    for(int i = 0; i < len; i++) {
        start[i] = starts[i];
        end[i] = ends[i];
        routes[i] = malloc(sizeof(int) * len);
        length[i] = 1;
        routes[i][0] = i;
        for(int j = 0; j < i; j++) {
            if(end[j] <= start[i] && length[i] <= length[j] + 1) {
                length[i] = length[j] + 1;
                memcpy(routes[i], routes[j], sizeof(int) * length[j]);
                routes[i][length[j]] = i;
                if(length[i] > max){
                    max = length[i];
                    max_idx = i;
                }
            }
        }
    }
    for(int i = 0; i < max; i++) {
        printf("%d\t", routes[max_idx][i]);
    }
    free(start);
    free(end);
    free(length);
    for(int i = 0; i < len; i++) {
        free(routes[i]);
    }
    free(routes);
}

void test_activity_selector(){
    int starts[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int ends[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    activity_selector(starts, ends, 0, 11, 0);
    activity_selector_dynamic(starts, ends, 11);
}
