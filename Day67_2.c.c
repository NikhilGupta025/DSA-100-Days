#include <stdlib.h>

void dfs(int node, int** adj, int* size, int* visited, int* stack, int* top, int* cycle) {
    if (*cycle) return;

    visited[node] = 1; // visiting

    for (int i = 0; i < size[node]; i++) {
        int nei = adj[node][i];

        if (visited[nei] == 0) {
            dfs(nei, adj, size, visited, stack, top, cycle);
        }
        else if (visited[nei] == 1) {
            // cycle detected
            *cycle = 1;
            return;
        }
    }

    visited[node] = 2; // visited
    stack[(*top)++] = node;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* size = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // build graph: bi -> ai
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][size[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* stack = (int*)malloc(numCourses * sizeof(int));
    int top = 0;
    int cycle = 0;

    // DFS on all nodes
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            dfs(i, adj, size, visited, stack, &top, &cycle);
        }
    }

    // if cycle → return empty array
    if (cycle) {
        *returnSize = 0;
        return (int*)malloc(0);
    }

    // reverse stack
    int* result = (int*)malloc(numCourses * sizeof(int));
    *returnSize = numCourses;

    for (int i = 0; i < numCourses; i++) {
        result[i] = stack[numCourses - 1 - i];
    }

    return result;
}