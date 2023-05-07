// 线索二叉树
#include <iostream>
#include <treeConstruct.cpp>
using namespace std;

// 线索二叉树结点结构
typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

// 中序遍历线索化
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL) // 根结点不为空
    {
        InThread(p->lchild, pre); // 中序遍历左子树线索化
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1; // ltag=0表示指向左孩子，ltag=1表示指向前驱
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}
// 构造中序线索二叉树
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 先序遍历线索化
void PreThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        if (p->ltag == 0) // ltag=0表示指向左孩子，ltag=1表示指向前驱，避免打转
        {
            PreThread(p->lchild, pre);
        }
        if (p->rtag == 0)
        {
            PreThread(p->rchild, pre);
        }
    }
}
// 构造先序线索二叉树
void CreatePreThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        PreThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 后序遍历线索化
void PostThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        else
        {
            p->ltag = 0;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        else
        {
            pre->rtag = 0;
        }
        pre = p;
    }
}
// 构造后续线索二叉树
void CreatePostThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        PostThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
} 

//找中序线索二叉树中结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
    if (p->rtag == 0) // rtag=0表示指向右孩子，rtag=1表示指向后继
    {
        return p->rchild;
    }
    else
    {
        p = p->rchild;
        while (p->ltag == 1)
        {
            p = p->lchild;
        }
        return p;
    }
}