#include "../pub_include.h"

void task_schedule(int * endtimes, int * punish, int len){
    int * results = malloc(sizeof(int) * len);
    int result_len = 0, temp;
    for(int i = 0; i < len; i++) {
        if(endtimes[i] <= result_len) {
            continue;
        }
        results[result_len++] = i;
        for(int j = 1; j < result_len; j++) {
            if(endtimes[results[j - 1]] > endtimes[results[j]]) {
                temp = results[j];
                results[j] = results[j - 1];
                results[j - 1] = temp;
            }
        }

    }
    for(int i = 0; i < result_len; i++) {
        printf("%d\t", results[i]);
    }
    printf("\n");
    free(results);
}
void test_task_schedule(){
    int endtimes[] = {4, 2, 4, 3, 1, 4, 6};
    int punishs[] = {70, 60, 50, 40, 30, 20, 10};
    task_schedule(endtimes, punishs, 7);
}
