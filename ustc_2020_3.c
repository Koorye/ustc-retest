// 求最大组合数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int smaller_than(char *a, char *b) {
    char s1[MAX];
    char s2[MAX];
    strcpy(s1, a);
    strcpy(s2, b);
    strcat(s1, s2);
    strcat(s2, s1);
    // for (int i = 0; i < strlen(s1); i++) {
    //     if (s1[i] < s2[i]) return s1[i] < s2[i];
    //     if (s1[i] > s2[i]) return s1[i] > s2[i];
    // }
    // return 0;
    int a = atoi(s1);
    int b = atoi(s2);
    return a > b;
}

void swap(char **arr, int i, int j) {
    char tmp[MAX];
    strcpy(tmp, arr[i]);
    printf("tmp: %s\n", tmp);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], tmp);
}

void sort(char **arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (smaller_than(arr[i], arr[j]) == 1) swap(arr, i, j);
        }
    }
}

int main() {
    char *arr[MAX];
    FILE *fp = fopen("datas/2020/number.in", "r");
    int len = 0;
    char tmp[MAX];
    for (int i = 0; !feof(fp); i++) {
        fscanf(fp, "%s", &tmp);
        ++len;
        int len_str = strlen(tmp);
        arr[i] = (char *)malloc(sizeof(char) * (len_str + 1));
        strcpy(arr[i], tmp);
    }
    fclose(fp);
    sort(arr, len);
    for (int i = 0; i < len; i++) printf("%s", arr[i]);
    printf("\n");
}