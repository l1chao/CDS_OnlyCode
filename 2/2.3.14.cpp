#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

//无头结点，右循环移动
void CycleMove(LinkList L, int k, int n) {
    LNode* slow = L;
    LNode* quick = L;

    for (int i = 0;i < k;i++, quick = quick->next) {}
    while (quick->next != NULL) {
        slow = slow->next;
        quick = quick->next;
    }

    quick->next = L;
    L = slow->next;
    slow->next = NULL;
}