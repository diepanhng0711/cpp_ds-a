#include <bits/stdc++.h>

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                std::swap(a[j], a[j - 1]);
}

void BubbleSort1(int a[], int n)
{
    int temp; // biến tạm temp
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    std::cout << "Enter the number of unsorted array's elements" << std::endl;
    std::cin >> n;

    int arr[n];
    std::cout << "Please enter each element of the array:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "The array before sorted using Insertion Sort Algorithm: " << std::endl;
    for (int i : arr)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    bubbleSort(arr, n);

    std::cout << "The array after sorted using Insertion Sort Algorithm: " << std::endl;
    for (int i : arr)
    {
        std::cout << i << "  ";
    }

    return 0;
}