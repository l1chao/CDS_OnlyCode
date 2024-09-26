#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* prior;
    struct LNode* next;
    int freq;
}LNode, * LinkList;

LNode* FindPub(LinkList a, LinkList b) {
    int aLen = 0;
    int bLen = 0;

    LNode* pa = a;
    LNode* pb = b;
    while (pa->next != NULL) {
        pa = pa->next;
        aLen++;
    }
    while (pb->next != NULL) {
        pb = pb->next;
        bLen++;
    }
    pa = a->next;
    pb = b->next;
    if (aLen > bLen) {
        for (int i = 0;i < aLen - bLen;i++, pa = pa->next) {}
    }
    if (aLen < bLen) {
        for (int i = 0;i < bLen - aLen;i++, pb = pb->next) {}
    }

    while (pa != NULL && pa != pb) {}
    int _a = 1;
    _a += 1;
    return pa;
}