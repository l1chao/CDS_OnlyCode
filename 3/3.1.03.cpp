#include<iostream>
using namespace std;

//出入栈序列是否合法
bool IsValid(char a[], int len) {
    int tag = 0;

    for (int i = 0;i < len;i++) {
        if (a[i] == 'I')
            tag++;
        else
            tag--;

        if (tag < 0) return false;

    }

    if (tag != 0) return false;

    return true;
}

int main() {

    return 0;
}