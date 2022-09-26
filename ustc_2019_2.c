// 求一个数是否是两个2的任一幂之和
#include <stdio.h>
#include <math.h>

int main() {
    int num, num_saved;
    printf("input num: ");
    scanf("%d", &num);
    num_saved = num;

    int count = 0;
    int ind1 = -1, ind2 = -1;
    int ind = 0;
    while (num > 0) {
        int res = (num & 1);
        if (res == 1) {
            ++count;
            if (ind1 == -1) ind1 = ind; else ind2 = ind;
        }
        num >>= 1;
        ++ind;
    }
    if (count == 2) {
        printf("%d = 2^%d + 2^%d\n", num_saved, ind1, ind2);
    } else {
        printf("NO!\n");
    }
}