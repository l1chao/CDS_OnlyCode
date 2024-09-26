#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//有序表删除所有重复元素。
bool DelDuplicate(SqList* L) {
    if (L->length == 0) {
        return false;
    }

    int i, j;
    for (j = 0, i = 1;i < L->length;i++) {
        if (L->data[j] != L->data[i]) {
            j++;
            L->data[j] = L->data[i];
        }
    }

    L->length = j + 1;
    return true;
}

bool repeat1(SqList* L) {
    if (L->length == 0) return false;
    int i, j;
    for (j = 0, i = 1;i < L->length;i++) {
        if (L->data[i] != L->data[j]) {
            j++;
            L->data[j] = L->data[i];
        }
    }
    L->length = j + 1;
    return true;
}


int main() {
    SqList L;

    int testSqL[3] = { 1,1,2 };
    L.length = sizeof(testSqL) / sizeof(testSqL[0]);

    for (int i = 0;i < L.length;i++) {
        L.data[i] = testSqL[i];
    }

    if (DelDuplicate(&L)) {
        for (int i = 0;i < L.length;i++) {
            printf("%d ", L.data[i]);
        }
    }
}