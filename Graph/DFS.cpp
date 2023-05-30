//深度优先遍历
#include <iostream>

bool visited[MAX_VERTEX_NUM];   //访问标记数组

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; ++v) {
        visited[v] = false;     //访问标记数组初始化
    }
    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v]) {
            DFS(G, v);          //对尚未访问的顶点调用DFS
        }
    }
}

void DFS(Graph G, int v) {
    visited[v] = true;          //标记v已访问
    Visit(v);                   //访问第v个顶点
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);          //对v的尚未访问的邻接顶点w递归调用DFS
        }
    }
}
/*
深度优先类似于树的先序遍历
空间复杂度：O(v)
时间复杂度：邻接表O(v+2e)；邻接矩阵O(v^2)
对于时间复杂度的分析都是遍历顶点以及边
*/