#include<iostream>
using namespace std;

typedef struct BSTNode {
    int data;
    struct BSTNode* left, * right;
}BSTNode, * BiTree;

//递归实现
BSTNode* BST_Search(BiTree T, int x) {
    if (T != NULL) {
        if (x == T->data) return T;
        else if (x < T->data) BST_Search(T->left, x);
        else if (x > T->data) BST_Search(T->right, x);
    }
}

//非递归
BSTNode* BST_Search(BiTree T, int x) {
    while (T != NULL && T->data != x) {
        if (x < T->data) T = T->left;
        else T = T->right;
    }

    return T;
}

//排序树插入
int BST_Insert(BiTree& T, int x) {
    //如果为空
    if (!T) {
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->left = NULL;
        T->right = NULL;
        T->data = x;
        return 1;
    }

    //如果值重复，插入失败
    if (T->data == x) return 0;
    else if (x < T->data) BST_Insert(T->left, x);
    else BST_Insert(T->right, x);
}

