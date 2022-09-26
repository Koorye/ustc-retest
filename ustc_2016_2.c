// 微信红包分配
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isin(int *arr, int len, int e) {
    for (int i = 0; i < len; ++i) if (e == arr[i]) return 1;
    return -1;
}

int cmp(const void *a, const void *b) {
    int a_ = *(int*)a;
    int b_ = *(int*)b;
    if (a_ < b_) {
        return -1;
    } else if (a_ > b_) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int x, n;
    do {
        float x_tmp;
        printf("input x, n: ");
        scanf("%f %d", &x_tmp, &n);
        x = (int) (x_tmp * 100);
    } while (n > x);

    srand(time(NULL));
    
    int s[n + 1];
    s[0] = 0;
    s[n] = x;
    int idx = 1;
    while (idx < n) {
        int a;
        do {
            a = rand() % x;
        } while (isin(s, idx, a) == 1 || a == 0);
        s[idx++] = a;
    }
    qsort(s, n + 1, sizeof(s[0]), cmp);
    for (int i = 0; i < n; ++i) printf("%d.%d ", (s[i + 1] - s[i]) / 100, (s[i + 1] - s[i]) % 100);
    printf("\n");
}