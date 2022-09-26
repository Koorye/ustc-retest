// 转换16进制
#include <stdio.h>
#define MAX 100

int main() {
    char hexs[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int num;
    char s[MAX];
    int len_s;
    printf("input num: ");
    scanf("%d", &num);
    while (num > 0) {
        int hex = num % 16;
        num /= 16;
        s[len_s++] = hexs[hex];
    }
    for (int i = len_s - 1; i >= 0; --i) printf("%c", s[i]);
    printf("\n");
}