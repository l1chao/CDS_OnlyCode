//图的基本存储结构声明 & 图的基本操作声明

#include<iostream>
#define MaxVertexNum 100
using namespace std;


//邻接矩阵的声明
typedef struct {
    char Vex[MaxVertexNum]; //顶点数组。用于顶点的编号如“A”等与下标的对应。
    int Edge[MaxVertexNum][MaxVertexNum]; //边数组。
    int vexnum, arcnum; //总的顶点数和边数。
}MGraph;


//邻接表的声明
// 边/弧节点声明
typedef struct ArcNode {
    int adjvex; //将要连到的顶点编号
    struct ArcNode* nextarc; //下一个顶点编号
    //int Info; //边的权值
}ArcNode;

// 顶点节点声明
typedef struct VNode {
    int data;
    ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];

//邻接表的声明
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;


//图的常用基本操作
char FirstNeighbor(MGraph G, char x) {
    //如果节点x有邻居，则返回第1个邻居。
    return '0';
}

char NextNeighbor(MGraph G, char x, char  y) {
    //y是x的一个邻接点，则函数返回属于x的、y的下一个邻接点。
    return '0';
}
