#include<iostream>
#include"SandQBase.h"

#define MAXSIZE 100
using namespace std;

//括号匹配检测
bool IsMatched(char a[]) {
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = 0;

    for (int i = 0;a[i] != '\0';i++) {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
            Push(S, a[i]);
        }
        else {
            int val;
            if (!Pop(S, &val)) { return false; }

            if (a[i] == ')' && val != '(' || a[i] == ']' && val != '[' || a[i] == '}' && val != '{') {
                return false;
            }
        }
    }
    if (StackEmpty(S)) return true;
    else return false;
}

//一路排除掉。具体操作没有说就别管。（栈相关）
bool IsMatched(char a[]) {
    InitStack(S);
    for (int i = 0;a[i] != '\0';i++) {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{') Push(&S, a[i]);

        if (IsEmpty(S)) return false;

        char temp = a[i];
        Pop(&S, &temp);
        if (a[i] == ')' && temp != '(' ||
            a[i] == ']' && temp != '[' ||
            a[i] == '}' && temp != '{')
            return false;
    }
    if (!IsEmpty(S)) return false;
    return true;
}