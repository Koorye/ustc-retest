// 求sum_k=1^n 1/k!
// 注意阶乘溢出，使用 1/k! = 1/(k-1)! * 1/k 计算

#include <stdio.h>

int main() {
    int n;
    printf("input n: ");
    scanf("%d", &n);
    double sum = 0, fac = 1.0;
    for (int i = 1; i <= n; i++) {
        fac /= i;
        printf("i=%d, fac=%f\n", i, fac);
        sum += fac;
    }
    printf("%.4f\n", sum);
    return 0;
}