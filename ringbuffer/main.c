// e1371 奥村 嶺

#include <stdio.h>
#include <string.h>
#include <math.h>

#define QUEUE_MAX_PLUS_ONE 6

const int QUEUE_MAX = 5;

int returnDigit(int);

int toTail(int);

int returnDigit(int x){
    if(x < 0) return (int)log10((-1)*x) + 1 + 1; //数字の分と、-の分 +1
    else return (int)log10(x|1) + 1; // 0が入ってきた時のために1でor取る
}

int toTail(int x) {
    return (x + 1) % QUEUE_MAX_PLUS_ONE;
}

int main(void) {
    int queue[QUEUE_MAX_PLUS_ONE] = {0}, head = 0, tail = 0, check;
    while (1) {
        if (tail - head < 0) check = tail - head + 6;
        else check = tail - head;
        printf("操作を指定してください\n>>>");
        int val = 0;
        char in[2];
        scanf("%s", in);
        if (strcmp(&in[0], "i") == 0) {
            if (check == QUEUE_MAX) printf("キューが満杯です。データを挿入できませんでした。\n");
            else {
                printf("挿入するデータを入力してください。\n>>>");
                if (scanf("%d", &val) != 1) {
                    scanf("%*s");
                    printf("ERROR:数値以外が入力されたため、データを挿入できませんでした。\n\n");
                    continue;
                }
                queue[tail] = val;
                tail = toTail(tail);
                printf("%dを末尾に挿入しました\n", val);
            }
        } else if (strcmp(&in[0], "d") == 0) {
            if (check == 0) printf("キューが空です。データを削除できませんでした。\n");
            else {
                printf("先頭のデータ%dを削除しました。\n", queue[head]);
                queue[head] = 0;
                head = toTail(head);
            }
        } else if (strcmp(&in[0], "p") == 0) {
            if (check == 0) {
                printf("キューが空です\n\n");
                continue;
            }
            printf("キューの中身を表示します。\n");
            int lenMax = check - 1, q = head; //パイプの数が check-1個
            for (int i = 0; i < check; i++) {
                lenMax += returnDigit(queue[q]) + 2; //桁数に加えて, 前後の空白の分で +2個
                q = toTail(q);
            }
            printf("        "); for (int i = 0; i < lenMax; i++) printf("-"); printf("\n");
            printf("Head <- ");
            q = head;
            for (int i = 0; i < check; i++) {
                printf(" %d ", queue[q]);
                if (i != check - 1) printf("|");
                q = toTail(q);
            }
            printf(" <- Tail\n");
            printf("        "); for (int i = 0; i < lenMax; i++)printf("-"); printf("\n");
        } else if (strcmp(&in[0], "q") == 0) {
            printf("終了します。\n");
            break;
        } else {
            printf("i, d, p, qいずれかを入力してください\n");
        }
        printf("\n");
    }
    return 0;
}