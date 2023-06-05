//分块查找
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//分块查找
typedef struct
{
    int *elem; //存储空间基址
    int length; //当前长度
    vector<int> index; //索引表
    vector<int> block; //块表
}IndexTable;

int Search_Block(IndexTable ST, int key)
{
    int i = 0;
    while (i < ST.index.size() && key > ST.index[i])
        ++i;
    int low = ST.block[i-1], high = ST.block[i]-1, mid;
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
//块间顺序查找，块内二分查找
//此代码仅供参考

/*
ASL=Li+Ls(索引查找和块内查找的平均查找长度之和)
顺序：（b+1）/2 +（s+1）/2
二分：log2(b+1) + log2(s+1)
*/