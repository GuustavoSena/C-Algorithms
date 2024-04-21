#include "graph.h"

// Função para criar um novo nó da lista de adjacência. Como ela tem uma logica única, é melhor separá-la de addEdge. Até porque ela também pode ser usada em outro locais.
AdjListNode *newAdjListNode(int dest)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo dado um número de vértices.
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Cria um array de lista de adjacências. Tamanho do array será o numero de vertices.
    graph->array = (AdjList *)malloc(numVertices * sizeof(AdjList));

    // Inicializa cada lista de adjacência como vazia fazendo cada cabeça ser nula (NULL).
    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adiciona uma aresta em um grafo direcionado
void addEdge(Graph *graph, int src, int dest)
{
    // Adiciona uma aresta da origem ao destino (src, dest). Um novo nó é adicionado na lista de adjacência da origem (src). O nó é adicionado no começo.
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Função para liberar memoria do grafo
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
    {
        AdjListNode *node = graph->array[i].head;
        while (node)
        {
            AdjListNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}
