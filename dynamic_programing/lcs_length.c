#include "../pub_include.h"

void lcs_length(char * a, int a_len, char * b, int b_len, int ** res) {
    for(int i = 0; i < a_len; i++) {
        for(int j = 0; j < b_len; j ++){
            if(a[i] == b[j]) {
                if(i == 0 || j == 0) {
                    res[i][j] = 1;
                }else{
                    res[i][j] = res[i - 1][j - 1] + 1;
                }
            }else{
                int j_1 = (j == 0 ? 0 : res[i][j - 1]),
                    i_1 = (i == 0 ? 0 : res[i - 1][j]);
                if(j_1 > i_1) {
                    res[i][j] = j_1;
                }else {
                    res[i][j] = i_1;
                }

            }
        }
    }
}

void print_lcs(int ** res, char * a, char * b, int x, int y){
    if(x < 0 || y < 0) {
        return;
    }
    if(a[x] == b[y]) {
        print_lcs(res, a, b, x - 1, y - 1);
        printf("%c", a[x]);
    }else {
        int x_1 = (x == 0 ? 0 : res[x - 1][y]);
        if(res[x][y] == x_1) {
            print_lcs(res, a, b, x - 1, y);
        }else {
            print_lcs(res, a, b, x, y - 1);
        }
    }
}

void bottom_print_lcs(char * a, int a_len, char * b, int b_len, int ** res){
    int lcs[res[a_len - 1][b_len - 1]];
    int idx = 0;
    for(int i = a_len - 1, j = b_len - 1; i >= 0 && j >= 0;) {
        if(a[i] == b[j]) {
            lcs[idx++] = a[i];
            j--;
            i--;
        }else {
            int x_1 = (i == 0 ? 0 : res[i - 1][j]);
            if(res[i][j] == x_1) {
                i--;
            }else {
                j--;
            }
        }
    }
    if(idx > 0) {
        for(int i = idx - 1; i >= 0; i--) {
            printf("%c", lcs[i]);
        }
    }
}

void test_lcs_length(){
    char * a = "ABCBDAB";
    char * b = "BDCABA";
    int a_len = strlen(a);
    int b_len = strlen(b);
    int ** res;
    res = malloc(sizeof(int *) * a_len);
    for(int i = 0; i < a_len; i++){
        res[i] = malloc(sizeof(int) * b_len);
        memset(res[i], 0, sizeof(int) * b_len);
    }
    lcs_length(a, a_len, b, b_len, res);
    print_lcs(res, a, b, a_len - 1, b_len - 1);
    printf("\n");
    bottom_print_lcs(a, a_len, b, b_len, res);
    for(int i = 0; i < a_len; i++){
        free(res[i]);
    }
    free(res);
}
