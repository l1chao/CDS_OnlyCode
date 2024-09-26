#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//寻找两条链的所有公共元素
LNode* FindAllPub(LinkList l1, LinkList l2) {
    LNode* l0 = (LNode*)malloc(sizeof(LNode));
    l0->next = NULL;

    LNode* p1 = l1->next, * p2 = l2->next, * p0 = l0;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val == p2->val) {
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->val = p1->val;
            newNode->next = NULL;

            p0->next = newNode;
            p0 = p0->next;

            // p1 = p1->next;
            // p2 = p2->next;//?
        }
        else if (p1->val < p2->val) p1 = p1->next;
        else p2 = p2->next;
    }
    return l0;
}

LinkList FindAllPub1(LinkList l1, LinkList l2) {
    LNode* p1 = l1->next, * p2 = l2->next;

    LNode* l0 = (LNode*)malloc(sizeof(LNode));//头结点
    LNode* p = l0;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val == p2->val) {
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->val = p1->val;
            newNode->next = NULL;
            p->next = newNode;
            p = p->next;

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->val < p2->val) p1 = p1->next;
        else p2 = p2->next;
    }
    return l0;
}

LinkList TailInsert(int a[], int n) {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    LNode* p = L;
    int aLen = n;
    for (int i = 0;i < aLen;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = a[i];
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
    }

    return L;
}

void PrintLink(LinkList L) {
    if (L->next == NULL) {
        printf("WRONG! Link is empty.");
        return;
    }

    LNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
}
int main() {
    int a[6] = { 1,3,4,6,9,10 };
    int b[7] = { 2,4,6,7,9,11,12 };

    LNode* l1 = TailInsert(a, 6);
    LNode* l2 = TailInsert(b, 7);

    PrintLink(FindAllPub(l1, l2));
}