#include<iostream>

void insertionSort(int arr[], int array_size) {
    int i, j, last;
    
    for (int i = 1; i < array_size; i++) {
        last = arr[i];
        j = i;

        while (j > 0 && arr[j-1] > last) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = last;
    }
}

void insertionSort2(int x[], int n) {
    int i, j;
    int next;
    for (i = 1; i < n; i++) {
        next = x[i];
        for (j = i-1; j >= 0 && (next < x[j]); j--) {
            x[j+1] = x[j];
        }
        x[j+1] = next;
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

    std::cout << "The array before sorted using Insertion Sort Algorithm: " << std::endl;
    for(int i : arr) {
        std::cout << i << "  " ;
    }
    std::cout << std::endl;
    
    insertionSort(arr, n);
    // insertionSort2(arr, n);

    std::cout << "The array after sorted using Insertion Sort Algorithm: " << std::endl;
    for (int i: arr) {
        std::cout << i << "  ";
    }

    return 0;
}