//顺序查找和二分查找
#include <iostream>

//查找表数据结构
typedef struct
{
    int *elem; //存储空间基址
    int length; //当前长度
}SSTable;

//顺序查找
int Search_Seq(SSTable ST, int key)
{
    ST.elem[0] = key; //哨兵
    for (int i = ST.length; ST.elem[i] != key; --i)
        return i; //查找成功返回其下标
    return 0; //查找失败返回0
}

/*
ASL(Average Search Length)平均查找长度
ASL = Pi * Ci
Pi为查找表中第i个数据元素的概率
Ci为查找第i个数据元素时已经比较过的次数
ASL成功 = 1/n * (1+2+...+n) = (n+1)/2
ASL不成功=n+1
*/

//二分查找
int Search_Bin(SSTable ST, int key)
{
    int low = 1, high = ST.length-1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ST.elem[mid] == key)
            return mid;
        else if (ST.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
/*
判定树是一颗平衡二叉树，其深度为h=log2(n+1)
二分查找的时间复杂度为O(log2n)
ASL成功 = 1/n * (1x1+2x2+...+hx2^(h-1)) ≈ log(n+1)-1 
*/