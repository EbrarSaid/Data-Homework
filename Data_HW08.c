#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

void dfs(int node, int graph[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], 
         int cluster[MAX_NODES], int cluster_id, int num_nodes) {
    visited[node] = true;
    cluster[node] = cluster_id;
    
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, cluster, cluster_id, num_nodes);
        }
    }
}

void extract_clusters(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    bool visited[MAX_NODES] = {false};
    int cluster[MAX_NODES] = {-1};
    int cluster_id = 0;
    
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, cluster, cluster_id, num_nodes);
            cluster_id++;
        }
    }
    
    printf("Clusters found:\n");
    for (int i = 0; i < cluster_id; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < num_nodes; j++) {
            if (cluster[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_nodes = 5;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    
    extract_clusters(graph, num_nodes);
    
    return 0;
}