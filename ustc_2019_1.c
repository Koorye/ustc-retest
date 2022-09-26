// 验证身份证有效
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[18];
    printf("input id code: ");
    scanf("%s", s);
    int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 
                       9, 10, 5, 8, 4, 2};
    char M[11] = {'1', '0', 'X', '9', '8', '7', 
                  '6', '5', '4', '3', '2'};
    int sum = 0;
    for (int i = 0; i < 17; i++) {
        int weight = weights[i];
        char tmp[2];
        tmp[0] = s[i];
        tmp[1] = '\0';
        int num = atoi(tmp);
        sum += weight * num;
    }
    int z = sum % 11;
    if (M[z] == s[17]) {
        printf("YES!\n");
    } else {
        printf("NO!\n");
    }
}