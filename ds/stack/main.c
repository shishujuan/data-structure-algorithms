#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

/****************/
/** 栈基本操作 **/
/***************/

void testStackOperation()
{
    Stack *stack = stackNew(5);
    if (!stack) {
        printf("No memory\n");
        return;
    }

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    
    printf("Top element is %d\n", peek(stack));
    printf("Stack size is %d\n", peek(stack));
    pop(stack);
    pop(stack);
    pop(stack);

    if (IS_EMPTY(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}


/*****************/
/* 后缀表达式求值*/
/*****************/

int evaluatePostfix(char *exp)
{
    Stack* stack = stackNew(strlen(exp));
    int i;
 
    if (!stack) {
        printf("New stack failed\n");
        exit(E_NOMEM);
    }
 
    for (i = 0; exp[i]; ++i) {
        // 如果是数字，直接压栈
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0');
        } else {// 如果遇到符号，则弹出栈顶两个元素计算，并将结果压栈
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2/val1);   break;
            }
        }
    }

    return pop(stack); 
}

void testEvaluatePostfix()
{
    char *exp = "6523+8*+3+*";
    int ret = evaluatePostfix(exp);
    printf("EvaluatePostfix result:%d\n", ret);
}


/*****************/
/*** 栈逆序 ******/
/*****************/

/**
 * 在栈底插入一个元素
 */
void insertAtBottom(Stack *stack, int v)
{
    if (IS_EMPTY(stack)) {
        push(stack, v);
    } else {
        int x = pop(stack);
        insertAtBottom(stack, v);
        push(stack, x);
    }
}

/**
 * 栈逆序
 */
void stackReverse(Stack *stack)
{
    if (IS_EMPTY(stack))
        return;

    int top = pop(stack);
    stackReverse(stack);
    insertAtBottom(stack, top);
}

/**
 * 栈逆序测试函数
 */
void testStackReverse()
{
    int capacity = 4;
    Stack *stack = stackNew(capacity);

    int i;
    for (i = 1; i <= capacity; i++) {
        push(stack, i);
    }
    stackTraverseTop(stack);
    printf("\n");
    stackReverse(stack);
    stackTraverseTop(stack);
    printf("\n");
}

/*********************************/
/*设计包含min函数的栈- 辅助栈方式*/
/*********************************/
void minStackPush(Stack *orgStack, Stack *minStack, int v)
{
    if (IS_FULL(orgStack)) {
        printf("Stack Full\n");
        exit(E_FULL);
    }

    push(orgStack, v);
    if (IS_EMPTY(minStack) || v < peek(minStack)) {
        push(minStack, v);
    }
}

int minStackPop(Stack *orgStack, Stack *minStack)
{
    if (IS_EMPTY(orgStack)) {
        printf("Stack Empty\n");
        exit(E_EMPTY);
    }

    if (peek(orgStack) == peek(minStack)) {
        pop(minStack);
    }
    return pop(orgStack);
}

int minStackMin(Stack *minStack)
{
    return peek(minStack);
}


/********************************/
/** 设计包含min函数的栈-差值法 **/
/********************************/
void minStackPushUseDelta(Stack *stack, int v)
{
    if (IS_EMPTY(stack)) { // 空栈，直接压入v两次
        push(stack, v);
        push(stack, v);
    } else { 
       int oldMin = pop(stack); // 栈顶保存的是压入v之前的栈中最小值
       int delta = v - oldMin; 
       int newMin = delta < 0 ? v : oldMin;
       push(stack, delta); // 压入 v 与之前栈中的最小值之差
       push(stack, newMin); // 最后压入当前栈中最小值
   }
}

