// 求最长等差子序列
#include <stdio.h>
#define MAX 100

int solve(int **mat, int len, int y, int diff, int layer) {
    int *arr = mat[y];
    int count = 0;
    for (int i = 0; i < len; ++i) if (arr[i] == diff) ++count;
    if (count == 0) return layer;

    int layer_max = 0;
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == diff) tmp = solve(mat, len, i, diff, layer + 1);
        if (tmp > layer_max) layer_max = tmp;
    }
    return layer_max;
}

int main() {
    int arr[MAX];
    int len_arr = 0;
    FILE *fp = fopen("datas/2017/input3.txt", "r");
    for (;!feof(fp); ++len_arr) fscanf(fp, "%d", &arr[len_arr]);
    fclose(fp);

    int mat[len_arr][len_arr];
    for (int row = 0; row < len_arr; ++row) for (int col = 0; col < len_arr; ++col) mat[row][col] = arr[row] - arr[col];

    int *p[len_arr];
    for (int row = 0; row < len_arr; ++row) p[row] = mat[row];
    int layer;
    for (int row = 0; row < len_arr; ++row) for (int col = 0; col < row; ++col) layer = solve(p, len_arr, row, mat[row][col], 1);
    printf("%d\n", layer);
}