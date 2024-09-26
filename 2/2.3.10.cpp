#include<iostream>
using namespace std;

typedef struct LNode {
    int val;
    struct LNode* next;
}LNode, * LinkList;


//判定son是否是dad的连续子序列
//注意，先掌握基础的、待优化的算法，这样才能够更加深刻的把握优化算法的好处。
//最最简陋的做法是：父串i开始，和子串比了一会发现不匹配。发现不匹配后，立即父串指针跳到i+1，再进行下一轮和子串的匹配。
bool IsSubSeq(LinkList dad, LinkList son) {
    if (dad->next == NULL || son->next == NULL) {
        return false;
    }

    LNode* pdad = dad->next;
    LNode* pson = son->next;

    while (pdad != NULL) {
        if (pdad->val == pson->val) {
            LNode* p = pdad->next;
            LNode* q = pson->next;
            while (q != NULL) {
                if (p->val != q->val) {
                    break;
                }
                p = p->next;
                q = q->next;
            }
            return true;
        }
        pdad = pdad->next;
    }
}

int Pattern(LinkList A, LinkList B) {
    LNode* p = A->next;
    LNode* q = B->next;
    LNode* pre = p;

    while (p && q) {
        if (p->val == q->val) {
            p = p->next;
            q = q->next;
        }
        else {
            pre = pre->next;
            p = pre;
            q = B->next;
        }
    }

    if (!q) return 1;
    return 0;
}

int Pattern1(LinkList A, LinkList B) {

}