//归并排序
#include<iostream>
using namespace std;

typedef int ElemType;

void swap(ElemType* a, ElemType* b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

//A[low,mid] A[mid+1,high]
int* B = (int*)malloc(sizeof(int) * (n + 1));
void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    for (int p = low;p <= high;p++) {//将low,high段复制到B里面去。
        B[p] = A[p];
    }

    //B是temp，将B里面的两段元素放回A里面去，k是A的指针。
    for (i = low, j = mid + 1, k = i;i <= mid && j <= high;k++) {
        if (B[i] < B[j]) {
            A[k] = B[i++];
        }
        else {
            A[k] = B[j++];
        }
    }

    while (i <= mid)A[k++] = A[i++];
    while (j <= high)A[k++] = A[j++];
}

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid - 1);
        mergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}