#pragma once
#include <stdlib.h>

// Estrutura para representar um nó da lista de adjacências
typedef struct adjListNode
{
    int dest;
    struct adjListNode *next;
} AdjListNode;

// Estrutura para representar uma lista de adjacencias (a cabeça dela, que na prática seria como o array funciona, ele tem o endereço da cabeça e daí em diante)
typedef struct adjList
{
    AdjListNode *head; // Ponteiro para a cabaça do nó da lista
} AdjList;

// Estrutura para representar um grafo. Estou utilizando a representação por listas de adjacências
// Tamanho do array será o numero de vértices do grafo
typedef struct graph
{
    int numVertices;
    AdjList *array;
} Graph;

AdjListNode *newAdjListNode(int dest);
Graph *createGraph(int numVertices);
void addEdge(Graph *graph, int src, int dest);
void freeGraph(Graph *graph);
