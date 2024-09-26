//线索化相关代码

#include<iostream>
using namespace std;

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
        pre->rtag = 1;
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

