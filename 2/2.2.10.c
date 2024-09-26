#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//为什么能够想到双逆呢？是因为前面的题目有这样的解法。
void Answer(SqList* l, int p) {
    Reverse(l, 0, l->length - 1);
    Reverse(l, 0, l->length - p - 1);
    Reverse(l, l->length - p, l->length - 1);
}

void Reverse(SqList* l, int head, int tail) {
    int temp;
    for (int i = 0;i <= l->length / 2;i++) {
        temp = l->data[i];
        l->data[i] = l->data[l->length - 1 - i];
        l->data[l->length - 1 - i] = temp;
    }
}