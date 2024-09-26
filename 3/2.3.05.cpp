#include<iostream>
#define MAXSIZE 50
using namespace std;

//共享栈相关操作。
//巧妙设计：在使用共享栈的时候需要确定到底是用哪个栈。栈号的0、1对应top[2]的0、1。
typedef struct SharedStack {
    int data[MAXSIZE];
    int top[2];
}SharedStack;

SharedStack S;

int push(int i, int x) {
    if (i < 0 || i>1) {
        printf("输入错误！i只能为0或1.");
        return 0;
    }

    if (S.top[0] + 1 == S.top[1]) return 0;

    switch (i) {
    case 0: S.data[++S.top[0]] = x;return 1; break;
    case 1: S.data[++S.top[1]] = x;
    }
}


int main() {

    return 0;
}