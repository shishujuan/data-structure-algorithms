#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * 初始化栈
 */
Stack *stackNew(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(*stack) + sizeof(int) * capacity);
    if (!stack) {
        printf("Stack new failed\n");
        exit(E_NOMEM);
    }

    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

/**
 * 入栈
 */
void push(Stack *stack, int v)
{
    if (IS_FULL(stack)) {
        printf("Push: Stack Overflow\n");
        exit(E_FULL);
    }
    stack->items[++stack->top] = v;
}

/**
 * 出栈
 */
int pop(Stack *stack)
{
    if (IS_EMPTY(stack)) {
        printf("Pop: Stack Empty\n");
        exit(E_EMPTY);
    }

    return stack->items[stack->top--];
}

/**
 * 返回栈顶元素
 */
int peek(Stack *stack)
{
    if (IS_EMPTY(stack)) {
        printf("Peek: Stack Empty\n");
        exit(E_EMPTY);
    }
    return stack->items[stack->top];
}

/**
 * 从栈顶遍历
 */
void stackTraverseTop(Stack *stack)
{
    int i;
    for (i = SIZE(stack) - 1; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
}

/**
 * 从栈底遍历
 */
void stackTraverseBottom(Stack *stack)
{
    int i;
    for (i = 0; i < SIZE(stack); i++) {
        printf("%d ", stack->items[i]);
    }
}
