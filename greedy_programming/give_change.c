#include "../pub_include.h"

void greddy_give_change(int * changes, int money, int len){
    int rest = money;
    for(int i = 0; i < len; i++) {
        while(rest >= changes[i]) {
            printf("%d\t", changes[i]);
            rest = rest - changes[i];
        }
        if(rest == 0) {
            break;
        }
    }
    printf("\n");
}


void dynamic_give_changes(int * changes, int money, int len){
    int * min_changes = malloc(sizeof(int) * money);
    int ** min_changes_money = malloc(sizeof(int *) * money);
    for(int i = 0; i < money; i++) {
        min_changes[i] = i + 1;
        min_changes_money[i] = malloc(sizeof(int) * money);
        for(int k = 0; k <= i; k++) {
            min_changes_money[i][k] = 1;
        }
        for(int j = 0; j < len; j++) {
            if((i + 1) == changes[j]) {
                min_changes[i] = 1;
                min_changes_money[i][0] = changes[j];
                break;
            }
            if(changes[j] <= i && min_changes[i - changes[j]] + 1 < min_changes[i]) {
                min_changes[i] = min_changes[i - changes[j]] + 1;
                memcpy(min_changes_money[i], min_changes_money[i - changes[j]], sizeof(int) * min_changes[i - changes[j]]);
                min_changes_money[i][min_changes[i - changes[j]]] = changes[j];
            }
        }
    }
    for(int i = 0; i < min_changes[money - 1]; i++) {
        printf("%d\t", min_changes_money[money - 1][i]);
    }
    printf("\n");
    free(min_changes);
    for(int i = 0; i < money; i++) {
        free(min_changes_money[i]);
    }
    free(min_changes_money);
}

void test_give_change(){
    int changes[] = {10, 7, 5, 1};
    greddy_give_change(changes, 12, 4);
    dynamic_give_changes(changes, 12, 4);
}
