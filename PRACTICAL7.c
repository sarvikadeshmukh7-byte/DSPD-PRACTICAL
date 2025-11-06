#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

int adj[N+1][4];
int deg[N+1];

void build_graph() {
    for(int i=1;i<=N;i++) deg[i] = 0;
    for(int i=1;i<=9;i++){
        int r = (i-1)/3;
        int c = (i-1)%3;
        if(r > 0) adj[i][ deg[i]++ ] = i-3;
        if(r < 2) adj[i][ deg[i]++ ] = i+3;
        if(c > 0) adj[i][ deg[i]++ ] = i-1;
        if(c < 2) adj[i][ deg[i]++ ] = i+1;
    }
    for(int i=1;i<=N;i++){
        for(int a=0;a<deg[i];a++){
            for(int b=a+1;b<deg[i];b++){
                if(adj[i][b] < adj[i][a]){
                    int t = adj[i][a];
                    adj[i][a] = adj[i][b];
                    adj[i][b] = t;
                }
            }
        }
    }
}

void bfs(int start) {
    bool visited[N+1] = {false};
    int queue[N+1];
    int front = 0, rear = 0;
    visited[start] = true;
    queue[ rear++ ] = start;
    printf("BFS order: ");
    while(front < rear) {
        int v = queue[ front++ ];
        printf("%d ", v);
        for(int i=0;i<deg[v];i++){
            int w = adj[v][i];
            if(!visited[w]){
                visited[w] = true;
                queue[ rear++ ] = w;
            }
        }
    }
    printf("\n");
}

void dfs_iterative(int start) {
    bool visited[N+1] = {false};
    int stack[N+1];
    int top = 0;
    stack[ top++ ] = start;
    printf("DFS order: ");
    while(top > 0) {
        int v = stack[ --top ];
        if(visited[v]) continue;
        visited[v] = true;
        printf("%d ", v);
        for(int i = deg[v]-1; i >= 0; i--){
            int w = adj[v][i];
            if(!visited[w]){
                stack[ top++ ] = w;
            }
        }
    }
    printf("\n");
}

int main(){
    build_graph();
    bfs(1);
    dfs_iterative(1);
    return 0;
}
