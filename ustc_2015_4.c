// 求1经过k到n的最短路径
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct queue_node {
    int val;
    struct queue_node *next;
} Node;

void queue_push(Node **head, int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new -> val = val;
    new -> next = NULL;
    if ((*head) == NULL) {
        *head = new;
        return;
    }
    new -> next = *head;
    *head = new;
}

int queue_pop(Node **head) {
    if (*head == NULL) {
        return -1;
    }
    if ((*head) -> next == NULL) {
        int val = (*head) -> val;
        free(*head);
        *head = NULL;
        return val;
    }

    Node *p = *head;
    while (p -> next -> next != NULL) p = p -> next;
    int val = p -> next -> val;
    free(p -> next);
    p -> next = NULL;
    return val;
}

int find_sep(char *s) {
    for (int i = 0; i < strlen(s); ++i) if (' ' == s[i] || '\n' == s[i]) return i;
    return -1;
}

char *substring(char *s, int start_idx, int end_idx) {
    char *s_new = (char *)malloc(sizeof(char) * (end_idx - start_idx + 1));
    for (int i = 0; i < end_idx - start_idx; ++i) s_new[i] = s[start_idx + i];
    s_new[end_idx - start_idx] = '\0';
    return s_new;
}

void dijkstra(int *nodes_from, int *nodes_to, int *distances, int len, int start_node, int end_node, int first) {
    int cur_node = 1;
    Node *queue = NULL;
    int nodes_prev[MAX] = {-1}, distances_total[MAX] = {-1}, visited[MAX] = {-1};
    distances_total[cur_node] = 0;
    queue_push(&queue, start_node);

    while (queue != NULL) {
        int cur_node = queue_pop(&queue);
        for (int i = 0; i < len; ++i) {
            if (nodes_from[i] == cur_node && visited[nodes_to[i]] != 1) {
                int node_to = nodes_to[i];
                visited[node_to] = 1;
                queue_push(&queue, node_to);

                int dist_to_cur_total = distances_total[cur_node] + distances[i];
                if (nodes_prev[node_to] < 0 || distances_total[node_to] < dist_to_cur_total) {
                    nodes_prev[node_to] = cur_node;
                    distances_total[node_to] = dist_to_cur_total;
                }
            }
        }
    }

    int paths[MAX], len_paths = 0;
    cur_node = end_node;
    while (nodes_prev[cur_node] != -1) {
        paths[len_paths++] = cur_node;
        cur_node = nodes_prev[cur_node];
    }
    if (first == 1) for (int i = len_paths - 1; i >= 0; --i) printf("%d ", paths[i]);
    else for (int i = len_paths - 2; i >= 0; --i) printf("%d ", paths[i]);
}

int main() {
    FILE *fp = fopen("datas/2015/input_4.txt", "r");
    int n, k;
    fscanf(fp, "n=%d k=%d", &n, &k);

    int len_nodes = 0;
    int nodes_from[MAX], nodes_to[MAX], distances[MAX];
    for (int i = 0; i < n; ++i) {
        char *tmp = (char *)malloc(sizeof(char) * MAX);
        int node_from, node_to, dist;
        fscanf(fp, "%d ", &node_from);
        fgets(tmp, MAX, fp);

        int flag = 0;
        while (1) {
            int idx = find_sep(tmp);
            if (idx == -1) break;
            int e = atoi(substring(tmp, 0, idx));
            tmp = substring(tmp, idx + 1, strlen(tmp));
            if (flag % 2 == 0) {
                node_to = e;
                flag = 1;
            } else {
                dist = e;
                nodes_from[len_nodes] = node_from;
                nodes_to[len_nodes] = node_to;
                distances[len_nodes++] = dist;
                flag = 0;
            }
        }
    }

    dijkstra(nodes_from, nodes_to, distances, n, 1, k, 1);
    dijkstra(nodes_from, nodes_to, distances, n, k, n, -1);
}