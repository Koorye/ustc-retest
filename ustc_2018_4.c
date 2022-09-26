// 求最长公共子序列
#include <stdio.h>
#include <string.h>
#define MAX 100

int count(int **mat, int row, int col, int x, int y) {
    int arr[MAX];
    int len = 0;
    while (y < row && x < col) arr[len++] = mat[y++][x++];
    int max = 0, num = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 1) {
            ++num;
        } else {
            max = num > max ? num : max;
            num = 0;
        }
    }
    return max;
}

void public_substring(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int mat[len1][len2];
    for (int row = 0; row < len1; row++) {
        for (int col = 0; col < len2; col++) {
            mat[row][col] = s1[row] == s2[col] ? 1 : 0;
        }
    }
    int *p[len2];
    for (int row = 0; row < len1; row++) p[row] = mat[row];
    int max = 0;
    for (int x = 0; x < len2; x++) {
        int max_ = count(p, len1, len2, x, 0);
        max = max_ > max ? max_ : max;
    }
    printf("%d\n", max);
}

int main() {
    FILE *fp = fopen("datas/2018/input4.txt", "r");
    char tmp1[MAX], tmp2[MAX]; 
    for (int i = 0; !feof(fp); i++) {
        fscanf(fp, "%s %s\n", tmp1, tmp2);
        public_substring(tmp1, tmp2);
    }
    fclose(fp);
}
