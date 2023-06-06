//二叉排序树
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct BSTNode {
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//查找
BSTNode *BSTSearch(BSTree T, int key) {
    if (T == NULL) {
        return NULL;
    } else if (key == T->data) {
        return T;
    } else if (key < T->data) {
        return BSTSearch(T->lchild, key);
    } else {
        return BSTSearch(T->rchild, key);
    }
}

//插入
bool BSTInsert(BSTree &T, int key) {
    if (T == NULL) {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    } else if (key == T->data) {
        return false;
    } else if (key < T->data) {
        return BSTInsert(T->lchild, key);
    } else {
        return BSTInsert(T->rchild, key);
    }
}

//构造二叉排序树
void CreateBST(BSTree &T, int *a, int n) {
    T = NULL;
    for (int i = 0; i < n; i++) {
        BSTInsert(T, a[i]);
    }
}

//删除
bool BSTDelete(BSTree &T, int key) {
    if (T == NULL) {
        return false;
    } else if (key == T->data) {
        BSTNode *p = T;
        if (T->lchild == NULL) {
            T = T->rchild;
        } else if (T->rchild == NULL) {
            T = T->lchild;
        } else {                        //左右子树均不空
            BSTNode *s = T->lchild;     //s指向左子树根结点
            while (s->rchild) {
                s = s->rchild;
            }                       //s指向左子树中值最大的结点,即中序遍历直接前驱；此处也可用T->rchild的最小值代替
            s->rchild = T->rchild;  //s的右子树为T的右子树
            T = T->lchild;        
        }
        free(p);
        return true;
    } else if (key < T->data) {
        return BSTDelete(T->lchild, key);
    } else {
        return BSTDelete(T->rchild, key);
    }
}