#include<iostream>
#include<fstream>
using namespace std;
void docfile(int a[], int n)
{
    ifstream filein;
    filein.open(" ");
    filein >> n; 
    for(int i=0;i<n;i++)
    {
        filein >> a[i];
    }
    filein.close();
}
void ghifile(int a[], int n)
{
    ofstream fileout;
    fileout.open("");
    fileout << n << endl;
    for(int i=0;i<n;i++)
    {
        fileout << a[i] << " ";
    }
    fileout.close();
}
int main()
{

    system("pause");
    return 0;
}