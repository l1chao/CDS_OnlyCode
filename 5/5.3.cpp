//1.树的遍历
//2.线索化
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

    while (p || !StackEmpty(S)) {//每一轮：访问 or 调整。调整后，访问要到下一轮才进行。
        if (p != NULL) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, &p);
            p = p->rchild;
        }
    }
}


void InOrder_NoRecursion(BiTree T) {
    Stack* S = InitStack();
    BiTNode* p = T;

    while (p || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);//有一点运行时候的问题
            visit(p);
            p = p->rchild;
        }
    }
}

// void PostOrder_NoRecursion(BiTree T) {}//不用掌握

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

void levelans(BiTree T) {
    InitQueue(Q);
    BiTNode* p = T;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);
    }
}

//层次遍历伪代码所需辅助函数
Queue* InitQueue() {}
void EnQueue(Queue* Q, BiTree p) {}
void DeQueue(Queue* Q, BiTree p) {}
bool IsEmpty(Queue* Q) {}



//////////////////////////////////////////////////////////线索化

typedef struct ThreadNode {
    int data;
    struct ThreadNode* lchild, * rchild;
    int ltag, rtag;
}ThreadNode, * ThreadTree;


//线索化二叉树
void InThread(ThreadTree p, ThreadTree pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);

        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;//1表示rchild指向结点后继，所以这里要处理为1，表示后继为空。
    }
}

//中序线索化树的遍历
ThreadNode* FirstNode(ThreadNode T) {
    ThreadNode p = T;
    while (p->ltag == 0) p = p->lchild;
    return p;
}

ThreadNode* NextNode(ThreadNode T) {
    if (T->rtag == 1) return T->rchild;
    return FirstNode(T->rchild);
}

void InOrder(ThreadNode T) {
    for (ThreadNode p = FirstNode(T);p;p = NextNode(p)) {
        visit(p);
    }
}

void PreThread(ThreadTree p, ThreadTree pre) {
    if (p != NULL) {
        if (p->lchild == NULL) {
            pre->lchild = pre;
            pre->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        if (p->ltag == 0)//必须有，否则产生循环便利问题
            PreThread(p->lchild, pre);
        PreThread(p->rchild, pre);
    }
}

void CreatePreThread(ThreadTree T) {
    ThreadTree pre;
    if (T != NULL) {
        PreThread(T, pre);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}
void PostThread(ThreadTree p, ThreadTree pre) {
    if (p != NULL) {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}
void CreatePostThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        PostThread(T, pre);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}