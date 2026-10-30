#include <stdio.h>

#define INF 9999

int main() {
    int cost[10][10], distance[10], visited[10];
    int n, source, i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        next = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && cost[next][i] != INF &&
                distance[next] + cost[next][i] < distance[i]) {
                distance[i] = distance[next] + cost[next][i];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d: No path\n", i);
        else
            printf("Vertex %d: %d\n", i, distance[i]);
    }

    return 0;
}