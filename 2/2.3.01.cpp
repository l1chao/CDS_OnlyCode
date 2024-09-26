#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//删除多个x
void DelXs(LinkList L, int x) {
    LNode* p = L;
    for (;p->next != NULL;) {
        if (p->next->val == x) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}

//删除多个X
void DelXs(LinkList L, int x) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->val == x) {

        }
    }
}

//用尾插法构造出一个链表并返回。
LinkList TailInsert() {
    LNode* L = (LNode*)malloc(sizeof(LNode));//有一个头结点
    L->next = NULL;

    LNode* p = L; //对于所有的链表，开头都需要一个指针，想都不用想直接设出来。

    int a[8] = { 1,2,3,3,4,5,6,3 };
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

//打印链表
void LinkListPrint(LinkList L) {
    if (L->next == NULL) {
        printf("Empty LinkList.");
    }

    LNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
}

int main() {
    LNode* L = TailInsert();

    DelXs(L, 3);
    LinkListPrint(L);
}