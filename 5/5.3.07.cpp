//统计二叉树双分支节点个数

#include<iostream>
#include "SandQBase.h"
using namespace std;

int Ans(BiTree T) {
    int total = 0;

    InitStack(S);
    BiTNode* p = T;
    while (p || !IsEmpty(S)) {
        if (p != NULL) {
            // visit(p);
            if (p->lchild != NULL && p->rchild != NULL)
                total++;
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

