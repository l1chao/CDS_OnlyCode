//Stack Queue所需要的基础操作。

#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef struct {
    int data[MAXSIZE];
    int rear, front;
}Queue;

typedef struct {
    int data[MAXSIZE];
    int top;
}Stack;

//栈操作(top指向下一空)

Stack* InitStack() {
    Stack* S = (Stack*)malloc(sizeof(Stack));//malloc申请的变量内存空间生命周期由程序员控制。
    S->top = 0;
    return S;
}

bool StackEmpty(Stack* S) {
    if (S->top == 0) return true;
    return false;
}

bool StackFull(Stack* S) {
    if (S->top == MAXSIZE) return true;
    return false;
}

bool Push(Stack* S, int val) {
    if (StackFull(S)) {
        return false;
    }

    S->data[S->top] = val;
    S->top++;
    return true;
}

bool Pop(Stack* S, int* val) {
    if (StackEmpty(S)) {
        return false;
    }

    S->top--;
    *val = S->data[S->top];
    return true;
}

int Get(Stack* S) {
    return S->data[S->top - 1];
}

void RuinStack(Stack* S) {
    free(S);
}

//队列操作(循环队列，rear指向下一空，牺牲一格来判满)

bool QueueEmpty(Queue* Q) {
    if (Q->rear == Q->front) {
        return true;
    }
    return false;
}

bool QueueFull(Queue* Q) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return true;
    }
    return false;
}

//入队
bool EnQueue(Queue* Q, int val) {
    if (QueueFull(Q)) {
        return false;
    }

    Q->data[Q->rear] = val;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(Queue* Q, int* val) {
    if (QueueEmpty(Q)) {
        return false;
    }

    *val = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return true;
}