#ifndef SORT_PUB
#define SORT_PUB

void build_heap(int *, int);
void max_heapify(int *, int, int);
void heap_sort(int *, int);
void test_heap_sort();

void insert_sort(int *, int len);
void test_insert_sort();

void quick_sort(int *, int, int);
void test_quick_sort();

void counting_sort(int *, int);
void test_counting_sort();

void radix_sort(int *, int);
void test_radix_sort();

void shell_sort(int *array, int len);
void test_shell_sort();

#endif // SORT_PUB
