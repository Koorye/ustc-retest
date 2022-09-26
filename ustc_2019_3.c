// 计算前缀表达式
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int isdigit_all(char *s) {
    for (int i = 0; i < strlen(s); i++) if (!isdigit(s[i])) return 0;
    return 1;
}

void stack_push(int *stack, int *len, int val) {
    stack[*len] = val;
    ++(*len);
    printf("after push: ");
    for (int i = 0; i < *len; i++) printf("%d, ", stack[i]);
    printf("\n");
}

int stack_pop(int *stack, int *len) {
    int val = stack[*len - 1];
    --(*len);
    printf("after pull: ");
    for (int i = 0; i < *len; i++) printf("%d, ", stack[i]);
    printf("\n");
    return val;
}

int main() {
    FILE *fp = fopen("datas/2019/pre.in", "r");


    char *s[MAX], tmp[MAX];
    int len_s = 0;
    for (int i = 0; !feof(fp); i++) {
        fscanf(fp, "%s", tmp);
        s[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(s[i], tmp);
        ++len_s;
    }

    int stack[MAX];
    int len_stack = 0;
    for (int i = len_s - 1; i >= 0; i--) {
        if (isdigit_all(s[i])) {
            int val = atoi(s[i]);
            stack_push(stack, &len_stack, val);
        } else {
            int a = stack_pop(stack, &len_stack);
            int b = stack_pop(stack, &len_stack);

            int c = -1;
            char *p = s[i];
            if (p[0] == '+') {
                c = a + b;
            } else if (p[0] == '-') {
                c = a - b;
            } else if (p[0] == '*') {
                c = a * b;
            } else if (p[0] == '/') {
                c = a / b;
            }
            stack_push(stack, &len_stack, c);
        }
    }
    int res = stack_pop(stack, &len_stack);
    printf("%d\n", res);
    return 0;
}