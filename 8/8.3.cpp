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
    while (i < j) {
        while (i < j && A[j] >= pivot)j--;//先是右边往左边移动，因为左边缺一个（在pivot里面）
        A[i] = A[j];
        while (i < j && A[i] <= pivot)i++;
        A[j] = A[i];
    }//i==j的时候退出循环。

    A[i] = pivot;
    return i;
}

void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

//一体版
void QuickSort_whole(ElemType A[], int low, int high) {
    if (low >= high) return;

    ElemType pivot = A[low];
    int i = low, j = high;
    while (i < j) {
        while (i<j && A[j]>pivot)j--;
        A[i] = A[j];
        while (i < j && A[i] <= pivot)i++;
        A[j] = A[i];
    }
    A[i] = pivot;

    QuickSort(A, low, i - 1);
    QuickSort(A, i + 1, high);
}


int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    BubbleSort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}