#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//链表去重
bool DelDipulate(LinkList L) {
    if (L->next == NULL) {
        return false;
    }

    LNode* p = L->next; //去重是从第1个有效元素开始的。此时p是第2个元素的前驱节点。

    while (p->next != NULL) {
        if (p->next->val == p->val) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }

    return true;
}

bool DelDipulate1(LinkList L) {
    if (L->next == NULL) return false;

    LNode* p = L->next;
    while (p->next != NULL) {
        if (p->next->val == p->val) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}

bool DelDipulate(LinkList L) {
    if (L->next == NULL) return false;

    LNode* p = L->next;
    while (p->next != NULL) {
        if (p->next->val == p->val) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else { p = p->next; }

    }
}

LinkList TailInsert() {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* p = L;

    int a[5] = { 1,1,1,1,1 };
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

void LinkPrint(LinkList L) {
    if (L->next == NULL)
        printf("Link is empty.");

    for (LNode* p = L->next; p != NULL;p = p->next)
        printf("%d ", p->val);
}

int main() {
    LNode* L = TailInsert();

    DelDipulate(L);
    LinkPrint(L);

    return 0;
}