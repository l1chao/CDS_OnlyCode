//求第k个值

#include<iostream>
#include "SandQBase.h"
using namespace std;

bool GetKthInPreOrder(BiTree T, int k, int* val) {
    int cnt = 0;
    BiTNode* p = T;

    InitStack(S);
    while (p || !IsEmpty(S)) {
        if (p != NULL) {
            // visit(p);
            cnt++;
            if (cnt == k) {
                *val = p->data;
                return true;
            }
            Push(S, p);
            p = p->lchild;

        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }

    return false;
}
