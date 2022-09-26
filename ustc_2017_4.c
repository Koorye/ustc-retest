// 找到去掉就可以使得图不连通的节点
#include <stdio.h>
#define MAX 100

void stack_push(int *stack, int *len, int e) {
    stack[*len] = e;
    ++(*len);
}

int stack_pop(int *stack, int *len) {
    int e = stack[(*len) - 1];
    --(*len);
    return e;
}

int is_connected(int *nodes_from, int *nodes_to, int len) {
    int stack[MAX];
    int len_stack = 0;

    int visit[MAX] = {0};
    int start_node = nodes_from[0];
    stack_push(stack, &len_stack, start_node);
    visit[start_node] = 1;

    while (len_stack > 0) {
        int node = stack_pop(stack, &len_stack);
        for (int i = 0; i < len; ++i) {
            if (nodes_from[i] == node && visit[nodes_to[i]] != 1) {
                stack_push(stack, &len_stack, nodes_to[i]);
                visit[nodes_to[i]] = 1;
            } else if (nodes_to[i] == node && visit[nodes_from[i]] != 1) {
                stack_push(stack, &len_stack, nodes_from[i]);
                visit[nodes_from[i]] = 1; 
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        if (visit[nodes_from[i]] != 1 || visit[nodes_to[i]] != 1) return -1;
    }
    return 1;
}

int isin(int *arr, int len, int e) {
    for (int i = 0; i < len; ++i) if (e == arr[i]) return 1;
    return -1;
}

int main() {
    int n;
    FILE *fp = fopen("datas/2017/input4.txt", "r");
    fscanf(fp, "%d\n", &n);
    int nodes_from[n], nodes_to[n];
    for (int i = 0; i < n; ++i) fscanf(fp, "%d %d\n", &nodes_from[i], &nodes_to[i]);

    int nodes_all[n * 2];
    int len_all = 0;
    for (int i = 0; i < n; ++i) {
        if (isin(nodes_all, len_all, nodes_from[i]) == -1) nodes_all[len_all++] = nodes_from[i];
        if (isin(nodes_all, len_all, nodes_to[i]) == -1) nodes_all[len_all++] = nodes_to[i];
    }

    for (int i = 0; i < len_all; i++) {
        int nodes_from_copy[n * 2];
        int nodes_to_copy[n * 2];

        int idx = 0;
        for (int j = 0; j < n; ++j) {
            if (nodes_from[j] == nodes_all[i] || nodes_to[j] == nodes_all[i]) continue;
            nodes_from_copy[idx] = nodes_from[j];
            nodes_to_copy[idx] = nodes_to[j];
            ++idx;
        }

        for (int j = 0; j < len_all; ++j) {
            if (j == i) continue;
            nodes_from_copy[idx] = nodes_all[j];
            nodes_to_copy[idx] = nodes_all[j];
            ++idx;
        }

        int res = is_connected(nodes_from_copy, nodes_to_copy, idx);
        if (res == -1) {
            printf("%d\n", nodes_all[i]);
            return 0;
        }
    }
    printf("not exist\n");
    return 0;
}