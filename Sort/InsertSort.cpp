#include <iostream>

// 直接插入排序
void InsertSort(int A[], int n)
{
    int j, temp;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--)
            {
                A[j + 1] = A[j];
                A[j] = temp;
            }
            A[j + 1] = temp;
        }
    }
}
// 时间复杂度：O(n^2)，空间复杂度：O(1)，稳定

// 折半插入排序
void BInsertSort(int A[], int n)
{
    int low, high, mid, temp;
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > temp)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; j--)
        {
            A[j + 1] = A[j];
        }
        A[high + 1] = temp;
    }
}
// 时间复杂度：O(n^2)，空间复杂度：O(1)，稳定

// 希尔排序
void ShellSort(int A[], int n)
{
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2) // 步长
    {
        for (i = gap; i < n; i++) // 直接插入排序
        {
            if (A[i] < A[i - gap])
            {
                int temp = A[i];
                for (j = i - gap; j >= 0 && A[j] > temp; j -= gap)
                {
                    A[j + gap] = A[j];
                }
                A[j + gap] = temp;
            }
        }
    }
}
// 时间复杂度：O(n^1.3)，空间复杂度：O(1)，不稳定

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "原始数组：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    InsertSort(arr, size);

    std::cout << "排序结果：";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
