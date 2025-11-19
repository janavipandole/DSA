#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(Node *node)
    {
        if (node == NULL || node->next == NULL)
        {
            cout << "Cannot delete this node!" << endl;
            return;
        }

        node->data = node->next->data;
        Node *temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main()
{
    List lst;
    cout << "Delete Node in a Linked List : " << endl;
    lst.push_front(5);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);

    lst.printLL(); // 1 2 3 4 5

    lst.deleteNode(lst.head->next->next);

    lst.printLL(); // 1 2 4 5

    return 0;
}
