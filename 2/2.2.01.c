#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int* data[100];
    int length;
} SqList;

//删除唯一最小元素，函数返回被删除值，并用末元素填补，若顺序表空需报错。
bool DeleteMin(SqList* L, int* e) {
    if (L->length == 0) {
        return false;
    }

    *e = L->data[0];
    int loc = 0;
    for (int j = 1;j < L->length;j++) { //循环的始末位置，一般都是按照最正常的流程来看的。如果只是1个单位的变动，一般结束约束不会错误。
        if (L->data[j] < *e) {
            *e = L->data[j];
            loc = j;
        }
    }

    L->data[loc] = L->data[L->length - 1];
    L->length--;

    return true;
}

bool DeleteMin(SqList* L, int* e) {
    if (L->length == 0) {
        return false;
    }
    int loc = 0;
    for (int i = 1;i < L->length;i++) {
        if (L->data[i] < L->data[loc]) {
            loc = i;
        }
    }

    *e = L->data[loc];
    L->data[loc] = L->data[L->length - 1];
    L->length--;

    return true;
}