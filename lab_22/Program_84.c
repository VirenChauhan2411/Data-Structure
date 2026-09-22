#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int vertex;
    struct Edge *next;
};

struct Edge *addEdge(struct Edge *head, int vertex) {
    struct Edge *newEdge;

    newEdge = malloc(sizeof(struct Edge));
    newEdge->vertex = vertex;
    newEdge->next = head;

    return newEdge;
}

void dfs(struct Edge *graph[], int vertex, int visited[]) {
    struct Edge *current;

    visited[vertex] = 1;
    printf("%d ", vertex);

    current = graph[vertex];

    while (current != NULL) {
        if (visited[current->vertex] == 0)
            dfs(graph, current->vertex, visited);

        current = current->next;
    }
}

void bfs(struct Edge *graph[], int start) {
    int queue[100];
    int visited[100] = {0};
    int front;
    int rear;
    int vertex;
    struct Edge *current;

    front = 0;
    rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        vertex = queue[front++];
        printf("%d ", vertex);

        current = graph[vertex];

        while (current != NULL) {
            if (visited[current->vertex] == 0) {
                visited[current->vertex] = 1;
                queue[rear++] = current->vertex;
            }

            current = current->next;
        }
    }
}

int main() {
    struct Edge *graph[100] = {NULL};
    int vertices;
    int edges;
    int first;
    int second;
    int start;
    int visited[100] = {0};
    int i;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    printf("Enter edges:\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &first, &second);

        graph[first] = addEdge(graph[first], second);
        graph[second] = addEdge(graph[second], first);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS: ");
    dfs(graph, start, visited);

    printf("\nBFS: ");
    bfs(graph, start);

    printf("\n");

    return 0;
}
