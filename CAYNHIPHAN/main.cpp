// Cài đặt trực quan mô phỏng 1 cây nhị phân tìm kiếm 
// gồm tạo cây, duyệt cây thêm node, xóa node, tìm kiếm phần tử trong cây
#include"function.h"
int main()
{
    BST t;
    int temp, n, key;
    cout <<endl;

    cout <<"\t\t*************************CHUONG TRINH CAY DAT CAY NHI PHAN***************************"<<endl;
    cout << "\t\tNhap so luong phan tu muon them vao : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\tNhap gia tri: ";
        cin >> temp;
        t.insert(temp);
    }
    while (true)
    {
        cout << endl;
        cout <<"\t\t==================MENU==================" << endl;
        cout << "\t\t(1) Duyet cay theo inorder (L-N-R)" << endl;
        cout << "\t\t(2) Duyet cay theo preorder (N-L-R)" << endl;
        cout << "\t\t(3) Duyet cay theo postorder (L-R-N)" << endl;
        cout << "\t\t(4) Tim kiem" << endl;
        cout << "\t\t(5) Them gia tri" << endl;
        cout << "\t\t(6) Xoa gia tri" << endl;
        cout << "\t\t(7) Exit"<<endl;
        cout << "\t\tLua chon: ";
        cin >> key;
        system("cls");
        switch (key)
        {
        case 1:
            cout << "\n\t\tduyet cay inOrder: ";
            t.InOrder();
         
            break;
        case 2:
            cout << "\n\t\tduyet cay preOrder: ";
            t.PreOrder();

            break;
        case 3:
            cout << "\n\t\tduyet cay postOrder: ";
            t.PostOrder();
            
            break;
        case 4:
            int value;
            cout << "\t\tnhap gia tri muon tim kiem: ";
            cin >> value;
            t.search(value);
          
            break;
        case 5:
            int insertValue;
            cout << "\t\tnhap gia tri muon them vao: ";
            cin >> insertValue;
            t.insert(insertValue);
         
            break;
        case 6:
            int removeValue;
            cout << "\t\tnhap gia tri muon xoa: ";
            cin >> removeValue;
            t.remove(removeValue);
          
            break;
        case 7:
        exit(1);
        default:
            break;
        }
    }
    return 0;
}