// Description: 最短路径算法
#include <iostream>
#include <queue>

//利用广度优先搜索算法，求从顶点u到其他顶点的最短路径(适用于无权图)

void BFS_MIN_DISTANCE(Graph g,int u){
    int distance[MAX_VERTEX_NUM];       // 从u到v的最短距离
    int path[MAX_VERTEX_NUM];        // 从u到v的最短路径上v的前一个顶点
    for(int i=0;i<g.vexnum;++i){
        distance[i]=INT_MAX;        // 初始化为无穷大
        path[i]=-1;            // 初始化为-1
    }
    bool visited[MAX_VERTEX_NUM];       // 访问标记数组
    for(int i=0;i<g.vexnum;++i){
        visited[i]=false;           // 初始化为false
    }
    distance[u]=0;              // u到u的距离为0
    queue<int> q;           // 辅助队列
    q.push(u);              
    while(!q.empty()){
        int v=q.pop();
        for(int w=FirstNeighbor(g,v);w>=0;w=NextNeighbor(g,v,w)){
            if(distance[w]==INT_MAX){
                visited[w]=true;    // 标记w已访问
                distance[w]=distance[v]+1;  // 更新距离
                path[w]=v;        // 更新路径
                q.push(w);      
            }
        }
    }
}