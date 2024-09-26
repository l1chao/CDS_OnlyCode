//双链表操作及测试

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>n 

typedef struct DNode {
    int val;
    struct DNode* next;
    struct DNode* prior;

}DNode, * DoubleList;

//p节点后面插入值为val的节点
//插入有四个指针需要变动。变动逻辑有两种：1.先处理newNode右右  2.先处理newNode右左
void DLInsert(DoubleList L, DNode* p, int val) {
    DNode* new = (DNode*)malloc(sizeof(DNode));
    new->val = val;

    //先处理newNode右右
    // new->next = p->next;
    // p->next->prior = new;
    // new->prior = p;
    // p->next = new;

    //先处理newNode右左
    new->next = p->next;
    new->prior = p;
    p->next->prior = new;
    p->next = new;
}

//删除p节点
//双链表的删除相比于双链表的添加要简单的多（因为只需要处理两条链即可。分别是前的后、后的前）
void DLDel(DoubleList L, DNode* p) {
    p->prior->next = p->next;
    p->next->prior = p;
    free(p);
}

//删除p的前驱节点
void DLDel1(DoubleList L, DNode* p) {
    DNode* temp = p->prior;
    temp->prior->next = p;
    p->prior = temp->prior;
    free(temp);
}