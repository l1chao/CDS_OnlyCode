#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

bool Reverse(LinkList L) {
    if (L->next == NULL) return false;

    LNode* p = L->next;

    while (p->next != NULL) {
        LNode* temp = p->next;
        p->next = temp->next;
        temp->next = L->next;
        L->next = temp;
    }

    return true;
}

//似乎并不需要反馈
void Reverse1(LinkList L) {
    if (L->next == NULL) return;

    LNode* p = L->next;
    while (p->next != NULL) {
        LNode* temp = p->next;
        p->next = temp->next;
        temp->next = L->next;
        L->next = temp;
    }
}
//2024-9-24 09:40:36
void Reverse2(LinkList L) {
    if (L->next == NULL || L->next->next == NULL) return;

    LNode* p = L->next;
    while (p->next != NULL) {
        LNode* temp = p->next;
        p->next = temp->next;
        temp->next = L->next;
        L->next = temp;
    }
}

LinkList TailInsert() {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* p = L;

    int a[8] = { 1,2,3,4,5,6,7,8 };
    int aLen = sizeof(a) / sizeof(a[0]);

    for (int i = 0;i < aLen;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = a[i];
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
    }

    return L;
}

int main() {
    LNode* L = TailInsert();

    Reverse1(L);
    LNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }

    return 0;
}