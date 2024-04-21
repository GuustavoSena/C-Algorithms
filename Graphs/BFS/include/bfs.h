#pragma once
#include "graph.h"
#include "queue.h"

void bfs(Graph *graph, int startVertex, bool *visited);
void completeBFS(Graph *graph);