// 读取签到时间
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char *substring(char *s, int start_idx, int end_idx) {
    char *s_new = (char *)malloc(sizeof(char) * (end_idx - start_idx + 1));
    for (int i = 0; i < end_idx - start_idx; i++) s_new[i] = s[i + start_idx];
    return s_new;
}

int get_time(char *s) {
    int idx = -1;
    for (int i = 0; i < strlen(s); i++) if (s[i] == ':') idx = i;
    char *hour = substring(s, 0, idx);
    char *minute = substring(s, idx + 1, strlen(s));
    int hour_ = atoi(hour);
    int minute_ = atoi(minute);
    return hour_ * 60 + minute_;
}

int isin(char **names, int len, char *name) {
    for (int i = 0; i < len; i++) if (strcmp(names[i], name) == 0) return i;
    return -1;
}

int argmax(int *arr, int len) {
    int max = arr[0];
    int ind = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
            ind = i;
        }
    }
    return ind;
}

int main() {
    FILE *fp = fopen("datas/2018/input2.txt", "r");
    char tmp[MAX];
    fgets(tmp, MAX, fp);
    int m = atoi(tmp);

    char *names[m];
    int intervals[m];
    int len = 0;
    char tmp1[MAX], tmp2[MAX], tmp3[MAX];
    for (int i = 0; i < m; i++) {
        fscanf(fp, "%s %s %s\n", tmp1, tmp2, tmp3);        
        int idx = isin(names, len, tmp1);
        int time_start = get_time(tmp2);
        int time_end = get_time(tmp3);
        while (time_end < time_start) time_end += 24 * 60;
        int interval = time_end - time_start; 
        if (idx == -1) {
            names[len] = (char *)malloc(sizeof(char) * (strlen(tmp1) + 1));
            strcpy(names[len], tmp1);
            intervals[len] = interval;
            ++len;
        } else {
            intervals[idx] += interval;
        }
    }
    fclose(fp);
    int ind = argmax(intervals, len);
    printf("%s\n", names[ind]);
}
