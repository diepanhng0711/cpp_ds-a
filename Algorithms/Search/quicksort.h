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