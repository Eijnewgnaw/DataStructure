//拓扑排序
#include <iostream>

int print[MAX_VERTEX_NUM];  //存放拓扑排序结果
int inDegree[MAXN_VERTEX_NUM];  //存放每个点的入度

bool topologicalSort() {
   InitStack(S);
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            Push(S, i);
        }
    }
    int count = 0;
    while (!IsEmpty(S)) {
        Pop(S,i);
        print[count++]=i;   //将弹出的顶点加入拓扑排序结果中
        for (p=G.vertices[i].firstarc; p; p=p->nextarc) {
            v = p->adjvex;      //找到顶点v的邻接点
            inDegree[v]--;    //将顶点v的邻接点的入度减1
            if (inDegree[v] == 0) {
                Push(S, v);
            }
        }
    }
    if (count < G.vexnum) {
        return false;
    } else {
        return true;
    }
}