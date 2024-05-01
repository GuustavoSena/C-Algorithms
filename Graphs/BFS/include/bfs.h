#pragma once
#include "../../../include/graph.h"
#include "../../../include/queue.h"

void bfs(Graph *graph, int startVertex, bool *visited);
void completeBFS(Graph *graph);