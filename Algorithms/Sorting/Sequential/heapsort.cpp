#include<bits/stdc++.h>
using namespace std;

//Thuật toán sắp xếp vun đống heap sort
//Độ phức tạp thuật toán O(n) = n*log(n)

/*
 *  Best Case:  O(n*log n)      
 *  Worst Case: O(n*log n)      
 *  Avg Case:   O(n*log n)
*/

//Hàm hoán đổi swap với 2 tham chiếu truyền vào &a và &b
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//Thao tác vun đống heapify
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    //Luôn phải check xem l và r có nhỏ hơn n không để đảm bảo chúng luôn nằm trong mảng (là con trái/con phải)
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    //Lúc này, largest đã lưu chỉ số của thằng lớn nhất trong đống 3 node
    if (largest != i) {         //Largest khác nốt cha => swap rồi heapify tới node vừa được swap với chỉ số largest
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

//Thao tác xây dựng Max heap với thuật toán heap_Sort
void heapSort(int a[], int n) {
    //Xây dựng Max heap: duyệt từ chỉ số của node không phải node lá giảm dần
    //Node cha = n => nốt lá (nếu có) là 2n+1 và 2n+2
    //Do đó, node lớn nhất không phải node lá trong cây nhị phân hoàn chỉnh này là (n/2)-1. VD cây có 6 phần tử => (6/2) - 1 = 2 là node có chỉ số lớn nhất không phải là node lá (đúng vậy do 2 có 1 node con là node 6, đảm bảo tính đúng đắn của cây nhị phân hoàn chỉnh được xây dựng trong thuật toán heapsort)

    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    //Sau vòng for này, t đã xây dựng được max heap
    //Tiếp theo, thực hiện swap node gốc hiện tại(0) với node cuối cùng của cây(n - 1) rồi thực hiện vòng lặp tiếp tục heapify từ node gốc

    for (i = n - 1; i >= 0; i--) {
        swap(&a[i], &a[0]);

        //Đã loại bỏ node lớn nhất (đưa về cuối mảng)=> mảng lúc này chỉ còn i phần tử chưa được sắp xếp <=> node chưa sắp xếp lớn nhất mang chỉ số i - 1
        heapify(a, i, 0);
    }

}

//Hiển thị danh sách phần tử của mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}


//Cài đặt
int main() {
    int arr[] = {25, 9, 18, -4, 7, -22, 6, 0, -8, -14, 55, 13};
    int size = sizeof(arr) / sizeof(int);

    cout << "Unsorted Array: " << endl;
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted Array using Heap Sort Algorithms: " << endl;
    printArray(arr, size);
}