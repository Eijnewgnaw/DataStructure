#include <iostream>

//简单选择排序
void SelectSort(int A[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}
// 时间复杂度：O(n^2)，空间复杂度：O(1)，不稳定

//堆排序
void HeapAdjust(int A[], int s, int len)  
{
    A[0] = A[s];    //暂存根节点
    for (int j = 2 * s; j <= len; j *= 2)
    {
        if (j < len && A[j] < A[j + 1])   //找到较大的子节点
            j++;
        if (A[0] >= A[j])   //如果父节点大于子节点，跳出循环
            break;
        A[s] = A[j];    //将子节点赋值给父节点
        s = j;  //将子节点作为父节点，继续向下筛选
    }
    A[s] = A[0];    //将暂存的值赋值给最终位置
}
//时间复杂度：O(logn),下坠时间复杂度为树的高度，即logn

void BuildMaxHeap(int A[], int n)
{
    for (int i = n / 2; i >0; i--)
        HeapAdjust(A, i, n);
}
//O(n)时间建立初始堆

void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);       //建立初始堆
    for (int i = len; i > 1; i--)   //n-1趟的交换和建堆过程
    {
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        HeapAdjust(A, 1, i - 1);    //将剩余的元素整理成堆
    }
}
//共进行n-1趟排序，每趟排序的时间复杂度为O(logn)，所以总的时间复杂度为O(nlogn)
// 时间复杂度：O(nlogn)，空间复杂度：O(1)，不稳定

int main(){
    int arr[] = {0,5, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原始数组：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    HeapSort(arr,size-1);   //A[0]不存放元素

    std::cout << "排序结果：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}