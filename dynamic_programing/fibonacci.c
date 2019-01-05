#include "../pub_include.h"

int fib(int n){
    if(n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib_1(int n, int * res){
    if(n <= 2) {
        res[n - 1] = 1;
        return 1;
    }
    int n_1 = res[n - 2];
    int n_2 = res[n - 3];
    if(n_1 == 0) {
        n_1 = fib_1(n - 1, res);
        res[n - 2] = n_1;
    }
    if(n_2 == 0) {
        n_2 = fib_1(n - 2, res);
        res[n - 3] = n_2;
    }
    res[n - 1] = n_1 + n_2;
    return res[n - 1];
}

int fib_2(int n, int * arr) {
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 3; i <= n; i++) {
        arr[i - 1] = arr[i - 2] + arr[i - 3];
    }
    return arr[n - 1];
}

void test_fibonacci(){
    int n = 10;
    printf("n = %d, fibonacci = %d\n", n, fib(n));
    int arr[n];
    memset(arr, 0, sizeof(int) * n);
    printf("n = %d, fibonacci = %d\n", n, fib_1(n, arr));
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    memset(arr, 0, sizeof(int) * n);
    printf("n = %d, fibonacci = %d\n", n, fib_2(n, arr));
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}
