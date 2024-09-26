//判定两个相似
#include<iostream>
#include "SandQBase.h"
using namespace std;

int IsSimilar(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) return 1;
    if (T1 == NULL ^ T2 == NULL)return 0;

    return IsSimilar(T1->lchild, T2->lchild) * IsSimilar(T1->rchild, T2->rchild);
}