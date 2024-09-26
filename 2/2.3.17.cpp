#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

//找到单链表倒数第k个节点
int FindLastKth(LinkList L, int k) {
    LNode* p = L->next;
    LNode* q = L->next;
    for (int i = 0;i < k - 1;i++) {
        if (p == NULL) {
            return 0;
        }
        p = p->next;
    }

    while (p->next != NULL) {
        p = p->next;
        q = q->next;
    }

    return q->val;
}

