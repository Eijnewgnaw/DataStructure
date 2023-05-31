/*
最小生成树（Minimum-Spanning-Tree,MST）
Prim算法:
    1. 从图中任意选取一个顶点作为起始顶点，标记为已访问
    2. 从与已访问顶点相邻的顶点中选取权值最小的边，标记为已访问
    3. 重复第二步，直到所有顶点都被访问
    时间复杂度: O(n^2)
Kruskal算法:
    1. 将图中的所有边按权值从小到大排序
    2. 从权值最小的边开始，如果这条边的两个顶点不在同一个连通分量中，则将这条边加入最小生成树中
    3. 重复第二步，直到所有顶点都在同一个连通分量中
    时间复杂度: O(eloge)
*/

void Prim(Graph g)
{
    int lowcost[MAX_VERTEX_NUM];  // 保存顶点到已访问顶点的最小权值
    int adjvex[MAX_VERTEX_NUM];   // 保存顶点到已访问顶点的最小权值的那个已访问顶点
    bool visited[MAX_VERTEX_NUM]; // 访问标记数组
    for (int i = 0; i < g.vexnum; ++i)
    {
        lowcost[i] = g.arcs[0][i].adj; // 初始化lowcost数组
        adjvex[i] = 0;                 // 初始化adjvex数组
        visited[i] = false;            // 初始化visited数组
    }
    visited[0] = true; // 选取0号顶点作为起始顶点
    for (int i = 1; i < g.vexnum; ++i)
    {
        int min = INT_MAX;
        int k = -1;
        for (int j = 0; j < g.vexnum; ++j)
        {
            if (!visited[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        if (k != -1)
        {
            cout << adjvex[k] << "-" << k << endl; // 输出最小生成树的一条边
            visited[k] = true;                     // 标记k已访问
            for (int j = 0; j < g.vexnum; ++j)
            {
                if (!visited[j] && g.arcs[k][j].adj < lowcost[j])
                {
                    lowcost[j] = g.arcs[k][j].adj;
                    adjvex[j] = k;
                }
            }
        }
    }
}

void Kruskal(Graph g)
{
    int parent[MAX_VERTEX_NUM]; // 保存顶点的父节点
    for (int i = 0; i < g.vexnum; ++i)
    {
        parent[i] = -1; // 初始化parent数组
    }
    for (int i = 0; i < g.arcnum; ++i)
    {
        int v1 = Find(parent, g.edges[i].begin);
        int v2 = Find(parent, g.edges[i].end);
        if (v1 != v2)
        {
            cout << g.edges[i].begin << "-" << g.edges[i].end << endl; // 输出最小生成树的一条边
            parent[v1] = v2;                                           // 将v1的父节点设为v2,类似于并查集按秩合并
        }
    }
}