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

//思路是：将一个点不断下沉
void HeadAdjust1(ElemType A[], int len, int k) {
    A[0] = A[k]; //如果需要不断调整（不断下沉），可以最后调整，而不是两两调整。
    for (int i = 2 * k;i <= len;i *= 2) {
        if (i < len && A[i] < A[i + 1])i++;//找到k的较大孩子，让i指向它。此后父是k，子是i。
        if (A[0] >= A[i]) break; //如果此时父节点已经大于两个孩子，单点调整结束。
        else {//这里的else可以省略
            A[k] = A[i];//把孩子节点上移。
            k = i;
        }
    }//如果k没有子节点i了，就结束了。
    A[k] = A[0];//要么break要么叶节点。i=空才知道k是叶节点。
}

<<<<<<< HEAD
void BuildMaxHeap(ElemType A[], int len) {//A开始时无序。调整所有的分支节点。叶节点不用调整。
    for (int i = len / 2;i > 0;i--) {
        HeadAdjust(A, i, len);
=======
//将一个乱序数组变成大根堆
void BuildMaxHeap1(ElemType A[], int len) {
    for (int i = len / 2;i >= 1;i--) {
        HeadAdjust1(A, len, i);
>>>>>>> origin/HEAD
    }
}

//堆排序。必须要在前两者的基础上进行。
void HeapSort(ElemType A[], int len) {
    BuildMaxHeap1(A, len);
    for (int i = len;i > 1;i--) {
        swap(A[1], A[i]);//将最大的放在末尾。换过来的单点只需要adjust即可。
        HeadAdjust1(A, i - 1, 1);
    }
}