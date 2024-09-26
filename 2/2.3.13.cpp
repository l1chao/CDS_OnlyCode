#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

LNode* Locate(LinkList L, int x) {
    LNode* p = L->next;
    while (p != NULL && p->val != x) {}
    if (p == NULL) return NULL;

    LNode* q = p->prior;
    while (q->freq <= p->freq + 1 && q != L) {
        q = q->prior;
    }

    p->next->prior = p->prior;
    p->prior->next = p->next;

    p->next = q->next;
    q->next->prior = p;
    p->prior = q;
    q->next = p;

    return p;
}