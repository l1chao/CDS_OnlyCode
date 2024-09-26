#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SqList {
    int data[100];
    int length;
} SqList;


int* Answer(int* a) {
    int aa = 1;
    a = &aa;
    return a;
}
int main() {
    int* a;
    Answer(a);
    printf("%d", *a);

    return 0;
}