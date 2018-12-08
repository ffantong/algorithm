#include "pub_include.h"
#include "tree/tree_pup.h"
int main()
{
    test_heap_sort();
    printf("\n");
    test_insert_sort();
    printf("\n");
    test_quick_sort();
    printf("\n");
    test_counting_sort();
    printf("\n");
    test_radix_sort();
    printf("\n");
    test_tree();
    return 0;
}
