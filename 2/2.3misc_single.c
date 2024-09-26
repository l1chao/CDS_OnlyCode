//单链表的基本操作及测试

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;

//链表初始化。指针的指针。
bool InitLink(LinkList* L) {
    (*L) = (LNode*)malloc(sizeof(LNode));
    (*L)->val = 9527;
    (*L)->next = NULL;
    return true;
}

//循环输入数值，头插法建立链表。
LinkList List_HeadInsert() {
    LNode* L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    int arr[] = { 2,9,3,7,4,5,4,3,1 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0;i < arrlen;i++) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->val = arr[i];

        p->next = L->next;
        L->next = p;//后面一个前面一个
    }

    return L;
}

//循环输入数值，尾插法建立链表
LinkList List_TailInsert() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode* p = L;
    int arr[] = { 2,9,3,7,4,5,4,3,1 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0;i < arrlen;i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        p->next = newNode;
        p = p->next;//后面一个+转移指针一个
    }
    return L;
}

//查值。返回第一个x的节点。
LNode* FindValue(LinkList L, int x) {
    LNode* p = L;
    for (;p != NULL && p->val != x;p = p->next) {}//希望得到状态1：p->val == x;希望在状态2时结束

    return p;
}

//查序（注意函数返回值是什么：返回对应结点）
LNode* FindLoc(LinkList L, int loc) {
    int locp = 0;
    LNode* p = L;

    for (;p != NULL && locp < loc;p = p->next, locp++) {}

    return p;
}

//增添结点到第i个（结点序数从第1个开始）
bool Insert(LinkList L, int loc, int val) {
    if (loc < 1) {
        return false;
    }

    int locp = 0;
    LNode* p = L;

    for (;p != NULL && locp < loc - 1;p = p->next, locp++) {}

    if (p == NULL) return false;

    LNode* new = (LNode*)malloc(sizeof(LNode));
    new->val = val;
    new->next = NULL;
    p->next = new;
    return true;
}

//前插操作
bool FrontInsert(LNode* n, int val) {
    LNode* temp = (LNode*)malloc(sizeof(LNode));
    temp->next = NULL;
    temp->val = n->val;
    n->val = val;

    temp->next = n->next;
    n->next = temp;
}
//实质是后插+值的复制。
//注意，前插算法要解决的问题是“单链表中已知某一个节点而不知其前驱的情况下，如何在该节点前插一个节点？”
//用不着前插算法的场景：1.双链表则不用；2.单链表允许从头开始遍历则不用。


//删除指定位置的节点（有时候可能会让返回被删除节点）
bool Del(LinkList L, int loc) {
    if (loc < 1) return false;

    int locp = 0;
    LNode* p = L;
    for (; locp < loc - 1;p = p->next, locp++) {
        if (p->next == NULL) return false;
    }

    LNode* temp = p->next;
    p->next = temp->next;
    free(temp);
    return true;
}

//求表长（有头结点）
int ListLen(LinkList L) {
    int loc;
    LNode* p = L;

    for (;p->next != NULL;p = p->next, loc++) {}
    return loc;
}

//测试
int main() {
    LNode* L;
    InitLink(&L);
    printf("%d", L->val);


    // L = List_TailInsert();//空指针作为函数参数传递的时候，2,9,3,7,4,5,4,3,1


    // LNode* p = FindLoc(L, 0);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 1);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 2);
    // printf("%d\n", p->val);

    // p = FindLoc(L, 5);
    // printf("%d\n", p->val);

    //查值测试
    // LNode* p = FindValue(L, 9);
    // printf("%d\n", p->val);

    //查序测试 2,9,3,7,4,5,4,3,1
    // LNode* p = FindLoc(L, 2);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");
    // p = FindLoc(L, 0);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");
    // p = FindLoc(L, 100);
    // if (p != NULL)
    //     printf("%d", p->val);
    // else
    //     printf("不存在！");

    //插入测试
    // Insert(L, 3, 9527);
    // printf("%d\n", FindLoc(L, 3)->val);

    //删除测试 2,9,3,7,4,5,4,3,1
    // int loc = 3;
    // int val = 0;
    // printf("%d\n", FindLoc(L, loc)->val);
    // Delete(L, loc, &val);
    // printf("%d\n", val);
    // printf("%d\n", FindLoc(L, loc)->val);

    //表长测试
    // printf("%d", ListLen(L));


}