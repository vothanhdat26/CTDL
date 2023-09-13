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
    void shellSort()
    {
        int len, step = 0;
        Node *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        while (2 * (3 * step + 1) <= len)
        {
            step = 3 * step + 1;
        }
        for (step; step > 0; step /= 3)
        {
            for (int i = step; i > 0; i--)
            {
                for (int j = step - i; j < len; j += step)
                {
                    Node *p = head;
                    int k = 0;
                    while (k < j)
                    {
                        p = p->next;
                        k++;
                    }
                    Node *c = p;
                    int temp = k + step;
                    while (temp <= len)
                    {
                        while (k < temp)
                        {
                            c = c->next;
                            k++;
                        }
                        if (c != NULL)
                        {
                            if (c->data <= p->data)
                            {
                                swapNode(c, p);
                            }
                        }
                        temp += step;
                    }
                }
            }
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
    l.shellSort();
    cout << "shellSort: " << endl;
    l.printList();
    return 0;
}