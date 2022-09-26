// 求完数和盈数
#include <stdio.h>
#include <math.h>

void solve(int a) {
    int sum = 0;
    for (int i = 1; i < a; i++) if (a % i == 0) sum += i;
    if (sum == a) printf("%d is wan shu\n", a);
    else if (sum > a) printf("%d is ying shu\n", a);
}

int main() {
    for (int i = 2; i <= 1000; i++) {
        solve(i);
    }
}