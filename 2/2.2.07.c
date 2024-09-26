#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//(a1,a2,a3...b1,b2,b3) ->(b1,b2,b3...a1,a2,a3)

bool ReversePartly(SqList* L, int m, int n) { //0~m-1 m~m+n-1
    Reverse(L, 0, m - 1);
    Reverse(L, m, n + m - 1);
    Reverse(L, 0, n + m - 1);
}

void Reverse(SqList* L, int head, int tail) {
    int mid = (head + tail) / 2;

    for (int i = 0;i <= mid;i++) {
        int temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }
}

void ReversePartly(SqList* L, int head, int tail) {
    int mid = (head + tail - 1) / 2;

    for (int i = head; i <= mid;i++) {
        int temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }
}

void Reverse(SqList* L, int m, int n) {
    ReversePartly(L, 0, m - 1);
    ReversePartly(L, m, m + n - 1);
    ReversePartly(L, 0, m + n - 1);
}