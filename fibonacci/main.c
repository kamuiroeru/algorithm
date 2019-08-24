// e1371 奥村 嶺

#include <stdio.h>
#include <stdlib.h>

int fib2(int);

int fib2(int n) {
    int i = 1, j = 0;
    for (int k = 0; k < n; k++) {
        j = j + i;
        i = j - i;
    }
    return j;
}

int main(int argc, char *argv[]) {
    if (argc <2){
        printf("引数がありません。\n");
        exit(1);
    }
    printf("%d\n", fib2(atoi(argv[1])));
    return 0;
}