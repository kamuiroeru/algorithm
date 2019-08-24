// e1371 奥村 嶺

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void downheap(int, int, int *);

int getheap(int, int *);

void upheap(int, int *);

void putheap(int, int, int *);

int returnDigit(int); // 要素（数字）の桁数を数える

void printArray_from1(int *, int, int); // 見やすい形式に出力する

void insert(int, int *); // ヒープに要素を挿入する

void downheap(int k, int r, int *h) {
    int i = 2 * k;
    int v = h[k];
    while (i <= r) {
        if (i < r && h[i] < h[i + 1]) i = i + 1;
        if (h[i] <= v) break;
        h[k] = h[i];
        k = i;
        i = 2 * k;
    }
    h[k] = v;
    return;
}

int getheap(int n, int *h) {
    if (n < 1) exit(1);
    int x = h[1];
    h[1] = h[n];
    n = n - 1;
    downheap(1, n, h);
    return x;
}

void upheap(int k, int *h) {
    int i = k / 2;
    int v = h[k];
    while (i >= 1) {
        if (h[i] >= v) break;
        h[k] = h[i];
        k = i;
        i = k / 2;
    }
    h[k] = v;
    return;
}

void putheap(int x, int n, int *h) {
    n = n + 1;
    h[n] = x;
    upheap(n, h);
    return;
}

void mkheap(int x, int *h) {
    for (int i = x; 2 <= i; i--) {
        upheap(i, h);
    }
    return;
}

int returnDigit(int x) {
    if (x < 0) return (int) log10((-1) * x) + 1 + 1; // 数字の分と、-の分 +1
    else return (int) log10(x | 1) + 1; // 0が入ってきた時のために1でor取る
}

void printArray_from1(int *h, int valCount, int length) {
    int lenMax = length - 1 - 1 + 2; // パイプの個数n-1個と、両端の壁の部分で +2
    for (int i = 1; i < length; i++) {
        if (i > valCount) lenMax += (int) fmax(1, returnDigit(i)) + 2; // N（文字列の長さ1）と、左右の空白の分で +2
        else lenMax += (int) fmax(returnDigit(h[i]), returnDigit(i)) + 2; // 数字の桁数と、左右の空白の分で +2
    }
    for (int i = 0; i < lenMax; i++) printf("-");
    printf("\n|");
    for (int i = 1; i < length; i++) {
        if (i <= valCount)
            for (int j = 0; j < (returnDigit(h[i]) - returnDigit(i)); j++)
                printf(" "); // 中身の数字の桁数に合わせる(比較する時の括弧は必須！！無いとバグる)
        printf(" %d ", i);
        if (i != length - 1) printf("|");
    }
    printf("|\n");
    for (int i = 0; i < lenMax; i++) printf("-");
    printf("\n|");
    for (int i = 1; i < length; i++) {
        if (i > valCount) {
            for (int j = 0; j < (returnDigit(i) - 1); j++)
                printf(" "); // 中身の数字の桁数に合わせる(比較する時の括弧は必須！！無いとバグる)
            printf(" N ");
        } else {
            for (int j = 0; j < (returnDigit(i) - returnDigit(h[i])); j++)
                printf(" "); // 中身の数字の桁数に合わせる(比較する時の括弧は必須！！無いとバグる)
            printf(" %d ", h[i]);
        }
        if (i != length - 1) printf("|");
    }
    printf("|\n");
    for (int i = 0; i < lenMax; i++) printf("-");
    printf("\n");
}

void insert(int valCount, int *tree) {
    int val = 0;
    printf("挿入するデータを入力してください。\n>>>");
    if (scanf("%d", &val) != 1) { // 数値じゃなかった時のエラー処理
        scanf("%*s");
        printf("ERROR:数値以外が入力されたため、データを挿入できませんでした。\n\n");
    } else {
        putheap(val, valCount, tree);
        printf("%dをヒープに挿入しました\n", val);
    }
}

int main(void) {
    int tree[11] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0};
    int treeLength = sizeof(tree) / sizeof(tree[0]);
    int valCount = 7;
    printf("初期状態\n");
    printArray_from1(tree, valCount, treeLength);
    mkheap(valCount + 1, tree); // treeをヒープにする。
    printf("ヒープを作りました。\n");
    while (1) {
        printf("操作を指定してください\n>>>");
        char in;
        scanf("%1s", &in);
        switch (in) {
            case 'i':
                if (valCount == 10) printf("ヒープが満杯です。データを挿入できませんでした。\n");
                else {
                    insert(valCount, tree);
                    valCount += 1;
                }
                break;
            case 'd':
                if (valCount == 0) printf("ヒープが空です。データを削除できませんでした。\n");
                else {
                    printf("先頭のデータ%dを削除しました。\n", getheap(valCount, tree));
                    valCount -= 1;
                }
                break;
            case 'p':
                printf("ヒープのデータ配列を表示します。\n");
                printArray_from1(tree, valCount, treeLength);
                break;
            case 'q':
                printf("終了します。\n");
                return 0;
            default:
                printf("i, d, p, qいずれかを入力してください\n");
        }
        printf("\n");
    }
}