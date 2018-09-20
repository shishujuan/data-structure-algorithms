#ifndef __BT_STACK_H
#define __BT_STACK_H

#include "bt.h"

typedef struct BTNodeStack {
    int capacity;
    int top;
    BTNode* items[];
} BTNodeStack;

#define SIZE(stack) (stack->top + 1)
#define IS_EMPTY(stack) (stack->top == -1)
#define IS_FULL(stack) (stack->top == stack->capacity - 1)

#define E_FULL -1
#define E_EMPTY -2
#define E_NOMEM -3

BTNodeStack *stackNew(int capacity);
void push(BTNodeStack *stack, BTNode *node);
BTNode *pop(BTNodeStack *stack);
BTNode *peek(BTNodeStack *stack);

#endif
