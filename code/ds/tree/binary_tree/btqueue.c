#include <stdio.h>
#include <stdlib.h>
#include "btqueue.h"

/**
 * 初始化栈
 */
BTNodeQueue *queueNew(int capacity)
{
    BTNodeQueue *queue = (BTNodeQueue *)malloc(sizeof(*queue) + sizeof(BTNode *) * capacity);
    if (!queue) {
        printf("BTNodeQueue new failed\n");
        exit(-1);
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->rear = -1;
    return queue;
}

/**
 * 入栈
 */
void enqueue(BTNodeQueue *queue, BTNode *v)
{
    if (QUEUE_SIZE(queue) == queue->capacity) {
        printf("Queue Full\n");
        exit(-1);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = v;
    queue->size++;
}

/**
 * 出栈
 */
BTNode *dequeue(BTNodeQueue *queue)
{
    if (QUEUE_SIZE(queue) == 0) {
        printf("Queue Empty\n");
        exit(-1);
    }
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return queue->items[queue->front];
}
