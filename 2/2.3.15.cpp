#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

//判断单链表是否有环
int IsCircle(LinkList L) {
    LNode* slow = L, * quick = L;

    while (quick->next != NULL || quick != NULL) {
        slow = slow->next;
        quick = quick->next->next;

        if (quick == slow) return 1;
    }
    return 0;//无环
}