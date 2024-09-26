//删除特定子树

#include<iostream>
#include "SandQBase.h"
using namespace std;

//递归释放一棵树
void DelTree(BiTree T) {
    if (T != NULL) {
        DelTree(T->lchild);
        DelTree(T->rchild);
        free(T);
    }
}

void DelSpecial(BiTree T, int x) {
    InitQueue(Q);
    BiTNode* p;
    if (T->data == x) {
        free(T);
        return;
    }

    EnQueue(T);
    while (!IsEmpty(Q)) {
        DeQueue(Q, &p);
        if (p->lchild) {
            if (p->lchild->data == x) {
                DelTree(p->lchild);
                p->lchild = NULL;
            }
            else {
                EnQueue(Q, p->lchild);
            }
        }
        if (p->rchild) {
            if (p->rchild->data == x) {
                DelTree(p->rchild);
                p->rchild == NULL;
            }
            else {
                EnQueue(Q, p->rchild);
            }
        }
    }
}