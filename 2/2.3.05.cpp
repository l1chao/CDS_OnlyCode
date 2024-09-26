#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//找到两个单链表的公共节点。
LNode* FindPublicNode(LinkList l1, LinkList l2) {
    int len1 = 0, len2 = 0;
    LNode* p1 = l1, * p2 = l2;

    for (;p1->next != NULL;p1 = p1->next, len1++) {}
    for (;p2->next != NULL;p2 = p2->next, len2++) {}

    if (len1 > len2)
        for (int i = 0;i < (len1 - len2);i++, p1 = p1->next);
    else if (len1 < len2)
        for (int i = 0;i < (len2 - len1);i++, p2 = p2->next);

    for (;p1 != p2;p1 = p1->next, p2 = p2->next);

    return p1;
}