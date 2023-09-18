#include <iostream>
#include <fstream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_back(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    Node *&getHead()
    {
        return head;
    }
    int getLenght(Node *head)
    {
        Node *temp = head;
        int len = 0;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    void mergerSort(Node *&head)
    {
        if (head->next != NULL)
        {
            Node *head1;
            Node *head2 = head;
            int len = getLenght(head);
            for (int i = 0; i < len / 2; i++)
            {
                head1 = head2;
                head2 = head2->next;
            }
            head1->next = NULL;
            head1 = head;
            mergerSort(head1);
            mergerSort(head2);
            head = merge(head1, head2);
        }
    }
    Node *merge(Node *&head1, Node *&head2)
    {
        Node *newhead;
        if (head1 == NULL)
        {
            return head2;
        }
        else if (head2 == NULL)
        {
            return head1;
        }
        if (head1->data < head2->data)
        {
            newhead = head1;
            newhead->next = merge(head1->next, head2);
        }
        else
        {
            newhead = head2;
            newhead->next = merge(head1, head2->next);
        }
        return newhead;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void readFile(List &l)
{
    cout << "Da doc file txt: " << endl;
    int data;
    ifstream myfile("input.txt");
    while (!myfile.eof())
    {
        myfile >> data;
        l.push_back(data);
    }
    myfile.close();
}
void writeFile(List &l)
{
    ofstream myfile("output.txt");
    Node *temp = l.getHead();
    while (temp)
    {
        myfile << temp->data << " ";
        temp = temp->next;
    }
    myfile.close();
}
int main()
{
    List l;
    readFile(l);
    l.printList();
    l.mergerSort(l.getHead());
    cout << "mergeSort: " << endl;
    l.printList();
    return 0;
}