//判定完全二叉树

#include<iostream>
#include "SandQBase.h"
using namespace std;

bool IsFullBT(BiTree T) {
    Queue* Q = InitQueue();
    BiTNode* p = T;

    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);

        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else {
            while (!IsEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL)
                    return false;
            }
        }
    }
    return true;
}

bool Repeat(BiTree T) {
    BitNode* p = T;
    InitQueue(Q);
    EnQueue(Q, p);

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else {
            while (!IsEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL) {
                    return false;
                }
            }
        }
    }
    return true;
}

