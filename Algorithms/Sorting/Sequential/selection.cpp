#include<bits/stdc++.h>

void SwapValue(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min]) min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}

int main() {
    int n;
    
    std::cout << "Enter the number of unsorted array's elements" << std::endl; 
    std::cin >> n;

    int arr[n];
    std::cout << "Please enter each element of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "The array before sorted using Selection Sort Algorithm: " << std::endl;
    for(int i : arr) {
        std::cout << i << "  " ;
    }
    std::cout << std::endl;
    
    selectionSort(arr, n);
    // insertionSort2(arr, n);

    std::cout << "The array after sorted using Selection Sort Algorithm: " << std::endl;
    for (int i: arr) {
        std::cout << i << "  ";
    }

    return 0;
}