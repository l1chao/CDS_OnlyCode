#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//对于各长度为n的线性表L，时间复杂度为O(n) 空间复杂度为O(1)的算法，删除所有值为x的的数据元素
bool DelX(SqList* L, int x) {
    if (L->length == 0) {
        return false;
    }

    int k = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] == x) {
            k++;
        }
        else {
            L->data[i - k] = L->data[i];
        }
    }

    L->length = L->length - k;
    return true;
}

bool DelX(SqList* L, int x) {
    if (L->length == 0) {
        return false;
    }

    int k = 0;
    for (int i = 0;i < L->length;i++) {
        if (L->data[i] == x) {
            k++;
        }
        else {
            L->data[i - k] == L->data[i];
        }
    }

    L->length -= k;
    return true;
}

//不能够很快验证算法的正确性。
bool MyDelX(SqList* L, int x) {
    if (L->length == 0) {
        return false;
    }

    for (int i = 0;i < L->length;) {
        if (L->data[i] == x) {
            L->data[i] = L->data[L->length - 1];
            L->length--;
        }
        else {
            i++;
        }
    }
    return true;
}

int main() {
    SqList L; //此时已经开辟内存了。c的声明有点混乱，变量声明的时候就已经开辟内存了，这一点和Go不一样。
    int a[9] = { 1,2,33,42,11,33,998,18,33 };

    L.length = 9;
    for (int i = 0;i < L.length;i++) {
        L.data[i] = a[i];
    }

    // DelX(&L, 33);
    MyDelX(&L, 33);

    for (int i = 0;i < L.length;i++) {
        printf("%d ", L.data[i]);
    }

    return 0;
}