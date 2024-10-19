#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//无序表删除特值的
bool Del(LinkList L, int floor, int ceiling) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->val >= floor && p->next->val <= ceiling) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}

//2024年9月24日09:44:47
void Del1(LinkList L, int floor, int ceiling) {
    LNode* p = L;
    while (p->next != NULL) {
        if (p->next->val >= floor && p->next->val <= ceiling) {
            LNode* temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}