#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;

//最速找x，找到将x与后面一个元素互换；找不到则插入x。
bool FindOrInsertX(SqList* L, int x) {
    if (L->length == 0) {
        return false;
    }
    int loc;
    if (FindX(L, x, 0, L->length - 1, &loc)) {
        int temp = L->data[loc];
        L->data[loc] = L->data[loc + 1];
        L->data[loc + 1] = temp;
    }
    else {
        for (int i = loc;i < L->length;i++) {
            L->data[i + 1] = L->data[i];
        }
        L->length++;
        L->data[loc] = x;
    }
}

//这里面最关键的还是二分查找的一个tips：如果没有找到，则head表示待查找元素应该在的位置
bool FindX(SqList* L, int x, int head, int tail, int* loc) {
    while (head <= tail) {
        int mid = (head + tail) / 2;
        if (L->data[mid] == x) {
            *loc = mid;
            return true;
        }
        else if (L->data[mid] > x) {
            tail = mid - 1;
        }
        else head = mid + 1;
    }

    *loc = head;
    return false;
}


////////9.23

//找到元素x的下标 or 插入x的位置
bool FindX(SqList* L, int head, int tail, int x, int* loc) {
    int mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (x == L->data[mid]) {
            *loc = mid;
            return true;
        }
        else if (x < L->data[mid]) {
            tail = mid - 1;
        }
        else {
            tail = mid + 1;
        }
    }
    *loc = head;
    return false;
}

void Ans(SqList* L, int x) {
    int loc;
    bool flag = FindX(L, 0, L->length - 1, x, &loc);
    if (flag) {
        if (loc <= L->length - 2) {
            int temp = L->data[loc];
            L->data[loc] = L->data[loc + 1];
            L->data[loc + 1] = temp;
        }
    }
    else {
        for (int i = loc;i < L->length - 1;i++) {
            L->data[i + 1] = L->data[i];
        }
        L->data[loc] = x;
        L->length++;
    }
}