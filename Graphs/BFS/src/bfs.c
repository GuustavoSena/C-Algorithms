#include "../include/bfs.h"
#include <stdio.h> // Para o printf
#include <stdlib.h> // Para malloc e free

void bfs(Graph *graph, int startVertex, bool *visited) {
    Queue q;
    initQueue(&q);
    
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!is_empty(&q)) {
        int currentVertex = dequeue(&q)->value;
        printf("Visited %d\n", currentVertex);

        // Percorre todos os vertices adjacentes ao vértice que saiu da queue por último ( dequeue ali em cima ).
        AdjListNode *adjList = graph->array[currentVertex].head;
        while (adjList != NULL) {
            int adjVertex = adjList->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(&q, adjVertex);
            }
            adjList = adjList->next;
        }
    }
}

void completeBFS(Graph *graph) {
    bool *visited = (bool *)malloc(graph->numVertices * sizeof(bool));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation failed for visited array\n");
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    // Chamando BFS em cada vértice (para analisar possíveis componentes). Se o grafo todo for um CFC, isso nem seria necessário.
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            bfs(graph, i, visited);
        }
    }

    free(visited);
}
