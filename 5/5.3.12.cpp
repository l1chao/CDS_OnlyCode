//最近公共祖先

#include<iostream>
#include "SandQBase.h"
using namespace std;

typedef struct TNode {
    int INFO;
    struct TNode* LLINK, * RLINK;
}TNode;

void ANCESTOR(BiTree ROOT, TNode* p, TNode* q, TNode* r) {
    InitStack(qS);
    InitStack(pS);
    TNode* pp = T, * qp = T;
    TNode* pr, * qr;
    int qLen = 0, pLen = 0;

    while (pp || !IsEmpty(pS)) {
        if (pp) {
            Push(pS, pp);
            pLen++;
            p = p->LLINK;
        }
        else {
            GetTop(pS, pp);
            if (pp->RLINK && pp->RLINK != pr) {
                pp = pp->RLINK;
            }
            else {
                Pop(pS, pp);
                if (pp == p) break;
                r = p;
                p = NULL;
            }
        }
    }

    while (qp || !IsEmpty(qS)) {
        if (qp) {
            Push(pS, qp);
            qLen++;
            p = p->LLINK;
        }
        else {
            GetTop(qS, qp);
            if (qp->RLINK && qp->RLINK != qr) {
                qp = qp->RLINK;
            }
            else {
                Pop(qS, qp);
                if (qp == q) break;
                r = p;
                p = NULL;
            }
        }
    }

    if (pLen > qLen) {
        for (int i = 0;i < (pLen - qLen);i++) {
            Pop(pS, pp);
        }
    }
    if (pLen < qLen) {
        for (int i = 0;i < (qLen - pLen);i++) {
            Pop(qS, qp);
        }
    }

    while (!IsEmpty(qS)) {
        Pop(qS, qp);
        Pop(pS, pp);
        if (qp == pp) r = qp;
    }
}