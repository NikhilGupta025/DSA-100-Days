#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    // Push to stack after visiting all neighbors
    stack[++top] = v;
}

// Topological Sort function
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// Main function
int main() {
    int V = 6;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}