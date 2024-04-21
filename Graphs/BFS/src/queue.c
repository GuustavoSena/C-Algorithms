#include "queue.h"
#include <stdlib.h>

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int value) {
    QueueNode* new_node = malloc(sizeof(QueueNode));
    new_node->value = value;
    new_node->next = NULL;
    if (q->rear != NULL) {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    if (q->front == NULL) {
        q->front = new_node;
    }
    q->size++;
}

QueueNode* dequeue(Queue* q) {
    if (is_empty(q)) return NULL;
    QueueNode* result = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    result->next = NULL; //Não sei se tirar a conexão do QueueNode que saiu com a Queue inteira é crítico para o BFS. Vou manter e ver se temos problema.
    q->size--;
    return result;
}

bool is_empty(Queue* q) {
    return q->size == 0;
}
