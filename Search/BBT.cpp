//平衡二叉树
#include <iostream>

typedef struct AVLNode {
    int data;
    int bf;     //平衡因子
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;

//查找
AVLNode *AVLSearch(AVLTree T, int key) {
    if (T == NULL) {
        return NULL;
    } else if (key == T->data) {
        return T;
    } else if (key < T->data) {
        return AVLSearch(T->lchild, key);
    } else {
        return AVLSearch(T->rchild, key);
    }
}

//对以p为根的二叉排序树作右旋处理
void R_Rotate(AVLTree &p) {
    AVLTree lc = p->lchild;     //lc指向p的左子树根结点
    p->lchild = lc->rchild;     //lc的右子树挂接为p的左子树
    lc->rchild = p;
    p = lc;                     //p指向新的根结点
}

//对以p为根的二叉排序树作左旋处理
void L_Rotate(AVLTree &p) {
    AVLTree rc = p->rchild;     //rc指向p的右子树根结点
    p->rchild = rc->lchild;     //rc的左子树挂接为p的右子树
    rc->lchild = p;
    p = rc;                     //p指向新的根结点
}

//对以指针T所指结点为根的二叉树作左平衡旋转处理
void LeftBalance(AVLTree &T) {
    AVLTree lc = T->lchild;     //lc指向T的左子树根结点
    switch (lc->bf) {
        case 1:                 //新结点插入在T的左孩子的左子树上，要作单右旋处理
            T->bf = lc->bf = 0;
            R_Rotate(T);
            break;
        case -1:                //新结点插入在T的左孩子的右子树上，要作双旋处理
            AVLTree rd = lc->rchild;    //rd指向T的左孩子的右子树根
            switch (rd->bf) {
                case 1:
                    T->bf = -1;
                    lc->bf = 0;
                    break;
                case 0:
                    T->bf = lc->bf = 0;
                    break;
                case -1:
                    T->bf = 0;
                    lc->bf = 1;
                    break;
            }
            rd->bf = 0;
            L_Rotate(T->lchild);
            R_Rotate(T);
    }
}

//对以指针T所指结点为根的二叉树作右平衡旋转处理
void RightBalance(AVLTree &T) {
    AVLTree rc = T->rchild;     //rc指向T的右子树根结点
    switch (rc->bf) {
        case -1:                //新结点插入在T的右孩子的右子树上，要作单左旋处理
            T->bf = rc->bf = 0;
            L_Rotate(T);
            break;
        case 1:                 //新结点插入在T的右孩子的左子树上，要作双旋处理
            AVLTree ld = rc->lchild;    //ld指向T的右孩子的左子树根
            switch (ld->bf) {
                case 1:
                    T->bf = 0;
                    rc->bf = -1;
                    break;
                case 0:
                    T->bf = rc->bf = 0;
                    break;
                case -1:
                    T->bf = 1;
                    rc->bf = 0;
                    break;
            }
            ld->bf = 0;
            R_Rotate(T->rchild);
            L_Rotate(T);
    }
}

//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个数据元素为e的新结点并返回1，否则返回0
int AVLInsert(AVLTree &T, int e, bool &taller) {
    if (T == NULL) {    //插入新结点，树长高，置taller为true
        T = (AVLTree) malloc(sizeof(AVLNode));
        T->data = e;
        T->lchild = T->rchild = NULL;
        T->bf = 0;
        taller = true;
    } else {
        if (e == T->data) {     //树中已存在和e有相同关键字的结点则不再插入
            taller = false;
            return 0;
        }
        if (e < T->data) {      //应继续在T的左子树中进行搜索
            if (!AVLInsert(T->lchild, e, taller)) {    //未插入
                return 0;
            }
            if (taller) {       //已插入到T的左子树中且左子树“长高”
                switch (T->bf) {
                    case 1:     //原本左子树比右子树高，需要作左平衡处理
                        LeftBalance(T);
                        taller = false;
                        break;
                    case 0:     //原本左右子树等高，现因左子树增高而使树增高
                        T->bf = 1;
                        taller = true;
                        break;
                    case -1:    //原本右子树比左子树高，现左右子树等高
                        T->bf = 0;
                        taller = false;
                        break;
                }
            }
        } else {                //应继续在T的右子树中进行搜索
            if (!AVLInsert(T->rchild, e, taller)) {    //未插入
                return 0;
            }
            if (taller) {       //已插入到T的右子树中且右子树“长高”
                switch (T->bf) {
                    case 1:     //原本左子树比右子树高，现左右子树等高
                        T->bf = 0;
                        taller = false;
                        break;
                    case 0:     //原本左右子树等高，现因右子树增高而使树增高
                        T->bf = -1;
                        taller = true;
                        break;
                    case -1:    //原本右子树比左子树高，需要作右平衡处理
                        RightBalance(T);
                        taller = false;
                        break;
                }
            }
        }
    }
    return 1;
}

