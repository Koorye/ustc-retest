// 求4个数是否能通过+, *组成24

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isin(int *arr, int len_arr, int e) {
    for (int i = 0; i < len_arr; i++) {
        if (e == *(arr + i)) return TRUE;
    }
    return FALSE;
}

int solve2(int a, int b) {
    if ((a + b == 24) || (a * b == 24)) {
        return TRUE;
    }
    return FALSE;
}

int solve3(int a, int b, int c) {
    int arr[3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int other = -1;
            int arr_selected[2] = {i, j};
            for (int k = 0; k < 3; k++) {
                if (isin(arr_selected, 2, k) == FALSE)
                    other = k;
            }

            int tmp = arr[i] + arr[j];
            if (solve2(tmp, arr[other]) == TRUE) {
                return TRUE;
            }
            tmp = arr[i] * arr[j];
            if (solve2(tmp, arr[other]) == TRUE) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

int solve4(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int arr_selected1[2] = {i, j};
            int other1 = -1;
            for (int k = 0; k < 4; k++) {
                if (isin(arr_selected1, 2, k) == FALSE) {
                    other1 = k;
                    break;
                }
            }
            int arr_selected2[3] = {i, j, other1};
            int other2 = -1;
            for (int k = 0; k < 4; k++) {
                if (isin(arr_selected2, 3, k) == FALSE) {
                    other2 = k;
                    break;
                }
            }

            int tmp = arr[i] + arr[j];
            if (solve3(tmp, arr[other1], arr[other2]) == TRUE) {
                return TRUE;
            }
            tmp = arr[i] * arr[j];
            if (solve3(tmp, arr[other1], arr[other2]) == TRUE) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

int main() {
    int a, b, c, d;
    printf("enter a, b, c, d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int res = solve4(a, b, c, d);
    if (res == TRUE) {
        printf("TRUE!\n");
    } else {
        printf("FALSE!\n");
    }
    return 0;
}