//交换所有左右子树

#include<iostream>
#include "SandQBase.h"
using namespace std;

void Ans(BiTree T) {
    if (T != NULL) {
        BiTNode* temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
    Ans(T->lchild);
    Ans(T->rchild);
}