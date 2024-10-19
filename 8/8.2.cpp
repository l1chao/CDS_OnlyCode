#include<iostream>
using namespace std;

typedef int Elemtype;

//直接插入排序
void InsertSort(Elemtype A[], int n) {//记得要穿入数组长度n，C++和C里面都是如此
    int i, j;
    for (i = 2; i < n; i++) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; j--)
                A[j + 1] = A[j];
            A[j + 1] = A[0]; //2,4,6,5来验证一遍
        }
    }
}

void InsertionSort(Elemtype A[], int n) {

}


//折半插入排序
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

//希尔排序
