#include<bits/stdc++.h>
using namespace std;

/*
 *  Best Case:  O(n*log n)      =>> Dãy được chia đều sau mỗi lần phân đoạn
 *  Worst Case: O(n^2)          =>> Dãy bị chia thành 1 mảng gần = 0 và 1 mảng gần bằng n - 1 sau phân đoạn
 *  Avg Case:   O(n*log n)
*/


//----------------------------------------------------------------
// Thuật toán Quicksort (Lomuto)
// O(n): nlogn
// Trường hợp tồi nhất: n^2

/*
 * THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) - PHÂN HOẠCH LOMUTO
 * Ý tưởng thuật toán:
 * - Đặt pivot(chốt) tại phần tử cuối cùng của dãy
 * - Chỉ số i bắt đầu từ l - 1 (left - 1)
 * - Bắt đầu thực hiện phân vùng Partition với dãy a, l, r Partition(a, l, r)
 * - Duyệt từ phần tử đầu tiên của dãy (l) với chỉ số j
 * - Nếu a[j] < pivot => i++ (++i), sau đó thực hiện swap a[j] với a[i]
 *    =>> Mục đích, tạo ra: || phân vùng trái với các phần tử nhỏ hơn pivot
                            || phân vùng phải với các phần tử lớn hơn pivot
 * - Sau khi phân vùng xong, i++ (++i) rồi thực hiện swap để đưa pivot vào giữa 2 phân vùng
 * - Lúc này, phân vùng trái luôn nhỏ hơn pivot, phân vùng phải luôn lớn hơn pivot
 * - Thực hiện đệ quy thuật toán Quicksort với 2 phân vùng trái: Quicksort(a, l, pivot - 1) và phân vùng Quicksort(a, pivot + 1, r) 
 */

//NHƯỢC ĐIỂM: nếu dãy đã sắp xếp tăng dần, dãy vẫn tiếp tục phân vùng và sắp xếp

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//Hàm dùng để sắp xếp lại từng phân vùng mảng
int partition(int arr[], int l, int h) {
    //l: low _ h: high
    //Chọn phần tử rightmost làm pivot 
    int pivot = arr[h];

    //Con trỏ trỏ tới phần tử lớn hơn
    int i = (l - 1);

    //Duyệt qua từng phần tử của mảng, so sánh chúng với pivot
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            //Nếu phần tử nhỏ hơn pivot đc tìm thấy 
            //Đổi chỗ nó với phần tử lớn hơn pivot được trỏ tới bởi y
            i++;

            //Đổi chỗ phần tử tại i và tại j
            swap(&arr[i], &arr[j]);
        }
    }

    //Đưa con trỏ i về phần tử đầu tiên lớn hơn pivot
    i++;
    //Đổi chỗ phần tử lớn hơn tại i với pivot => pivot được sắp xếp vào đúng vị trí
    swap(&arr[i], &arr[h]);

    
    //Trả lại vị trí phân đoạn 
    return i;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        // Phân đoạn lần đầu để đưa rightmost về đúng vị trí
        int pivot = partition(arr, l, h);

        //Sau đó, thực hiện sắp xếp đệ quy với 2 phân đoạn (arr, l, p - 1) và (arr, p + 1, h)
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
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

    quickSort(arr, 0, size - 1);

    cout << "Sorted Array using Quick Sort (Lomuto) Algorithms: " << endl;
    printArray(arr, size);
}