#include <stdio.h>
#include <stdlib.h>
#include "btstack.h"

/**
 * 初始化栈
 */
BTNodeStack *stackNew(int capacity)
{
    BTNodeStack *stack = (BTNodeStack *)malloc(sizeof(*stack) + sizeof(BTNode *) * capacity);
    if (!stack) {
        printf("BTNodeStack new failed\n");
        exit(E_NOMEM);
    }

    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

/**
 * 入栈
 */
void push(BTNodeStack *stack, BTNode *v)
{
    if (IS_FULL(stack)) {
        printf("Push: BTNodeStack Overflow\n");
        exit(E_FULL);
    }
    stack->items[++stack->top] = v;
}

/**
 * 出栈
 */
BTNode *pop(BTNodeStack *stack)
{
    if (IS_EMPTY(stack)) {
        return NULL;
    }

    return stack->items[stack->top--];
}

/**
 * 返回栈顶元素
 */
BTNode *peek(BTNodeStack *stack)
{
    if (IS_EMPTY(stack)) {
        return NULL;
    }
    return stack->items[stack->top];
}
