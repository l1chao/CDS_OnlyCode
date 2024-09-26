#include<iostream>
using namespace std;

typedef int ElemType;

void swap(ElemType* a, ElemType* b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序
void BubbleSort(ElemType A[], int n) {
    for (int i = 0;i < n;i++) {
        bool flag = false;
        for (int j = n - 1;j > i;j--) {
            if (A[j] < A[j - 1]) {
                swap(&A[j], &A[j - 1]);
                flag = true;
            }
        }

        if (!flag)
            return;
    }
}

//快速排序
int Partition(ElemType A[], int low, int high) {
    ElemType pivot = A[low];
    int i = low, j = high;
    while (low < high) {
        while (low<high && A[j]>pivot) j--;
        A[i] = A[j];
        while (low < high && A[i] < pivot)i++;
        A[j] = A[i];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}