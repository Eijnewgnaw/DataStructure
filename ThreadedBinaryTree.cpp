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
//找中序线索二叉树中结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        return p->lchild;
    }
    else
    {
        p = p->lchild;
        while (p->rtag == 1)
        {
            p = p->rchild;
        }
        return p;
    }
}
//对中序线索二叉树进行中序遍历
void InOrder(ThreadTree T)
{
    for (ThreadNode *p = T; p != NULL; p = NextNode(p))
    {
        cout << p->data << " ";
    }
}
//对中序线索二叉树进行逆向中序遍历
void InOrderReverse(ThreadTree T)
{
    for (ThreadNode *p = T; p != NULL; p = PreNode(p))
    {
        cout << p->data << " ";
    }
}

//找先序线索二叉树中结点p的后继结点
ThreadNode *NextNodePre(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        return p->lchild;
    }
    else
    {
        while (p->rtag == 1)
        {
            p = p->rchild;
        }
        return p->rchild;
    }
}
//对先序线索二叉树进行先序遍历
void PreOrder(ThreadTree T)
{
    for (ThreadNode *p = T; p != NULL; p = NextNodePre(p))
    {
        cout << p->data << " ";
    }
}

//找后序线索二叉树中结点p的前驱结点
ThreadNode *PreNodePost(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        return p->rchild;
    }
    else
    {
        while (p->ltag == 1)
        {
            p = p->lchild;
        }
        return p->lchild;
    }
}

//对后序线索二叉树进行后序遍历
void PostOrder(ThreadTree T)
{
    for (ThreadNode *p = T; p != NULL; p = NextNodePost(p))
    {
        cout << p->data << " ";
    }
}