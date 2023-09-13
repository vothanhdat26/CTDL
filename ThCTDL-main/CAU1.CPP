#include<iostream>
#include<fstream>
using namespace std;
class node 
{
    public:
        int data;
        node *next;
        node *prev;
        node(int data)
        {
            this ->data =data;
            next = NULL;
            prev = NULL;
        }
};
class list 
{
private:
    node *head;
    node *tail;
public:
    list(){
    head = NULL;
    tail = NULL;
    }
void push_back(int data)
{
    node *p= new node(data);
    if (head == NULL)
    {
        head = tail = p;
    }
    else 
    {
        tail -> next =p;
        p-> prev =tail;
        tail = p;
    }
}
node *gethead()
{
    return head;
}
node *gettail()
{
    return tail;
}
void printlist()
{
    node *temp =head;
    while(temp)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void swapnode(node *a, node *b)
{
    int data = a -> data;
    a -> data = b -> data;
    b->data = data;
}
};
void readfile(list &l)
{
    cout << " da doc duoc file" << endl;
    int data;
    ifstream myfile ("./input.txt");
    while(!myfile.eof())
    {
        myfile >> data;
        l.push_back(data);
    }
    myfile.close();
}
void writelist(list &l)
{
    ofstream myfile ("output.txt");
    node *temp = l.gethead();
    while(temp)
    {
        myfile << temp -> data << " ";
        temp  = temp-> next;
        }
        myfile.close();
}
int main()
{
    list l;
    readfile(l);
    l.printlist();
    l.insertionSort();
    cout << "interchangesort" << " ";
    l.printlist();
    return 0;
}
