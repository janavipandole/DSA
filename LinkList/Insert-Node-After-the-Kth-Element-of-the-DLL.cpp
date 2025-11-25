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
    Node *InsertAfterTheKthNode(Node *head, int val, int k)
    {
        Node *newNode = new Node(val);
        Node *curNode = head;
        Node *prevNode = head;
        for (int i = 1; i <= k; i++)
        {

            prevNode = curNode;
            if (prevNode == NULL) return head;
            curNode = curNode->next;
        }

        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (curNode)
        {
            curNode->prev = newNode;
            newNode->next = curNode;
        }

        return head;
    }

    Node *InsertBeforTheHead(Node *head, int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return head;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
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
    cout << "Insert Node after the Kth node of the DLL : " << endl;
    DLL.head = DLL.InsertBeforTheHead(DLL.head, 4);
    DLL.head = DLL.InsertBeforTheHead(DLL.head, 3);
    DLL.head = DLL.InsertBeforTheHead(DLL.head, 2);
    DLL.head = DLL.InsertBeforTheHead(DLL.head, 1);
    DLL.printDll();

    DLL.head = DLL.InsertAfterTheKthNode(DLL.head, 5, 5);
    DLL.printDll();
    return 0;
}