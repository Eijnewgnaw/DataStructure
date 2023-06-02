//拓扑排序
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;
vector<int> G[MAXN];
int inDegree[MAXN];
int n, m;

bool topologicalSort() {
    int num = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0) {
                q.push(v);
            }
        }
        G[u].clear();       //清空该点的所有出边
        num++;
    }
    if(num == n) {
        return true;
    } else {
        return false;
    }
}