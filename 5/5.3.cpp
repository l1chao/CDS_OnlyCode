#include<iostream>
#include "TreeBase.h"
#include "SandQBase.h"
using namespace std;

//访问节点的逻辑。这里用打印来代替。
void visit(BiTree T) {
    printf("%d", T->data);
}


// 树的循环遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}


//树的非递归遍历
void PreOrder_NoRecursion(BiTree T) {
    Stack* S = InitStack();
    BiTNode* p = T;

    if (p || !StackEmpty(S)) {
        if (p != NULL) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

void InOrder_NoRecursion(BiTree T) {
    Stack* S = InitStack();
    BiTNode* p = T;

    if (p || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, &p);//有一点运行时候的问题
            visit(p);
            p = p->rchild;
        }
    }
}

void PostOrder_NoRecursion(BiTree T) {

}

//层次遍历
void LevelOrder(BiTree T) {
    Queue* Q = InitQueue();
    BiTree p = T;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        EnQueue(Q, p->lchild);//判定p.left是否为空假设放在EnQueue内部进行。
        EnQueue(Q, p->rchild);
    }
}

//层次遍历伪代码所需辅助函数
Queue* InitQueue() {}
void EnQueue(Queue* Q, BiTree p) {}
void DeQueue(Queue* Q, BiTree p) {}
bool IsEmpty(Queue* Q) {}


