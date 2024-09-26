//非递归求树高度

#include<iostream>
#include "SandQBase.h"
using namespace std;

//非递归前序遍历
// void PreOrder_NoCursion(BiTree T) {
//     int h = 0;
//     BiTNode* p = T;
//     Stack* S = InitStack();
//     while (p || !IsEmpty(S) {
//         if (p != NULL) {
//             // visit(p);
//             h++;
//             Push(S,p);
//             p = p->lchild;
//         }
//         else {
//             Pop(S, p);
//             p = p->rchild;
//         }
//     }
// }

//层序遍历！！
void PreOrder_NoCursion(BiTree T) {
    int h = 0;
    Queue* Q = InitQueue();

    BiTNode* p = T;
    BiTNode* last = p;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        // visit(p);
        EnQueue(Q, p->lchild);
        EnQueue(Q, p->rchild);
        if (p == last) { //这个判断必须要写在两个EnQueue后面
            h++;
            last = GetRear(Q);//读队尾
        }
    }
}