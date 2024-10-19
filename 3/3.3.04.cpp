#include<iostream>
using namespace std;

typedef struct LNode {
    char val;
    struct LNode* next;
}LNode;
//判定字符链表中心对称
bool IsSymmetry(LNode* L) {
    LNode* slow = L, * quick = L->next;
    while (quick != NULL && quick->next != NULL) {
        slow = slow->next;
        quick = quick->next->next;
    }

    LNode* p = slow->next;
    while (p->next != NULL) {
        LNode* temp = p->next;
        p->next = temp->next;
        temp->next = slow->next;
        slow->next = temp;
    }

    LNode* pleft = L, * pright = slow->next;
    while (pright != NULL) {
        if (pleft->val != pright->val) return false;
    }
    return true;
}



int main() {

    return 0;
}