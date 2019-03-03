#include "../pub_include.h"


float optimal_bst(float * p, float * q, int start, int end, int root, int depth) {
    float best_left, best_right;
    float temp;
    if(start == end - 1 && start == root) {
        return p[root] * (depth) + (q[root - 1] + q[root]) * (depth + 1);
    }
    if(start == root) {
        best_left = p[root] * (depth) + q[root - 1] * (depth + 1);
    }else {
        best_left = optimal_bst(p, q, start, root, start, depth + 1);
        for(int i = start + 1; i < root; i++) {
            temp = optimal_bst(p, q, start, root, i, depth + 1);
            if(best_left > temp) {
                best_left = temp;
            }
        }
    }
    if(end == (root + 1)) {
        best_right = p[root] * (depth) + q[root] * (depth + 1);
    }else {
        best_right = optimal_bst(p, q, root + 1, end, root + 1, depth + 1);
        for(int i = root + 2; i < end; i++) {
            temp = optimal_bst(p, q, root + 1, end, i, depth + 1);
            if(best_right > temp) {
                best_right = temp;
            }
        }
    }
    printf("%f, %f, %d, %d, %d, %d\n", best_left, best_right, start, end, root, depth);
    return p[root] * (depth + 1) + best_left + best_right;
}

void test_optimal_bst() {
    float p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    float q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    float best = optimal_bst(p, q, 1, 6, 3, 0);
    printf("best: %f", best);
}
