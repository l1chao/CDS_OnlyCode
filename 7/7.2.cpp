//数组折半查找
//+改进版（可插入点）
#include<iostream>
using namespace std;


typedef struct {
    int data[100];
    int Len;
} SStable;

//通过改变head和tail来找到对象。
int Binary_Search(SStable L, int key) {
    int head = 0;
    int tail = L.Len;
    int mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (L.data[mid] == key) return key;
        else if (L.data[mid] < key) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//没找到，返回插入下表版本
bool Binary_Search_adv(SStable L, int key, int* loc) {
    int head = 0, tail = L.Len, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (L.data[mid] == key) {
            *loc = mid;
            return true;
        }
        else if (L.data[mid] < key) head = mid + 1;
        else tail = mid - 1;
    }
    *loc = head;//返回的head就是可以插入的地方
    return false;
}
