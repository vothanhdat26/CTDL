/// cai dat thuat toan binary insertion sort
#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
// function read file
void readFile(int a[], int &n)
{
    ifstream filein;
    filein.open("input.txt");
    filein >> n;
    for (int i = 0; i < n; i++)
    {
        filein >> a[i];
    }
    filein.close();
}
// function write file
void writeFile(int a[], int n)
{
    ofstream fileout;
    fileout.open("output.txt");
    fileout << n << endl;
    for (int i = 0; i < n; i++)
    {
        fileout << a[i] << " ";
    }
    fileout.close();
}
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
    // neu high > low
    int mid = (low + high) / 2;
    if (a[mid] == item)
        return mid + 1;
    if (item > a[mid])
        // goi de quy phai
        return binarySearch(a, item, mid + 1, high);
    // goi de quy trai
    return binarySearch(a, item, low, mid - 1);
}
void binaryInsertionSort(int a[], int n)
{
    int v, j, x, h;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        h = a[i];
        v = binarySearch(a, h, 0, j);
        while (j >= v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = h;
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[MAX];
    int n;
    readFile(a, n);
    cout << "Day truoc khi sap xep:\n ";
    print(a, n);
    binaryInsertionSort(a, n);
    cout << "\nDay sau khi sap xep\n ";
    print(a, n);
    writeFile(a, n);
    return 0;
}