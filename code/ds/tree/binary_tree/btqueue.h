#ifndef __BT_QUEUE_H
#define __BT_QUEUE_H

#include "bt.h"

typedef struct BTNodeQueue {
    int capacity;
    int size;
    int front;
    int rear;
    BTNode* items[];
} BTNodeQueue;

#define QUEUE_SIZE(queue) (queue->size)

BTNodeQueue *queueNew(int capacity);
void enqueue(BTNodeQueue *queue, BTNode *v);
BTNode *dequeue(BTNodeQueue *queue);

#endif
