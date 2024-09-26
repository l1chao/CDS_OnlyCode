//所有祖先

#include<iostream>
#include "SandQBase.h"
using namespace std;

void GetAllAncester(BiTree T, int x) {
    InitStack(S);
    BiTNode* p = T;
    BiTNode* r;

    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild
        }
        else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                Pop(S, p);
                // visit(p);
                if (p->data == x) {
                    while (!IsEmpty(S)) {
                        Pop(S, p);
                        printf("%d", p->data);
                    }
                }
                r = p;
                p = NULL;
            }
        }
    }
}