int minStackPopUseDelta(Stack *stack)
{
    int min = pop(stack);
    int delta = pop(stack);
    int v, oldMin;

    if (delta < 0) { // 最后压入的元素比min小，则min就是最后压入的元素
        v = min;
        oldMin = v - delta;
    } else { // 最后压入的值不是最小值，则min为oldMin。
        oldMin = min;
        v = oldMin + delta;
    }

    if (!IS_EMPTY(stack)) { // 如果栈不为空，则压入oldMin
        push(stack, oldMin);
    }
    return v;
}

int minStackMinUseDelta(Stack *stack)
{
    return peek(stack);
}

void testMinStack()
{
    int capacity = 5;
    Stack *orgStack = stackNew(capacity);
    Stack *minStack = stackNew(capacity);
    minStackPush(orgStack, minStack, 3);
    printf("Stack min:%d\n", minStackMin(minStack));
    minStackPush(orgStack, minStack, 4);
    minStackPush(orgStack, minStack, 2);
    minStackPush(orgStack, minStack, 5);
    minStackPush(orgStack, minStack, 1);
    printf("Stack min:%d\n", minStackMin(minStack));
    minStackPop(orgStack, minStack);
    minStackPop(orgStack, minStack);
    printf("Stack min:%d\n", minStackMin(minStack));

    minStack = stackNew(capacity + 1);
    minStackPushUseDelta(minStack, 3);
    minStackPushUseDelta(minStack, 4);
    minStackPushUseDelta(minStack, 2);
    minStackPushUseDelta(minStack, 5);
    minStackPushUseDelta(minStack, 1);
    printf("Stack Delta min:%d\n", minStackMinUseDelta(minStack));
    minStackPopUseDelta(minStack);
    printf("Stack Delta min:%d\n", minStackMinUseDelta(minStack));
    minStackPopUseDelta(minStack);
    printf("Stack Delta min:%d\n", minStackMinUseDelta(minStack));
    minStackPopUseDelta(minStack);
    printf("Stack Delta min:%d\n", minStackMinUseDelta(minStack));
    minStackPopUseDelta(minStack);
    printf("Stack Delta min:%d\n", minStackMinUseDelta(minStack));
}


/***************/
/** 出栈数目 **/
/**************/

/**
 * 计算出栈数目
 * - in：目前栈中的元素数目
 * - out：目前已经出栈的元素数目
 * - wait：目前还未进栈的元素数目
 */
int sumOfStackPopSequence(Stack *stack, int in, int out, int wait)
{
    if (out == stack->capacity) { // 元素全部出栈了，则总数+1
        return 1;
    } 

    int sum = 0;

    if (wait > 0)
        sum += sumOfStackPopSequence(stack, in + 1, out, wait - 1);

    if (in > 0)
        sum += sumOfStackPopSequence(stack, in - 1, out + 1, wait);

    return sum;
}

/**
 * 打印所有出栈序列。
 */
void printStackPopSequence(int input[], int i, int n, Stack *stk, Stack *output)
{
    if (i >= n) {
        stackTraverseBottom(output); // output 从栈底开始打印
        stackTraverseTop(stk); // stk 从栈顶开始打印
        printf("\n");
        return;
    }

    push(stk, input[i]);
    printStackPopSequence(input, i+1, n, stk, output);
    pop(stk);

    if (IS_EMPTY(stk))
        return;

    int v = pop(stk);
    push(output, v);
    printStackPopSequence(input, i, n, stk, output);
    push(stk, v);
    pop(output);
}

void testSumOfStackPopSequence()
{
    int input[] = {1, 2, 3};
    int size = sizeof(input) / sizeof(input[0]);

    Stack *stack = stackNew(size);
    int ret = sumOfStackPopSequence(stack, 0, 0, size);
    printf("Sum of Pop Sequence:%d\n", ret);

    Stack *stk = stackNew(size);
    Stack *output = stackNew(size);
    printStackPopSequence(input, 0, size, stk, output);
}

int main()
{
    testStackOperation();
    testEvaluatePostfix();
    testMinStack();
    testSumOfStackPopSequence();
    testStackReverse();
    return 0;
}
