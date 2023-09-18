
#include<iostream>
#include<cstdlib> // thu vien khoi taoham srand
#include<time.h>
#include<random> // thu vien khoitao mang ngau nhien
using namespace std;
const int n= 10000;
// khoi tao mang ngau nhien
void genertaRadomArray(int a[], int n){
    srand(time(NULL)); // dam bao moi lan chay cho 1 day so ngau nhien
    for(int i=0;i<n;i++){
        a[i] = rand()%10000;
    }
}
void swap(int &a, int &b){
    int temp =a;
    a=b; 
    b=temp;
}//              HEAP SORT
void heapify(int a[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;   
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
//                  merge sort 
void merge(int a[], int left, int mid, int right, int& compareCount, int& swapCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        compareCount++; // Tăng số lần so sánh 
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
        swapCount++; // Tăng số lần hoán đổi 
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int left, int right, int& compareCount, int& swapCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid, compareCount, swapCount);
        mergeSort(a, mid + 1, right, compareCount, swapCount);
        merge(a, left, mid, right, compareCount, swapCount);
    }
}
//          RADIX SORT
int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    return mx;
}
void countSort(int a[], int n, int exp, int &compareCount, int &swapCount) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
        swapCount++;
        compareCount++;
    }
}
void radixSort(int a[], int n, int &compareCount, int &swapCount) {
    int m = getMax(a, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(a, n, exp, compareCount, swapCount);
    }
}
//          quicksort
void quickSort(int a[], int left, int right, int& compareCount, int& swapCount) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
            compareCount++; 
        }
        while (a[j] > pivot) {
            j--;
            compareCount++; 
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
            swapCount++; 
        }
    }

    if (left < j) {
        quickSort(a, left, j, compareCount, swapCount);
    }
    if (i < right) {
        quickSort(a, i, right, compareCount, swapCount);
    }
}
void tinh_heapsort()
{   
    int a[n];
    genertaRadomArray(a,n);
    clock_t start_time = clock(); // thoi gian ban dau
    heapsort(a,n);
    clock_t end_time = clock(); // thoi gian ket thuc
    cout <<"\n\t\t\tThoi gian thuc hien Heap Sort: " << double(end_time - start_time)/CLOCKS_PER_SEC << "s\n";
    // tính độ phức tạp heapsort
    int comparisons = 0, swaps = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
        comparisons += 2;
        swaps++;
    }
    cout << "\t\t\tDo phuc tap cua thuat toan Heap Sort " <<endl;
    cout <<"\t\t\tSo lan so sanh: " <<comparisons; 
    cout<< " \n\t\t\tSo lan hoan doi: " <<swaps<<endl;
    double complexity_heap = n*log10(n);
    cout <<"\t\t\tDo phuc tap thuat toan Heap sort: O(nlogn) = "<< complexity_heap<< endl;
    cout <<"\t\t\tSap xep theo Heap sort: "; 
}
void tinh_mergeSort()
{
    int compareCount = 0;
    int swapCount = 0;
    int a[10000];
    genertaRadomArray(a,n);
    clock_t start_time = clock(); // thoi gian ban dau
    mergeSort(a,0,n-1,compareCount,swapCount);
    clock_t end_time = clock(); // thoi gian ket thuc
    cout <<"\n\t\t\tThoi gian thuc hien thuat toan Merge Sort: " << double(end_time - start_time)/ CLOCKS_PER_SEC << "s\n";
      // tinh do phuc tap merge sort
    cout << "\t\t\tDo phuc tap cua thuat toan Merge Sort: " <<endl;
    cout << "\t\t\tSo lan so sanh: " << compareCount << endl;
    cout << "\t\t\tSo lan hoan doi: " << swapCount << endl;
    double complexity_merge = n*log10(n);
    cout <<"\t\t\tDo phuc tap cua thuat toan merge sort: O(nlogn)= " << complexity_merge<<endl;
    cout <<"\t\t\tSap xep theo Merge sort: "; 
}
void tinh_radixSort()
{
    int compareCount = 0;
    int swapCount =0;
    int a[n];
    genertaRadomArray(a,n);
    clock_t start_time = clock(); // thoi gian ban dau
    radixSort(a,n,compareCount,swapCount);
    clock_t end_time = clock(); // thoi gian ket thuc
    cout <<"\n\t\t\tThoi gian thuc hien thuat toan Radix Sort: " << double(end_time - start_time)/ CLOCKS_PER_SEC << "s\n";
    cout << "\t\t\tDo phuc tap cua thuat toan Radix Sort " <<endl;
    cout << "\t\t\tSo la so sanh: " << compareCount << endl;
    cout << "\t\t\tSo lan hoan doi: " << swapCount << endl;
    int d = 5; // so chu so lon nhat trong mang (10000)
    int k=10; // gia tri khac nhau tu 0->9
    double complexity_radix = d*(n+k);
    cout<<"\t\t\tDo phuc tap cua thuat toan Radix Sort: O(d*(n+k))= "<<complexity_radix <<endl;

    cout <<"\t\t\tSap xep theo Radix sort: ";
}
void tinh_quicksort()
{
    int compareCount = 0; // Số lần so sánh
    int swapCount = 0; // Số lần hoán đổi
    int a[n];
    genertaRadomArray(a,n);
    clock_t start_time = clock(); // thoi gian ban dau
    quickSort(a,0,n-1,compareCount,swapCount);
    clock_t end_time = clock(); // thoi gian ket thuc
    cout <<"\n\t\t\tThoi gian thuc hien thuat toan Quick Sort: " << double(end_time - start_time)/ CLOCKS_PER_SEC << "s\n";
    cout << "\t\t\tDo phuc tap cua thuat toan Quick Sort " <<endl;
    cout << "\t\t\tSo la so sanh: " << compareCount << endl;
    cout << "\t\t\tSo lan hoan doi: " << swapCount << endl;
    double complexity_q=n*log10(n);
    cout <<"\t\t\tDo phuc tap trong truong hop tot: O(nlogn) = "<< complexity_q<< endl;
    int  complextixy_qt=n*n;
    cout<<"\t\t\tDo phuc tap trong truong hop xau: n*n = " << complextixy_qt <<endl;
    cout <<"\t\t\tSap xep theo Quick sort: " ;
}
void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
}

