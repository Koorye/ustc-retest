// 处理字符串
#include <stdio.h>
#define MAX 100

int main() {
    FILE *fp = fopen("datas/2017/input1.txt", "r");

    char tmp[100];
    for (int i = 0; !feof(fp); ++i) {
        fscanf(fp, "%s", tmp);
        if (tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] += 'A' - 'a';
        printf("%s ", tmp);
    }
    printf("\n");
}