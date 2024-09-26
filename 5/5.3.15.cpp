//将所有的叶节点串起来
#include<iostream>
#include "SandQBase.h"
using namespace std;


void Ans(BiTree T) {
    BiTNode* p = T;
    BiTNode* r;
    InitStack(S);
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            if (p->lchild == NULL && p->rchild == NULL) {
                if (r != NULL) {
                    r->rchild = p;
                    r = p;
                }
                else {
                    r = p;
                }
            }
            p = p->rchild;
        }
    }
}
