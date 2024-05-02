#pragma once
#include "../../../include/graph.h"  // Certifique-se de que este caminho está correto
#include "../../../include/queue.h" 

void initGraphFromMaze(Graph *graph, int **maze, int rows, int cols);
void bfsMaze(Graph *graph, int startVertex, int endVertex, bool *visited);
