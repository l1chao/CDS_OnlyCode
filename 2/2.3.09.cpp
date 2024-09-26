#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//就地保留公共元素。保留a里面的公共元素。
void RemainPub(LinkList a, LinkList b) {
    LNode* p = a;
    LNode* q = b;

    while (p->next != NULL && q->next != NULL) {
        if (p->next->val == q->next->val) {
            p = p->next;
            q = q->next;
        }
        else if (p->next->val < q->next->val) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else if (p->next->val > q->next->val) {
            q = q->next;
        }
    }
    // p->next = NULL;//内存泄漏
    // p = p->next;
    while (p != NULL) {
        LNode* temp = p;
        free(temp);
        p = p->next;
    }
}

LinkList TailInsert(int a[], int length) {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* p = L;

    for (int i = 0;i < length;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = a[i];
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;
    }

    return L;
}

//有头节点
void printLinkList(LinkList L) {
    LNode* p = L->next;
    for (;p != NULL;p = p->next) {
        printf("%d ", p->val);
    }
}

int main() {
    int a[5] = { 1,2,4,6,10 };
    int b[5] = { 2,4,6,7,8 };
    LNode* la = TailInsert(a, 5);
    LNode* lb = TailInsert(b, 5);

    RemainPub(la, lb);
    printLinkList(la);

}