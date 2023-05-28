#include<iostream>

//邻接矩阵
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];        //顶点表
    EdgeType arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //邻接矩阵
    int vexnum, arcnum;                    //图的当前顶点数和弧数
} MGraph;

//邻接表
typedef struct ArcNode {    //边表结点
    int adjvex;             //该弧所指向的顶点的位置
    struct ArcNode *next;   //指向下一条弧的指针
    //InfoType info;        //网的边权值
} ArcNode;
typedef struct VNode {      //顶点表结点
    VertexType data;        //顶点信息
    ArcNode *first;         //指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;       //邻接表
    int vexnum, arcnum;     //图的当前顶点数和弧数
} ALGraph;

//十字链表
typedef struct ArcBox {     //弧结点
    int tailvex, headvex;   //该弧的尾和头结点的位置
    struct ArcBox *hlink, *tlink;   //分别指向弧头相同和弧尾相同的弧的链域
    //InfoType info;        //该弧相关信息的指针
} ArcBox;
typedef struct VexNode {    //顶点结点
    VertexType data;        //顶点信息
    ArcBox *firstin, *firstout;     //分别指向该顶点第一条入弧和出弧
} VexNode;
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];  //表头向量
    int vexnum, arcnum;             //有向图的当前顶点数和弧数
} OLGraph;

//邻接多重表
typedef struct ArcNode {    //边表结点
    bool mark;              //访问标记
    int ivex, jvex;         //该边依附的两个顶点的位置
    struct ArcNode *ilink, *jlink;  //分别指向依附这两个顶点的下一条边
    //InfoType info;        //该边相关信息的指针
} ArcNode;
typedef struct VexNode {    //顶点表结点
    VertexType data;        //顶点信息
    ArcNode *firstedge;     //指向第一条依附该顶点的边的指针
} VexNode;
typedef struct {
    VexNode adjmulist[MAX_VERTEX_NUM];  //邻接表
    int vexnum, arcnum;                 //图的当前顶点数和弧数
} AMLGraph;

/*
                邻接表                                   邻接矩阵        十字链表       邻接多重表    
空间复杂度     有向图O(|V|+|E|)；无向图O(|V|+2|E|)         O(|V|^2)      O(|V|+|E|)     O(|V|+|E|)
适用于        稀疏图                                     稠密图        有向图         无向图
*/