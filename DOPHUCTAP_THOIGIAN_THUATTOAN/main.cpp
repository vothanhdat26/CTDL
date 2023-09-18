// Viết chương trình mô phỏng trực quan các thuật toán sắp xếp.
// Yêu cầu xuất ra được độ phức tạp, thời gian chạy của mỗi thuật toán.
// Các thuật toán cần cài đặt
// 1. Heap_sort
// 2. Merge sort
// 3. Radix sort
// 4. Quick sort
// Yêu cầu xuất ra được thời gian thực hiện và độ phức tạp của các thuật toán.
// - Đầu tiên viết hàm khởi tạo mảng ngẫu nhiên, sau đó viết các hàm sort của các thuật toán heap
// sort, merge sort, radix sort, quick sort.
// - Các hàm tinh_heapsort, tinh_mergesort, tinh_radixsort, tinh_quicksort dùng để tính thời gian
// thực hiện và độ phức tạp của các thuật toán.
// - Các hàm sort: mergesort, radixsort, quicksort thêm 2 biến là compareCount và swapCount. Hai
// biến này dùng để đếm số lần so sánh và số lần hoán đổi của các thuật toán. Riêng hàm heapsort
// không dùng 2 biến đếm này, em dùng 2 biến này tại hàm tinh_heapsort.
// - Cách tính thời gian thực hiện: đầu tiên cho mảng a với n phần tử 2 biến đếm compareCount và
// swapCount, sau đó gọi hàm tạo mảng, tạo thời gian ban đầu, gọi hàm sắp xếp tạo thời gian kết
// thúc, thời gian thực hiện bằng thời gian kết thúc trừ cho thời gian ban đầu và trả về kiểu double.
// - Cách tính độ phức tạp: 2 biến compareCount và swapCount dùng để đếm số lần so sánh và đếm
// số lần hoán đổi, xuất ra 2 giá trị này. Áp dụng công thức tính độ phức tạp của thuật toán để tính,
// hàm heapsort, mergesort với công thức n*logn, hàm quick sort cũng tương tự nhưng thêm
// trường hợp xấu với công thức n*n. Đối với radixsort thì áp dụng công thức d(n+k) , với d là số
// chữ số , n là số phần tử, k giá trị khác nhau từ 0->9 (10).
// - Xuất ra các sắp xếp theo các thuật toán là để kiểm tra xem các thuật toán đã cài đặt đúng hay
// chưa, nếu đúng thì mảng sắp xếp từ bé đến lớn.
#include "function.h"
#include<iostream>
int main()
{   
    int compareCount = 0; 
    int swapCount = 0;
    int arr[]= {12,1,3,2,5,4,8,9,6,7,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int a[n];

    cout << " \t\t\t****************************HEAP SORT****************************";
    tinh_heapsort();  
    heapsort(arr,size);
    print(arr,size);   
    cout << "\n\t\t\t****************************HEAP SORT****************************"<< endl;
    cout << endl;
    cout << "\n\t\t\t****************************MERGE SORT****************************";
    tinh_mergeSort();  
    mergeSort(arr,0,size-1,compareCount,swapCount);
    print(arr,size);
    cout << "\n\t\t\t****************************MERGE SORT****************************"<< endl;
    cout << endl;
    cout << " \n\t\t\t****************************RADIX SORT****************************";
    tinh_radixSort();
    radixSort(arr,size,compareCount,swapCount);
    print(arr,size);
    cout << "\n\t\t\t****************************RADIX SORT****************************"<< endl;    
    cout << endl;
    cout << " \n\t\t\t****************************QUICK SORT****************************";
    tinh_quicksort();  
    quickSort(a,0,size-1,compareCount,swapCount);
    print(arr,size);    
    cout << "\n\t\t\t****************************QUICK SORT****************************"<< endl; 
    system("pause");return 0;
}