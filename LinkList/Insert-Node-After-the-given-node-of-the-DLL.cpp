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
    void InsertAfterTheGivenNode(Node *node, int val)
    {
        Node *newNode = new Node(val);

        Node *nextNode = node->next;

        if (nextNode)
        {
            newNode->next = nextNode;
            nextNode->prev = newNode;
        }

        node->next = newNode;
        newNode->prev = node;
    }
    Node *InsertAfterTheLastNode(Node *head, int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return head;
        }

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;

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
    cout << "Insert Node After the given node of the DLL : " << endl;
    DLL.head = DLL.InsertAfterTheLastNode(DLL.head, 1);
    DLL.head = DLL.InsertAfterTheLastNode(DLL.head, 2);
    DLL.head = DLL.InsertAfterTheLastNode(DLL.head, 3);
    DLL.head = DLL.InsertAfterTheLastNode(DLL.head, 4);
    DLL.head = DLL.InsertAfterTheLastNode(DLL.head, 5);
    DLL.printDll();

    DLL.InsertAfterTheGivenNode(DLL.head, 19);
    DLL.printDll();
    return 0;
}