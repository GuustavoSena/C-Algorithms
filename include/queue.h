#pragma once
#include <stdbool.h>

typedef struct queue_node {
    int value;
    struct queue_node* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

void enqueue(Queue* q, int value);
QueueNode* dequeue(Queue* q);
bool is_empty(Queue* q);
void initQueue(Queue* q);