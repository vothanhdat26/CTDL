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
    void countingSort(int place)
    {
        Node *temp = head;
        const int max = 10;
        int count[max] = {};
        int output[getLenght()];
        while (temp)
        {
            count[(temp->data / place) % 10]++;
            temp = temp->next;
        }
        for (int i = 1; i < max; i++)
        {
            count[i] += count[i - 1];
        }
        temp = tail;
        while (temp)
        {
            output[count[(temp->data / place) % 10] - 1] = temp->data;
            count[(temp->data / place) % 10]--;
            temp = temp->prev;
        }
        temp = head;
        for (int i = 0; i < getLenght(); i++)
        {
            temp->data = output[i];
            temp = temp->next;
        }
    }
    void radixSort()
    {
        for (int place = 1; getMax() / place > 0; place *= 10)
        {
            countingSort(place);
        }
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
    l.radixSort();
    cout << "radixSort: " << endl;
    l.printList();
    return 0;
}