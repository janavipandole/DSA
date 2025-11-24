#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
public:
    Node *head;
    DoublyList()
    {
        head = NULL;
    }
    Node *InsertBeforTheLastNode(Node *head, int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return head;
        }

        if (head->next == NULL)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return head;
        }

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
        newNode->next = temp;

        return head;
    }

    void printDll()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    DoublyList DLL;
    cout << "Insert Node befor the Head of the DLL : " << endl;
    DLL.head = DLL.InsertBeforTheLastNode(DLL.head, 1);
    DLL.head = DLL.InsertBeforTheLastNode(DLL.head, 2);
    DLL.head = DLL.InsertBeforTheLastNode(DLL.head, 3);
    DLL.head = DLL.InsertBeforTheLastNode(DLL.head, 4);
    DLL.head = DLL.InsertBeforTheLastNode(DLL.head, 5);

    DLL.printDll();
    return 0;
}