//涵盖内容：
//广搜的基本算法（抽象实现，邻接矩阵实现，邻接表实现）
//广搜实现单源最短路径寻找
//深搜的基本算法

#include<iostream>
#define MaxVertexNum 100
#include "6.2Base.h"
using namespace std;

bool visited[MaxVertexNum];

//注意，进出队都用外参数v；找邻接点都用循环内声明的循环因子w

//广度优先算法
void BFS(MGraph G, int v) {
    visit(v);//d[v] = 0;
    visited[v] = true;
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        //下面的w>=0是因为NextNeighbor遍历到最后元素会返回-1。
        //都适用数字来代替节点名称进行遍历的。
        for (w = FirstNeighbor(G, v);w >= 0;w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);//d[w] = d[v]+1;
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
        // 如果是邻接矩阵的循环：
        // for (w = 0;w < G.vexnum;w++) {
        //     if (visit[w] == false && G.Edge[v][w] == 1) {//后面那个条件是说v和w有边才进入循环。
        //         visit[w];
        //         visit(w);
        //         EnQueue(w);
        //     }
        // }

        // 如果是邻接表的循环：
        // for (p = G.vertices[v].firstarc;p;p = p->nextarc) {
        //     w = p->adjvex;//p边表节点弧头元素
        //     if (visit[w] == false) {
        //         visit(w);
        //         visit[w] = true;
        //         EnQueue(Q, w);
        //     }
        // }
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

//单源最短路径
// ...

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

