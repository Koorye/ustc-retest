// 
#include <stdio.h>
#include <stdlib.h>

int get_max(int *arr, int len) {
    int max = *arr;
    int ind = 0;
    for (int i = 1; i < len; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
            ind = i;
        }
    }
    *(arr + ind) = -32767;
    return max;
}

int main() {
    FILE *fp = fopen("datas/2018/input3.txt", "r");
    int m, n;
    int arr[n];
    fscanf(fp, "%d %d", &m, &n);
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);

    int maxs[100];
    int len = 0;
    int max;
    while (1) {
        max = get_max(arr, n);
        if (max < 0) break;
        while (m >= max) {
            m -= max;
            maxs[len] = max;
            ++len;
        }
    }
    if (m == 0) {
        for (int i = 0; i < len; i++) printf("%d, ", maxs[i]);
        printf("\n");
    } else {
        printf("NO!\n");
    }
}