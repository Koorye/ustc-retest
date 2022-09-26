// 求最大公约数
#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int a, b;
    printf("enter a, b: ");
    scanf("%d %d", &a, &b);
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            printf("%d\n", i);
            return 0;
        } 
    }
    printf("NOT FOUND!\n");
    return 0;
}