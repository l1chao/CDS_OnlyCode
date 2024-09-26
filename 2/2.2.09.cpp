// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<stdbool.h>
#include<iostream>
#include<map>
using namespace std;


typedef struct SqList {
    int data[100];
    int length;
} SqList;

//找到3组里面所有共同元素 字典方法
void Asw(SqList* a, SqList* b, SqList* c) {
    map<int, int> dict;
    for (int i = 0;i < a->length;i++) {
        dict[a->data[i]] += 1;
        dict[b->data[i]] += 1;
        dict[c->data[i]] += 1;
    }

    for (auto c : dict) {
        if (c.second == 3) printf("%d\n", c.first);
    }
}

void StdAsw(int a[], int b[], int c[], int n) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        if (a[i] == b[j] && b[j] == c[k]) {
            printf("%d\n", a[i]);
            i++;j++;k++;
        }
        else {
            int MaxNum = max(a[i], max(b[i], c[i]));
            if (a[i] < MaxNum)i++;
            if (b[j] < MaxNum)j++;
            if (c[k] < MaxNum)k++;
        }
    }
}

void StdAns(int a[], int b[], int c[], int n) {
    int pa = 0, pb = 0, pc = 0;
    while (pa < n && pb < n && pc < n) {
        if (a[pa] == b[pb] && b[pb] == c[pc]) {
            printf("%d\n", a[pa]);
            pa++;pb++;pc++;
        }
        else if (a[pa] < b[pb] && a[pa] < c[pc])pa++;
        else if (b[pb] < a[pa] && b[pb] < c[pc])pb++;
        else pc++;
    }
}

int main() {


    return 0;
}