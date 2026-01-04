#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjacency[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjacency[i][j] = 0;
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjacency[u][v] = 1;
    graph->adjacency[v][u] = 1;
}

void dfs(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacency[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

void bfs(Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    Queue queue = {{}, 0, 0};
    
    visited[start] = true;
    queue.items[queue.rear++] = start;
    
    while (queue.front < queue.rear) {
        int vertex = queue.items[queue.front++];
        printf("%d ", vertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacency[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.items[queue.rear++] = i;
            }
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    
    printf("DFS: ");
    bool visited[MAX_VERTICES] = {false};
    dfs(graph, 0, visited);
    printf("\n");
    
    printf("BFS: ");
    bfs(graph, 0);
    printf("\n");
    
    free(graph);
    return 0;
}