#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//合并两个有序表
bool Merge(SqList* a, SqList* b, SqList* new) {
    int pa = 0, pb = 0, p = 0;
    for (;pa < a->length && pb < b->length;) {
        if (a->data[pa] <= b->data[pb]) {
            new->data[p] = a->data[pa];
            pa++;
            p++;
        }
        else {
            new->data[p] = b->data[pb];
            pb++;
            p++;
        }
    }

    for (;pa < a->length;pa++, p++) {
        new->data[p] = a->data[pa];
    }

    for (;pb < b->length;pb++, p++) {
        new->data[p] = a->data[pa];
    }

    new->length = p;//这里是p，不是p+1，因为p在结束循环的时候，是指向下一个空位。
    return true;
}

bool repeat1(SqList* a, SqList* b, SqList* new) {
    if (a->length + b->length > new->length) return false;

    int pa = 0, pb = 0, p = 0;
    while (pa < a->length && pb < b->length) {
        if (a->data[pa] <= b->data[pb])
            new->data[p++] = a->data[pa++];
        else
            new->data[p++] = b->data[pb++];
    }

    while (pa < a->length) new->data[p++] = a->data[pa++];
    while (pb < b->length) new->data[p++] = b->data[pb++];
    return true;
}

int main() {
    SqList L;
    L.length = 10;

    int testSqL[100] = { 1,1,1,2,2,3,4,5,5,6 };
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }

    DelDuplicate(&L);

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }
}