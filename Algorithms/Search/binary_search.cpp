#include<bits/stdc++.h>
using namespace std;

#include "quicksort.h"

int binarySearch(int arr[], int size, int key) {
    //l = low, h = high
    int mid, l = 0;
    int h = size - 1;

    while (l <= h) {
        mid = (l + h)/ 2;
        if (arr[mid] == key) return mid;
        else if (key < arr[mid]) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binarySearchRecursion(int arr[], int l, int h, int key) {
    if (l <= h) {
        int mid = (l + h)/ 2;

        if (arr[mid] == key) return mid;

        if (key < arr[mid]) return binarySearchRecursion(arr, l, mid - 1, key);

        return binarySearchRecursion(arr, mid + 1, h, key);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    int arr[] = {25, 9, 18, -4, 7, -22, 6, 0, -8, 14, 55, 13};
    int size = sizeof(arr) / sizeof(int);

    int key;

    cout << "Unsorted Array: " << endl;
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted Array using Quick Sort (Lomuto) Algorithms: " << endl;
    printArray(arr, size);

    cout << "Enter the number you wanna search for: " ;
    cin >> key;

    int index = binarySearch(arr, size, key);
    //int index = binarySearchRecursion(arr, 0, size - 1, key);

    cout << "Index of the element in the array = " << index << endl;
    // index = -1 <=> element not found

    return 0;
}