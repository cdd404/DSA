#include <stdio.h>
#include <stdlib.h>

int a[50][50], n, visited[50];
int q[50], front, rear;

void resetVisited() {
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
}

void bfs(int v) {
    int i, cur;
    front = 0;
    rear = 0;
    visited[v] = 1;
    q[rear] = v;
    printf("%d ", v);
    while (front <= rear) {
        cur = q[front++];
        for (i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int ch, start, i, j;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    while (1) {
        printf("\n\n==>1. BFS");
        printf("\n==>2. DFS");
        printf("\n==>3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                resetVisited();
                printf("Nodes reachable from starting vertex %d are:\n", start);
                bfs(start);
                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0)
                        printf("\nThe vertex not reachable is %d", i);
                }
                break;
            case 2:
                resetVisited();
                printf("Nodes reachable from starting vertex %d are:\n", start);
                dfs(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Please enter a valid choice.\n");
        }
    }
}
