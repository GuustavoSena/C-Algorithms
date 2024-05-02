#include "../include/maze_bfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initGraphFromMaze(Graph *graph, int **maze, int rows, int cols)
{
    int vertexId = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 0)
            { // Apenas células passáveis
                // Adicionar arestas para células adjacentes passáveis
                if (i > 0 && maze[i - 1][j] == 0)
                    addEdge(graph, vertexId, vertexId - cols);
                if (j > 0 && maze[i][j - 1] == 0)
                    addEdge(graph, vertexId, vertexId - 1);
                if (i < rows - 1 && maze[i + 1][j] == 0)
                    addEdge(graph, vertexId, vertexId + cols);
                if (j < cols - 1 && maze[i][j + 1] == 0)
                    addEdge(graph, vertexId, vertexId + 1);
            }
            vertexId++;
        }
    }
}

void bfsMaze(Graph *graph, int startVertex, int endVertex, bool *visited)
{
    Queue q;
    initQueue(&q);

    int *parent = (int *)malloc(graph->numVertices * sizeof(int));
    if (parent == NULL)
    {
        fprintf(stderr, "Memory allocation failed for parent array\n");
        return; // Não se esqueça de tratar a falha de alocação adequadamente.
    }
    memset(parent, -1, graph->numVertices * sizeof(int)); // Inicializa todos os elementos como -1.

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!is_empty(&q))
    {
        int currentVertex = dequeue(&q)->value;

        if (currentVertex == endVertex)
        {
            printf("Path found:\n");
            // Backtracking do ultimo vertice ao primeiro usando o array de parentes
            int crawl = endVertex;
            while (crawl != -1)
            {
                crawl == startVertex ? printf("%d", crawl) : printf("%d <- ", crawl);
                crawl = parent[crawl];
            }
            printf("\n");
            return;
        }

        AdjListNode *adjList = graph->array[currentVertex].head;
        while (adjList != NULL)
        {
            int adjVertex = adjList->dest;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                parent[adjVertex] = currentVertex;
                enqueue(&q, adjVertex);
            }
            adjList = adjList->next;
        }
    }
    printf("No path found.\n");
    free(parent);
}
