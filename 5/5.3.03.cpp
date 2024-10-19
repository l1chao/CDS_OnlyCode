// 真别看了我说
#include<iostream>
#include "SandQBase.h"
using namespace std;

//后序遍历非递归算法
void PostOrder_NoCursion(BiTree T) {
    BiTNode* r;
    BiTNode* p = T;
    InitStack(S);

    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}

void Repeat(BiTree T) {
    InitStack(S);
    BiTNode* p = T;
    BiTNode* r;
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}