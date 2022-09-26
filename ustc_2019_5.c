// 求二叉树层次遍历序列的最大直径(一个叶子节点到另一个叶子节点的最大距离)
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int tree[MAX], l[MAX], sl[MAX], ln[MAX], sln[MAX];

int down(int id, int len_tree) {
    if (id > len_tree) return 0;
    int id_l = id * 2;
    int id_r = id * 2 + 1;
    int len_l = down(id_l, len_tree);
    int len_r = down(id_r, len_tree);
    if (len_l > len_r) {
        l[id] = len_l + tree[id];
        sl[id] = len_r + tree[id];
        ln[id] = id_l;
        sln[id] = id_r;
        return len_l + tree[id];
    } else {
        l[id] = len_r + tree[id];
        sl[id] = len_l + tree[id];
        ln[id] = id_r;
        sln[id] = id_l;
        return len_r + tree[id];
    }
}

void up(int id, int parent_id, int len_tree) {
    if (id > len_tree) return;
    if (parent_id > 0) {
        if (ln[parent_id] == id) {
            if (sl[parent_id] > l[id]) { 
                sl[id] = l[id];
                sln[id] = ln[id];
                l[id] = sl[parent_id];
                ln[id] = parent_id;
            } else if (sl[parent_id] > sl[id]) {
                sl[id] = sl[parent_id];
                sln[id] = parent_id;
            }
        } else {
            if (l[parent_id] > l[id]) {
                sl[id] = l[id];
                sln[id] = ln[id];
                l[id] = l[parent_id];
                ln[id] = parent_id;
            } else if (l[parent_id] > sl[id]) {
                sl[id] = l[parent_id];
                sln[id] = parent_id;
            }
        }
    }
    int id_l = id * 2;
    int id_r = id * 2 + 1;
    up(id_l, id, len_tree);
    up(id_r, id, len_tree);
}

int max_(int a, int b) {
    return a > b ? a : b;
}

void print(int len_s) {
    printf("tree: ");
    for (int j = 1; j <= len_s; ++j) printf("%d, ", tree[j]);
    printf("\nl:");
    for (int j = 1; j <= len_s; ++j) printf("%d, ", l[j]);
    printf("\nln:");
    for (int j = 1; j <= len_s; ++j) printf("%d, ", ln[j]);
    printf("\n----------------------------------------\n");
}

int main() {
    int len_s = 0;
    FILE *fp = fopen("datas/2019/expr.in", "r");
    char tmp[MAX];
    for (int i = 1; !feof(fp); i++) {
        fscanf(fp, "%s", tmp);
        tree[i] = atoi(tmp);
        ++len_s;
    }
    fclose(fp);
    print(len_s);

    down(1, len_s);
    print(len_s);
    up(1, -1, len_s);
    print(len_s);

    int res = 0;
    for (int j = 1; j <= len_s; ++j) res = max_(res, l[j] + sl[j] - tree[j]);
    printf("%d\n", res);
}