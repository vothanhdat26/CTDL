// interchangeSort selectionSort insertionSort quickSort shellSort radixSort shakerSort
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
    Node *getHead()
    {
        return head;
    }
    Node *getTail()
    {
        return tail;
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
    void swapNode(Node *a, Node *b)
    {
        int data = a->data;
        a->data = b->data;
        b->data = data;
    }

    void selectionSort()
    {

        Node *temp = head;

        while (temp)
        {
            Node *pos = temp->next;
            if (!pos)
            {
                return;
            }
            Node *min = pos;
            while (pos)
            {
                if (min->data > pos->data)
                {
                    min = pos;
                }
                pos = pos->next;
            }
            swapNode(min, temp);
            temp = temp->next;
        }
    }

    int getMax()
    {
        Node *temp = head;
        int max = temp->data;

        while (temp)
        {
            if (max < temp->data)
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }
    int getLenght()
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
};
void readFile(List &l)
{
    cout << "Da doc file txt: " << endl;
    int data;
    ifstream myfile("./input.txt");
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
    l.selectionSort();
    cout << "selectionSort: " << endl;
    l.printList();
    return 0;
}