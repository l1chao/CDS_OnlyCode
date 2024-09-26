//图的遍历基础

#include<iostream>
#define MaxVertexNum 100
#include "6.2Base.cpp"
using namespace std;

bool visited[MaxVertexNum];

//广度优先算法

void BFS(MGraph G, int v) {
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        for (w = FirstNeighbor(G, p);w >= 0;p = NextNeighbor(G, p, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void MyBFS(MGraph G, int x) {
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        visit(v);
        visited[v] = true;
        for (w = FirstNeighbor(G, v);w >= 0;w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                EnQueue(Q, w);//周围全部都要进队，更复杂了
            }
        }
    }
}

void BFSTraverse(MGraph G) {
    for (int i = 0;i < G.vexnum;i++) {
        visited[i] = false;
    }

    InitQueue(Q);
    for (int i = 0;i < G.vexnum;i++) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}

//深度优先算法
void DFS(MGraph G, int x) {
    visit(x);
    visited[x] = true;
    for (w = FirstNeighbor(G, x);w >= 0;w = NextNeighbor(G, x, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFSTraverse(MGraph G) {
    for (int i = 0;i < MaxVertexNum;i++) {
        visited[i] = false;
    }

    for (int i = 0;i < MaxVertexNum;i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

