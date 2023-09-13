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
        void quickSort(Node *left, Node *right)
        {
            if (left == right)
            {
                return;
            }
            Node *pivot = right;
            Node *i = left;
            Node *j = left;

            while (j != pivot)
            {
                if (j->data <= pivot->data)
                {
                    swapNode(i, j);
                    i = i->next;
                }
                j = j->next;
            }
            swapNode(i, pivot);
            if (i != left)
            {
                quickSort(left, i->prev);
            }
            if (i != right)
            {
                quickSort(i->next, right);
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
        l.quickSort(l.getHead(), l.getTail());
        cout << "quickSort: " << endl;
        l.printList();
        return 0;
    }