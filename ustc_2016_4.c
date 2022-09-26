// 已知前序和后序，求一种中序
#include <stdio.h>
#define TRUE 1
#define FALSE 0 

int isin(char *arr, int len, char e) {
    for (int i = 0; i < len; ++i) if (e == arr[i]) return TRUE;
    return FALSE;
}

int same_set(char *s1, char *s2, int len) {
    for (int i = 0; i < len; ++i) if (isin(s1, len, s2[i]) == FALSE) return FALSE;
    return TRUE;
}

void solve(char *front, char *back, int len) {
    char root = front[0];
    if (len == 1) {
        printf("%c ", root);
        return;
    }
    if (len == 2) {
        printf("%c %c ", front[1], root);
        return;
    }

    for (int i = 2; i < len; ++i) {
        char *subtree_front_l = &front[1];
        char *subtree_back_l = &back[0];
        int len_subtree_l = i - 1;
        char *subtree_front_r = &front[i];
        char *subtree_back_r = &back[i - 1];
        int len_subtree_r = len - i + 1;
        if (same_set(subtree_front_l, subtree_back_l, len_subtree_l)) {
            solve(subtree_front_l, subtree_back_l, len_subtree_l);
            printf("%c ", root);
            solve(subtree_front_r, subtree_back_r, len_subtree_r);
            break;
        }
    }
}

int main() {
    int n;
    FILE *fp = fopen("datas/2016/4.in", "r");
    fscanf(fp, "%d\n", &n);
    char tree_front[n], tree_back[n];
    for (int i = 0; i < n; ++i) fscanf(fp, "%c ", &tree_front[i]);
    for (int i = 0; i < n; ++i) fscanf(fp, "%c ", &tree_back[i]);
    solve(tree_front, tree_back, n);
}