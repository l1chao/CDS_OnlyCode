//并查集的实现

#include<iostream>
#include "SandQBase.h"
#define SIZE 13
using namespace std;

int UFSets[SIZE];

//初始化并查集
void Initial(int S[]) {
    for (int i = 0;i < SIZE;i++) {
        S[i] = -1;                   //单独成集合
    }
}

//Find 查操作 O(n)  
//1.查操作实际是指查找某元素所在集合的根 2.判断两个元素是否属于统一集合：查两次根，看根是否相同。
int Find(int S[], int x) {
    while (S[x] >= 0) {
        x = S[x];
    }
    return x;
}

//Union 并操作
//注意！Union默认接受的Root1和Root2已经是根节点了！
//如果两个非根节点元素求并 == 求这两个元素的根的并
void Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    S[Root1] = Root2;  // S[x]的意思是x的父节点值
}