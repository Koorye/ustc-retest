// 计算海明距离
// 最好通过位运算实现
#include <stdio.h>

void print_bin(int number) {
    int bit = sizeof(int) * 8;
    for(int i = bit - 1; i >= 0; i--){
        int bin = (number & (1 << i)) >> i;
        printf("%d", bin);
    }
    printf("\n");
}

int main() {
    int a, b;
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);
    int c = a ^ b;

    printf("a=");
    print_bin(a);
    printf("b=");
    print_bin(b);
    printf("c=");
    print_bin(c);

    int ans = 0;
    while (c > 0) {
        ans += (c & 1);
        c >>= 1;
    }
    printf("%d", ans);
    return 0;
}