#include "../pub_include.h"

struct entity {
    int num;
    struct entity *next;
    struct entity *last;
};

void radix_sort(int *array, int len) {
    struct entity ** cur,** before = NULL;
    int next_bit, current_bit;
    int bucket;
    struct entity *p, *q;
    int max = array[0], min = array[0];
    for(int i = 1; i < len; i ++) {
        if(array[i] > max) {
            max = array[i];
        }
        if(array[i] < min) {
            min = array[i];
        }
    }
    int bit = 0;
    for(int i = 0; i < 10; i++) {
        if((max / (int)pow(10, i)) == 0){
            break;
        }
        bit++;
    }
    for(int i = 0; i < bit; i++) {
        next_bit = pow(10, i + 1);
        current_bit = pow(10, i);
        cur = malloc(sizeof(struct entity *) * 10);
        for(int k = 0; k < 10; k++) {
            cur[k] = NULL;
        }
        if(before == NULL) {
            for(int j = 0; j < len; j++) {
                bucket = (array[j] - min) % next_bit / current_bit;
                if(cur[bucket] == NULL) {
                    cur[bucket] = malloc(sizeof(struct entity));
                    cur[bucket]->num = (array[j] - min);
                    cur[bucket]->next = NULL;
                }else{
                    p = malloc(sizeof(struct entity));
                    p->num = (array[j] - min);
                    p->next = cur[bucket];
                    cur[bucket] = p;
                }
            }
        }else{
            for(int j = 0; j < 10; j++) {
                p = before[j];
                while(p != NULL) {
                    bucket = p->num % next_bit / current_bit;
                    if(cur[bucket] == NULL) {
                        cur[bucket] = p;
                        q = p->next;
                        cur[bucket]->next = NULL;
                        cur[bucket]->last = p;
                    }else{
                        cur[bucket]->last->next = p;
                        cur[bucket]->last = p;
                        q = p->next;
                        p->next = NULL;
                    }
                    p = q;
                }
            }
        }
        if(before != NULL) {
            free(before);
        }
        before = cur;
    }
    if(cur != NULL) {
        int index = 0;
        for(int j = 0; j < 10; j++) {
            p = cur[j];
            while(p != NULL) {
                array[index++] = p->num + min;
                q = p->next;
                free(p);
                p = q;
            }
        }
        free(cur);
    }
}

void test_radix_sort(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    radix_sort(array, len);
    PRINT_ARRAY(array, len);
}
