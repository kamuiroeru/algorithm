// e1371 奥村 嶺
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct cell {
    int item;
    struct cell *next;
} cell_t;

int returnDigit(int);

cell_t *top = NULL;

cell_t *push(int, cell_t *);

cell_t *pop(cell_t *);

cell_t *lalloc(void);

int returnDigit(int x){
    if(x < 0) return (int)log10((-1)*x) + 1 + 1; //数字の分と、-の分 +1
    else return (int)log10(x|1) + 1; // 0が入ってきた時のために1でor取る
}

cell_t *push(int x, cell_t *top) {
    cell_t *p;
    p = lalloc();
    p->item = x;
    p->next = top;
    return (p);
}

cell_t *pop(cell_t *top) {
    int x;
    if (top != NULL) {
        cell_t *p = top;
        x = top->item;
        top = top->next;
        free(p);
        printf("データ%dを取り出しました。\n", x);
    } else {
        printf("スタックは空です。\n");
    }
    return (top);
}

cell_t *lalloc(void) {
    return ((cell_t *) malloc(sizeof(cell_t)));
}

int main(void) {
    printf("英小文字を入力してください。\n");
    while (1) {
        printf(">>>");
        int val = 0;
        char in[2];
        scanf("%s", in);
        if (strcmp(&in[0], "i") == 0) {
            printf("挿入するデータを入力してください。\n>>>");
            if (scanf("%d", &val) != 1) {
                scanf("%*s");
                printf("ERROR:数値以外が入力されたため、データを挿入できませんでした。\n\n");
                continue;
            }
            top = push(val, top);
            printf("%dを挿入しました\n", val);
        } else if (strcmp(&in[0], "d") == 0) {
            top = pop(top);
        } else if (strcmp(&in[0], "m") == 0) {
            printf("取り出すデータ個数を入力してください。\n>>>");
            scanf("%d", &val);
            for (int i = 0; i < val; i++) {
                top = pop(top);
            }
        } else if (strcmp(&in[0], "p") == 0) {
            cell_t *p = top;
            if (p == NULL) {
                printf("スタックは空です。\n\n");
                continue;
            }
            printf("スタックの中身を表示します。\n");
            int lenMax = 0;
            cell_t *q = p;
            while (q != NULL) {
                lenMax = (int) fmax(lenMax, returnDigit(q->item));
                q = q->next;
            }
            while (p != NULL) {
                printf("| ");
                for (int i = returnDigit(p->item); i < lenMax; i++) {
                    printf(" ");
                }
                printf("%d |\n", p->item);
                p = p->next;
            }
            for (int i = 0; i < lenMax + 4; i++) {
                printf("-");
            }
            printf("\n");
        } else if (strcmp(&in[0], "q") == 0) {
            printf("終了します。\n");
            break;
        } else {
            printf("i, d, m, p, qいずれかを入力してください\n");
        }
        printf("\n");
    }
    return 0;
}
