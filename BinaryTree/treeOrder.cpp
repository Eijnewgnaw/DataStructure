#include <iostream>
//二叉树的结点
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//二叉树的递归遍历
//先序遍历
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data); //显示结点数据，可以更改为其他对结点操作
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

//二叉树的非递归遍历
//先序遍历
void PreOrderTraverse2(BiTNode* T)
{
    if(T==NULL)return;
    InitStack(S);
    push(S,T);
    while(!IsEmpty(S))
    {
        Pop(S,p);
        visit(p);                                               //访问当前节点
        if(p->rchild!=NULL)push(S,p->rchild);                   //右孩子先入栈==>后出栈，后处理右子树
        if(p->lchild!=NULL)push(S,p->lchild);                   //左孩子后入栈==>先出栈，先处理左子树
    }
}

//中序遍历
void goAlongLeftBranch(BiTNode* p)
{
    while(p!=NULL)
    {
        push(S,p);
        p=p->lchild;
    }
}
void InOrderTraverse2(BiTNode* T)
{
    if(T==NULL)return;
    InitStack(S);
    goAlongLeftBranch(T);                               //从根节点开始，一直向左走，直到叶子节点
    while(!IsEmpty(S))
    {
        Pop(S,p);
        visit(p);
        goAlongLeftBranch(p->rchild);                    //左孩子先入栈==>后出栈，后处理左子树
    }
}

//后序遍历
void PostOrderTraverse2(BiTNode* T)
{
    if(T==NULL)return;
    InitStack(S);                                    //主栈用来实现根右左递归遍历
    push(T);
    initstack(S2);                                   //辅助栈用来实现左右根递归遍历
    while(!IsEmpty(S))
    {
        Pop(S,p);
        push(S2,p);
        if(p->lchild!=NULL)push(S,p->lchild);        //左孩子先入栈==>后出栈，后处理左子树
        if(p->rchild!=NULL)push(S,p->rchild);        //右孩子后入栈==>先出栈，先处理右子树
    }
    while(!IsEmpty(S2))                             //辅助栈出栈，即为左右根遍历
    {
        Pop(S2,p);
        visit(p);
    }
}

//二叉树的层次遍历
void LevelOrderTraverse(BiTree T)
{
    if(T==NULL)return;
    InitQueue(Q);
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL)EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)EnQueue(Q,p->rchild);
    }
}