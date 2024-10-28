#include<iostream>
using namespace std;

typedef int Elemtype;

//直接插入排序
//一般先对主体进行算法编写；然后再处理边界条件。
//对于这个直接插入算法有感觉，用普通的中间情况模拟一下就好了。代码本身考的不多
void InsertSort(Elemtype A[], int n) {//记得要穿入数组长度n，C++和C里面都是如此
    int i, j;
    for (i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; j--)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}


//折半插入排序
//如果默认所有关键字不同，那么直接这么写就行了。
void InsertSort_HalfSearch(Elemtype A[], int n) {
    int i, j, low, high, mid;
    for (i = 2;i < n;i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high) {//默认查不到。并且将==和<合并，这样就能够保持稳定性。
            mid = (high + low) / 2;
            if (A[0] < A[mid]) high = mid - 1;
            else low = high + 1;
        }

        for (int k = i;k >= low + 1;k--) {
            A[k] = A[k - 1];
        }
        A[low] = A[0];
    }
}

void InsertSort_HalfSearch(Elemtype A[], int n) {
    int i, j, mid, h, t;
    for (i = 2;i <= n;i++) {//有哨兵
        if (A[i] < A[i - 1]) {
            h = 1;
            t = i - 1;
            while (h <= t) {
                mid = (h + t) / 2;
                if (A[mid] == A[0]) {
                    for (int k = mid + 1;k <= i - 1;k++) {
                        A[k + 1] = A[k];
                    }
                    A[mid] = A[0];
                    continue;
                }
                else if (A[mid] < A[0]) h = mid + 1;
                else t = mid - 1;
            }
            for (int k = h;k <= i - 1;k++)
                A[k + 1] = A[k];
            A[h] = A[0];
        }
    }
}