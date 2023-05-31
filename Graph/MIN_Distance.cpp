// Description: 最短路径算法
#include <iostream>
#include <queue>

//单源最短路径：BFS；Dijkstra
//各顶点间最短路径：Floyd

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

//利用迪杰斯特拉算法，求从顶点u到其他顶点的最短路径(适用于有权图)
void Dijkstra(Graph g,int u){
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
    visited[u]=true;            // 标记u已访问
    for(int i=0;i<g.vexnum;++i){
        int min=INT_MAX;
        int v=-1;
        for(int j=0;j<g.vexnum;++j){
            if(!visited[j]&&distance[j]<min){       // 找到未访问的顶点中距离u最近的顶点
                min=distance[j];            // 更新最小值
                v=j;                    // 更新顶点
            }
        }
        if(v==-1){          // 找不到最小值，说明剩下的顶点和u不连通
            break;
        }
        visited[v]=true;
        for(int w=FirstNeighbor(g,v);w>=0;w=NextNeighbor(g,v,w)){
            if(!visited[w]&&distance[w]>distance[v]+g.arcs[v][w]){      // 更新距离
                distance[w]=distance[v]+g.arcs[v][w];   //g.arcs[v][w]表示v到w的距离
                path[w]=v;
            }
        }
    }
}

//使用邻接矩阵时，时间复杂度：O(v^2)
//边上带有负权值时，不能使用迪杰斯特拉算法

//利用弗洛伊德算法，求从顶点u到其他顶点的最短路径(适用于有权图)
void Floyd(Graph g){
    int distance[MAX_VERTEX_NUM][MAX_VERTEX_NUM];       // 从u到v的最短距离
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];        // 从u到v的最短路径上v的前一个顶点
    for(int i=0;i<g.vexnum;++i){
        for(int j=0;j<g.vexnum;++j){
            distance[i][j]=g.arcs[i][j];        // 初始化为邻接矩阵
            path[i][j]=-1;            // 初始化为-1
        }
    }
    for(int k=0;k<g.vexnum;++k){                // 顶点k作为中间顶点
        for(int i=0;i<g.vexnum;++i){            // 遍历整个矩阵
            for(int j=0;j<g.vexnum;++j){        
                if(distance[i][j]>distance[i][k]+distance[k][j]){      // 更新距离
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
}

//使用邻接矩阵时，时间复杂度：O(v^3)
//允许出现负权值边，不允许有负权值的边组成回路