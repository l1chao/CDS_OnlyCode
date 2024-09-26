//树基础数据结构

#include<iostream>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
