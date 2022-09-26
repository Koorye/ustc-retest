// 求集合的所有划分
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int max_(int *arr, int len) {
    int a = -32767;
    for (int i = 0; i < len; i++) if (arr[i] > a) a = arr[i];
    return a;
}

void print_sep(char **s, int *sep_idxs, int len) {
    int max_sep_idx = max_(sep_idxs, len);
    for (int i = 0; i <= max_sep_idx; i++) {
        printf("{");
        for (int j = 0; j < len; j++) if (sep_idxs[j] == i) printf("%s, ", s[j]);
        printf("}");
    }
    printf("\n");
}

void sep(char **s, int *sep_idxs, int len, int cur_idx) {
    if (cur_idx == len) {
        print_sep(s, sep_idxs, len);
        return;
    }
    int sep_idxs_copy[len];
    for (int i = 0; i < len; i++) sep_idxs_copy[i] = sep_idxs[i];
    char *s_ = s[cur_idx];
    int cur_sep_idx = max_(sep_idxs_copy, len) + 1;

    if (cur_sep_idx == 0) {
        sep_idxs_copy[cur_idx] = cur_sep_idx;
        sep(s, sep_idxs_copy, len, cur_idx + 1);
    } else {
        for (int i = 0; i <= cur_sep_idx; i++) {
            sep_idxs_copy[cur_idx] = i;
            sep(s, sep_idxs_copy, len, cur_idx + 1);
        }
    }
}

int main() {
    char *s[MAX];
    int len_s = 0;
    FILE *fp = fopen("datas/2019/set.in", "r");
    char tmp[MAX];
    for (int i = 0; !feof(fp); i++) {
        fscanf(fp, "%s", tmp);
        s[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(s[i], tmp);
        ++len_s;
    }
    fclose(fp);
    int sep_idxs[len_s];
    memset(sep_idxs, -1, sizeof(sep_idxs));
    sep(s, sep_idxs, len_s, 0);
}