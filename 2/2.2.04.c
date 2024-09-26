#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//无序顺序表删除关键字值在s与t(s<t)之间的数据元素。注意健壮性。（实际上和2.2.03一样的）
bool DelStoT(SqList* L, int s, int t) {
    if (L->length == 0 || s > t) {
        return false;
    }

    int k = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] >= s && L->data[i] <= t) {
            k++;
        }
        else {
            L->data[i - k] = L->data[i];
        }
    }
    L->length -= k;
    return true;
}



//有序表删除[s,t]内元素。主要是考察数组范围的讨论。要点在讨论应该完备。（st相对于数组的情况一共有6种）
bool DelStoT1(SqList* L, int s, int t) {
    if (L->length == 0 || s > t) {
        printf("L is empty or s>t");
        return false;
    }

    int head, tail;
    for (head = 0;head < L->length && L->data[head] < s;head++);
    for (tail = head + 1; tail < L->length && L->data[tail] <= t;tail++);

    int distance = tail - head;
    for (int i = tail;i < L->length;i++) {
        L->data[i - distance] = L->data[i];
    }
    L->length -= distance;

    return true;
}

bool DelStoT2(SqList* L, int s, int t) {
    if (s >= t || L->length == 0) return false;

    int head, tail = 0;
    int i = 0;
    for (;i < L->length && L->data[i] < s;i++);
    head = i;
    for (;i < L->length && L->data[i] <= t;i++);
    tail = i;

    int distance = tail - head;
    for (int j = tail;j < L->length;j++) {
        L->data[j - distance] = L->data[j];
    }
    L->length -= distance;
    return true;
}

int main() {
    SqList L;

    int testSqL[11] = { 2,4,99,1,3,5,6,22,7,8,10 };//自定义1
    L.length = sizeof(testSqL) / sizeof(testSqL[0]);
    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    if (DelStoT(&L, 4, 8)) {
        for (int i = 0;i < L.length;i++) {
            printf("%d ", L.data[i]);
        }
        printf("delete successfully!");
    }

    printf("delete !");
    return 0;
}