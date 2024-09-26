#include<iostream>
using namespace std;

typedef int ElemType;

void swap(ElemType* a, ElemType* b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

//简单选择排序
void SelectSort(ElemType A[], int n) {
    int min;
    for (int i = 0;i < n - 1;i++) {
        min = i;
        for (int j = i + 1;j < n;j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i)swap(&A[min], &A[i]);
    }
}

//堆排序(大根堆为例)
void HeadAdjust(ElemType A[], int k, int len) {
    A[0] = A[k];
    for (int i = 2 * k;i <= len;i *= 2) {
        if (i < len&& A[i] < A[i + 1]) {
            i++;
        }
        if (A[0] >= A[i])break;
        A[k] = A[i];
        k = i;
    }
    A[k] = A[0];
}

void BuildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2;i > 0;i--) {
        HeadAdjust(A, i, len);
    }
}

void HeapSort(ElemType A[], int len) {
    BuildMaxHeap(A, len);
    for (int i = len;i > 1;i--) {
        swap(&A[1], &A[i]);
        HeadAdjust(A, 1, i - 1);
    }
}