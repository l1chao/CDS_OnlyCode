//并查集的实现

#include<iostream>
#include "SandQBase.h"
#define SIZE 13
using namespace std;

int UFSets[SIZE];

//初始化并查集
void Initial(int S[]) {
    for (int i = 0;i < SIZE;i++) {
        S[i] = -1;
    }
}

//Find 查操作 O(n)  
int Find(int S[], int x) {
    while (S[x] >= 0) {
        x = S[x];
    }
    return x;
}

//Union 并操作
void Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    S[Root1] = Root2;
}