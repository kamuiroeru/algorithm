//e1371 奥村嶺

#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int seed, n = N;

void init(int *A) {
    int i;
    srand((unsigned int) seed);

    for (i = 1; i <= N; i++) A[i] = rand();

}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void shift(int *A, int i, int m) {
    int k = i, j;
    do {
        j = k;
        if (2 * j <= m && A[2 * j] > A[k]) k = 2 * j;
        if (2 * j + 1 <= m && A[2 * j + 1] > A[k]) k = 2 * j + 1;
        swap(&A[j], &A[k]);
    } while (j != k);
}

void make_heap(int *A, int m) {
    for (int i = m / 2; i > 1; i--) shift(A, i, m);
}

void heapSort(int *A) {
    make_heap(A, n+1);
    for (int i = n+1; i > 1; i--) {
        swap(&A[1], &A[i]);
        shift(A, 1, i - 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("引数がありません。\n");
        exit(1);
    }
    int A[1000001] = {};
    int B[1000001] = {};
    seed = atoi(argv[1]);
    init(A);
    init(B);
    heapSort(A);
    printf("%d\n\n", A[500000]);
    for (int i = 1; i < 1000001; i++) {
        printf("%7d : %10d : %10d\n", i, A[i], B[i]);
    }
    for (int i = 1; i < N; i++) {
        if(A[i] > A[i+1]){
            printf("SortResultError: @[%d]: %d > %d\n", i, A[i], A[i+1]);
        }
    }
    return 0;
}