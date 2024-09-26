#include<iostream>
#include "SandQBase.h"
using namespace std;

//自下而上 从右到左的层次遍历
void NewLevelTraverse(BiTree T) {
    BiTNode* p = T;
    Stack* S = InitStack();
    Queue* Q = InitQueue();
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        Push(S, p);
        EnQueue(Q, p->lchild);
        EnQueue(Q, p->rchild);
    }
    while (!IsEmpty(S)) {
        Pop(S, p);
        visit(p);
    }
}

