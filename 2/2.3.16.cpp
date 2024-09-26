#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

int Ans(LinkList L) {
    LNode* slow = L, * quick = L;

    while (quick != NULL) {
        slow = slow->next;
        quick = quick->next->next;
    }

    //无头结点单链表逆置
    LNode* fakehead = L->next;
    L->next = fakehead->next;
    fakehead->next = L;
    while (L->next != NULL) {//对于每个状态，先摘下，后接上
        LNode* temp = L->next;
        L->next = temp->next;
        temp->next = fakehead->next;
        fakehead->next = temp;
    }

    int maxNum = 0;
    while (fakehead != NULL) {
        if (fakehead->val + slow->val > maxNum) {
            maxNum = fakehead->val + slow->val;
        }
    }

    return maxNum;
}