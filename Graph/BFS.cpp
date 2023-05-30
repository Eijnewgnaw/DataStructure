// 广度优先搜索
#include <iostream>
#include <queue>

bool visited[MAX_VEX_NUM];

void BFSTraverse(Graph G)
{
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false; // 访问标志数组初始化
    InitQueue(Q);           // 初始化辅助队列Q
    for (int v = 0; v < G.vexnum; ++v)  // 从0号顶点开始遍历
        if (!visited[v])
            BFS(G, v); // 对尚未访问的顶点调用BFS
}
void BFS(Graph G, int v)
{
    visit(v);          // 访问初始顶点v
    visited[v] = true; // 标记v已访问
    Enqueue(Q, v);     // 顶点v入队列Q
    while (!IsEmpty(Q))
    {
        Dequeue(Q, v); // 顶点v出队列
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        { // 检测v的所有邻接点,w初始值均大于0
            if (!visited[w])
            {                      // 若w未访问
                visit(w);          // 访问顶点w
                visited[w] = true; // 标记w已访问
                Enqueue(Q, w);     // 顶点w入队列
            }
        }
    }
}
/*
广度优先遍历对于采用邻接矩阵存储的图，访问顺序不变，对于采用邻接表存储的图，访问顺序可变
对于无向图来说调用BFS函数的次数就是图的连通分量数

广度优先搜索的时间复杂度：邻接表为O(v+2e)，其中v为顶点数，e为边数；邻接矩阵为O(v^2)
广度优先搜索的空间复杂度为O(v)，其中v为顶点数
*/