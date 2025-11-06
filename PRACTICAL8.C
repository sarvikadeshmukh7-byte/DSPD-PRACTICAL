  #include <stdio.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int distance[MAX];
int parent[MAX];

int findMinNode(int n) {
    int min = INF, minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n, e;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter edges (node1 node2 weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    distance[start] = 0;

    for (int count = 1; count <= n; count++) {
        int u = findMinNode(n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                int newDist = distance[u] + graph[u][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                    parent[v] = u;
                }
            }
        }
    }

    printf("\nShortest distances from node %d:\n", start);
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INF)
            printf("Node %d: Unreachable (-1)\n", i);
        else
            printf("Node %d: %d\n", i, distance[i]);
    }

    printf("\nShortest path tree (child <- parent):\n");
    for (int i = 1; i <= n; i++) {
        if (i != start && parent[i] != -1)
            printf("%d <- %d\n", i, parent[i]);
    }

    return 0;
}
