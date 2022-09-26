// 求无序数组中第k大的数
#include <stdio.h>
#define MAX 32767

int max_ind(int *arr, int len) {
    int max = -MAX, max_ind = -1;
    for (int i = 0; i < len; i++) {
        int e = *(arr + i);
        if (e > max) {
            max = e;
            max_ind = i;
        }
    }
    return max_ind;
}

int main() {
    int n, k;
    printf("input n, k: ");
    scanf("%d %d", &n, &k);
    int arr[n];
    printf("input arr: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int ind = -1;
    for (int i = 0; i < k; i++) {
        ind = max_ind(arr, n);
        if (i != k - 1) arr[ind] = -MAX;
    }
    int max = arr[ind];
    printf("%d\n", max);
}