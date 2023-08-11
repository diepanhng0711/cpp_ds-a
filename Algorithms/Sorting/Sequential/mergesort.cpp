#include<bits/stdc++.h>
using namespace std;

/*
 *  Best Case:  O(n*log n)      =>> Dãy được sắp xếp
 *  Worst Case: O(n*log n)      =>> Dãy sắp xếp ngược
 *  Avg Case:   O(n*log n)
*/

//Merge 2 mảng con L và M vào mảng chính
void merge(int arr[], int l, int m, int h) {

    // arr_1 <- arr[l...m] 
    // arr_2 <- arr[m+1...n]
    int n1 = m - l + 1;
    int n2 = h - m;   // = h - (m + 1) + 1

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[m + 1 + j];
    }

    //Khởi tạo index cho 2 mảng con và mảng chính
    int i, j, k;
    i = 0;
    j = 0;
    k = l; //Do mảng được truyền vào bắt đầu từ l tới h

    //Thực hiện sort cho tới khi chạm đích của 1 trong hai mảng con
    //Các phần tử sót lại của mảng con còn lại sẽ được thêm vào cuối
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j] ) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2;    //tương đương với (l + h)/2 nhưng tránh tràn số khi l, h lớn
        //int m = (l + h)/ 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
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

    cout << "Unsorted Array: " << endl;
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array using Merge Sort Algorithms: " << endl;
    printArray(arr, size);

    return 0;
}