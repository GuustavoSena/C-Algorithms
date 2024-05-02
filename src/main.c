#include "../include/graph.h"
#include "../include/queue.h"
#include "../Graphs/BFS/include/maze_bfs.h"
#include <stdio.h>

int main()
{
    printf("Iniciando o programa...\n");

    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};

    int *mazePtrs[5];
    for (int i = 0; i < 5; i++)
    {
        mazePtrs[i] = maze[i];
    }

    int rows = 5, cols = 5;
    Graph graph;
    graph.numVertices = rows * cols;
    graph.array = (AdjList *)malloc(graph.numVertices * sizeof(AdjList));
    for (int i = 0; i < graph.numVertices; i++)
    {
        graph.array[i].head = NULL;
    }

    initGraphFromMaze(&graph, mazePtrs, rows, cols);

    bool *visited = (bool *)malloc(graph.numVertices * sizeof(bool));
    for (int i = 0; i < graph.numVertices; i++)
    {
        visited[i] = false;
    }

    bfsMaze(&graph, 0, 24, visited); // Começa no canto superior esquerdo, termina no inferior direito

    free(visited);
    return 0;
}
