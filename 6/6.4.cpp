//图的应用

#include<iostream>
#include "6.2Base.h"
using namespace std;

//拓扑排序的实现
bool ToplogicalSort(ALGraph G) {
    InitStack(S);
    int indegree[MaxVertexNum];
    int print[MaxVertexNum];

    //把初始已经无入度的点压栈。
    for (int i = 0;i < G.vexnum;i++) {
        if (indegree[i] == 0) {
            Push(S, i);
        }
    }

    int cnt = 0;

    while (!IsEmpty(S)) {
        Pop(S, i);//出栈表示已访问；已访问则可以删除
        print[cnt++] = i;

        for (ArcNode* p = G.vertices[i].firstarc;p;p = p->nextarc) {
            int v = p->adjvex;
            indegree[v]--;
            if (indegree[v] == 0) {
                Push(S, v);
            }
        }
    }

    if (cnt < G.vexnum) return false;
    return true;
}


//逆拓扑排序的实现(现在不能够判断有环)
void DFS(ALGraph G, int i, bool visited[]) {
    visited[i] = true;
    for (w = FirstNeighbor(G, i);w >= 0;w = NextNeighbor(G, i, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
    printf("%d", i);
}

bool DeToplogicalSort(ALGraph G) {
    bool visited[MaxVertexNum];
    for (int i = 0;i < MaxVertexNum;i++) {
        visited[i] = false;
    }

    for (int i = 0;i < MaxVertexNum;i++) {
        DFS(G, i, visited);
    }
}

//逆拓扑排序 & 判断环路
//思路 如果有环路，深搜一定会在环路头再次被访问之前仍然待在栈里面。为了方便，这里将那些还在递归工作栈里面的点存入nowvisited数组并置对应点为true，在递归工作栈清空之前，一旦访问到了nowvisited的true元素，则表示有回路。
//注意！不能够通过计数来实现环路判断！