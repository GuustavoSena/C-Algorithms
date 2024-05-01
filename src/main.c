#include "../include/graph.h"
#include "../include/queue.h"
#include <stdio.h>

int main()
{
    // Criaremos um grafo com um número definido de vértices
    int numVertices = 5;
    Graph *graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    completeBFS(graph);

    // Liberar a memória alocada para o grafo
    freeGraph(graph);

    return 0;
}
