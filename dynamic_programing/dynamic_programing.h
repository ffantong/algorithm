#ifndef DYNAMIC
#define DYNAMIC

int cut_rod(int);
void test_cut_rod();
int bottom_cut_rod(int);
int memoized_cut_rod_aux(int, int *);
int memoized_cut_rod(int);

int fib(int);
int fib_1(int, int *);
int fib_2(int, int *);
void test_fibonacci();


void lcs_length(char *, int, char *, int, int **);
void print_lcs(int **, char *, char *, int, int);
void bottom_print_lcs(char *, int, char *, int, int **);
void test_lcs_length();

void test_max_sub_sequence();
void max_sub_sequence(int *, int);
void max_sub_sequence_plus(int *, int);

float optimal_bst(float *, float *, int, int, int, int);
void test_optimal_bst();

#endif // DYNAMIC
