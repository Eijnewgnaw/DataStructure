//并查集
#include<iostream>

//结点结构
typedef struct Node
{
    int data;   //结点数据
    int parent; //双亲位置
}PTNode;        //结点类型

typedef struct
{
    PTNode nodes[100];  //结点数组
    int n;            //结点数
}PTree;              //树类型

//初始化
void Init(PTree &t)
{
    for (int i = 0; i < t.nodes.size(); i++)
    {
        t.nodes[i].parent = -1;
        t.nodes[i].data = i;
    }
    t.n = t.nodes.size();
}
//初始化只将每个结点的双亲位置初始化为-1，实际根据各树图形将双亲位置初始化为相应的值

//查找, O(n)
int Find(PTree t, int x)
{
    while (t.nodes[x].parent >= 0)
    {
        x = t.nodes[x].parent;
    }
    return x;
}

//合并，O(1)
void Union(PTree &t, int x1, int x2)
{
    int root1 = Find(t, x1);
    int root2 = Find(t, x2);
    if (root1 != root2)
        t.nodes[root2].parent = root1;
}

/*查找的时间复杂度与元素所处位置树高有关，因此在合并时应尽量使树高大的树作为根，树高小的树作为子树
  1.按秩合并：将树高小的树作为子树，树高大的树作为根
  2.路径压缩：在查找时，将路径上的所有结点直接连接到根结点上
  3.按秩合并+路径压缩
*/

//将各棵树的根节点的parent设置为树的高度的负值
//按秩合并，O(logn)
void Union(PTree &t, int x1, int x2)
{
    int root1 = Find(t, x1);
    int root2 = Find(t, x2);
    if (root1 != root2)
    {
        if (t.nodes[root1].parent < t.nodes[root2].parent)  //越小树越高
        {
            t.nodes[root1].parent += t.nodes[root2].parent; //小树合并到大树
            t.nodes[root2].parent = root1;
        }
        else
        {
            t.nodes[root2].parent += t.nodes[root1].parent;
            t.nodes[root1].parent = root2;
        }
    }
}

//路径压缩，O(α(n)),α(n)为阿克曼函数的反函数，α(n)为任何实际应用中出现的最大值,α(n)≤4
int Find(PTree &t, int x)
{
    if (t.nodes[x].parent < 0)
        return x;
    else
    {
        int root = Find(t, t.nodes[x].parent);
        while (x!=root)     //路径压缩
        {
            int tmp = t.nodes[x].parent;    //保存x的双亲
            t.nodes[x].parent = root;   //x的双亲设置为根
            x = tmp;        //继续处理查找路径上的结点
        }
        return root;
    }
}