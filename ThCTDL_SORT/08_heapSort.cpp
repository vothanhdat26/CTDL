#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
void printArr(int arr[], int n);

void heapify(int arr[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = l + 1;
    if (l < n && arr[l] > arr[max])
    {
        max = l;
    }

    if (r < n && arr[r] > arr[max])
    {
        max = r;
    }
    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}
void heapSort(int arr[], int n, int i)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int j = n - 1; j > 0; j--)
    {

        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
}
void readFile(int arr[], int *p)
{
    cout << "Da doc file txt: " << endl;
    int data;
    ifstream myfile("input.txt");
    int i = 0;
    while (!myfile.eof())
    {
        myfile >> arr[i];
        i++;
    }
    *p = i;
    printArr(arr, *p);
    myfile.close();
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 0;
    int arr[MAX];
    readFile(arr, &n);
    cout << "heapSort: " << endl;
    heapSort(arr, n, 0);
    printArr(arr, n);
    return 0;
}