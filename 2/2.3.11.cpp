#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
}DNode, * DoubleList;

//判定带头结点的循环双链表是否对称
int isSymmetry(DoubleList L) {
    if (L->next == NULL) return 0;//认为空链表不属于对称

    LNode* head = L->next;
    LNode* tail = L->prior;

    while (head != tail && tail->next != head) {
        if (head->val != tail->val) {
            return 0;
        }
    }
    return true;
}
//认为len==1时，链表对称。
int isSymmetry(DoubleList L) {
    LNode* head = L->next;
    LNode* tail = L->prior;

    while (head != tail && head->prior != tail) {
        if (head->val != tail->val) return 0;
        head = head->next;
        tail = tail->prior;
    }
    return 1;
}