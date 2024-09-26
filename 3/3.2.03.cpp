#include<iostream>
#include"SandQBase.h"

#define MAXSIZE 100
using namespace std;

//用2个栈来模拟队列的入队、出队、判空

Stack inS, outS;
bool QueueEmpty1() {
    if (StackEmpty(&inS) && StackEmpty(&outS)) return true;
    return false;
}

bool EnQueue1(int x) {
    if (StackFull(&inS) && StackFull(&outS)) return false;
    if (StackFull(&inS) && StackEmpty(&outS)) {
        int val;
        while (!StackEmpty(&inS)) {
            Pop(&inS, &val);
            Push(&outS, val);
        }
    }
    Push(&inS, x);
    return true;
}

bool DeQueue1(int* val) {
    int temp;
    if (QueueEmpty1()) return false;
    if (StackEmpty(&outS) && StackFull(&inS)) {
        while (!StackEmpty(&inS)) {
            Pop(&inS, &temp);
            Push(&outS, temp);
        }
    }
    Pop(&outS, val);
    return true;
}