#include "../pub_include.h"

int rod_price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int cut_rod(int length) {
    if(length <= 0) {
        return 0;
    }
    if(length == 1) {
        return rod_price[0];
    }
    int max_price = 0, price;
    for(int i = 1; i <= length; i++) {
        price = rod_price[i - 1] + cut_rod(length - i);
        if(price > max_price) {
            max_price = price;
        }
    }
    return max_price;
}

int memoized_cut_rod(int length){
    int max_prices[length];
    memset(max_prices, 0, sizeof(int) * length);
    return memoized_cut_rod_aux(length, max_prices);
}

int memoized_cut_rod_aux(int length, int * max_prices) {
    if(max_prices[length - 1] != 0) {
        return max_prices[length - 1];
    }
    int max_price = 0, price;
    for(int i = 1; i <= length; i++) {
        price = rod_price[i - 1] + memoized_cut_rod_aux(length - i, max_prices);
        if(price > max_price) {
            max_price = price;
        }
    }
    max_prices[length - 1] = max_price;
    return max_price;
}

int bottom_cut_rod(int length) {
    int max_prices[length];
    memset(max_prices, 0, sizeof(int) * length);
    int price;
    for(int i = 1; i <= length; i++) {
        max_prices[i - 1] = rod_price[i - 1];
        for(int j = 1; j < i; j++) {
            price = max_prices[j - 1] + max_prices[i - j - 1];
            if(price > max_prices[i - 1]) {
                max_prices[i - 1] = price;
            }
        }
    }
    return max_prices[length - 1];
}

void test_cut_rod() {
    int length = 5;
    printf("length: %d, max price is: %d\n", length, cut_rod(length));
    printf("length: %d, max price is: %d\n", length, memoized_cut_rod(length));
    printf("length: %d, max price is: %d\n", length, bottom_cut_rod(length));
}
