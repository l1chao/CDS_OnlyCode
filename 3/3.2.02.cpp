#include<iostream>
#include"SandQBase.h"

#define MAXSIZE 100
using namespace std;


void Reverse(Stack* S, Queue* Q) {
    int val;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, &val);
        Push(S, val);
    }
    while (!StackEmpty(S)) {
        Pop(S, &val);
        EnQueue(Q, val);
    }
}


int main() {

    return 0;
}