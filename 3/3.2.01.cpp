#include<iostream>
#define MAXSIZE 50
using namespace std;

typedef struct {
    int data[MAXSIZE];
    int front, rear;
    int tag;
}SqQueue;

//带tag的循环队列操作

//入队
bool EnQueue(SqQueue Q, int val) {
    if (Q.rear == Q.front && Q.tag == 1) {
        return false;
    }

    Q.tag = 1;
    Q.data[Q.rear] = val;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//出队
bool DeQueue(SqQueue Q, int* val) {
    if (Q.rear == Q.front && Q.tag == 0) {
        return false;
    }

    Q.tag = 0;
    *val = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}


int main() {

    return 0;
}