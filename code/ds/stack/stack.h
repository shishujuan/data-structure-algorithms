#ifndef __STACK_H
#define __STACK_H

typedef struct Stack {
    int capacity;
    int top;
    int items[];
} Stack;

#define SIZE(stack) (stack->top + 1)
#define IS_EMPTY(stack) (stack->top == -1)
#define IS_FULL(stack) (stack->top == stack->capacity - 1)

#define E_FULL -1
#define E_EMPTY -2
#define E_NOMEM -3

Stack *stackNew(int capacity);
void push(Stack *stack, int x);
int pop(Stack *stack);
int peek(Stack *stack);
void stackTraverseTop(Stack *stack);
void stackTraverseBottom(Stack *stack);


#endif
