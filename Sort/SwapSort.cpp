#include <iostream>

//冒泡排序
void BubbleSort(int A[], int n)
{
    int i, j, flag;
    for (i = n - 1; i >= 1; i--)
    {
        flag = 0;
        for (j = 1; j <= i; j++)
        {
            if (A[j - 1] > A[j])
            {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}
// 时间复杂度：O(n^2)，空间复杂度：O(1)，稳定

// 快速排序
int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QSort(A, low, pivotpos - 1);
        QSort(A, pivotpos + 1, high);
    }
}
// 时间复杂度：O(nlogn)，空间复杂度：O(logn)，不稳定
//最坏时间复杂度：O(n^2)，最坏空间复杂度：O(n)；取决于划分是否平衡，反应为树的深度，递归的栈空间层数

int main(){
    int arr[] = {5, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原始数组：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    QuickSort(arr, 0,size-1);

    std::cout << "排序结果：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
