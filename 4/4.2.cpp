#include<iostream>
#define MAXLEN 255
using namespace std;

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

//子串在主串中的位置
int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            j++;
            i++;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j == T.length + 1) return;
    return 0;
}

int main() {

    return 0;
}