// 求7进制
#include <stdio.h>

int main() {
    int num;
    printf("enter num: ");
    scanf("%d", &num);
    int res = 0;
    int level = 1;
    while (num > 0) {
        res += level * (num % 7);
        num /= 7;
        level *= 10;
    }
    printf("%d\n", res);
}