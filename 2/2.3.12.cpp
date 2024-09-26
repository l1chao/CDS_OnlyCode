#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;


//链接两个小无需循环单链表为大循环单链表
//假设无头结点，且连接后头指针为h1
void LinkTwoCircle(LinkList h1, LinkList h2) {
    LNode* h1Head = h1->next;
    LNode* h2Head = h2->next;

    h2->next = h1Head;
    h1->next = h2Head;
}