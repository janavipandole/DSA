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
        else
        {
            newNode->next = head;
            head = newNode;
        }
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

    Node *deleteNode(Node *head, int x)
    {
        if (head == nullptr)
            return head;

        Node *temp = head;
        if (x == 1)
        {
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = 0;
        Node *prev = nullptr;
        while (temp != nullptr)
        {
            cnt++;
            if (cnt == x)
            {
                prev->next = temp->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
    List lst;

    lst.push_front(5);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);

    lst.printLL(); // 1 2 3 4 5
    cout << "Delete in a Singly Linked List : " << endl;
    lst.deleteNode(lst.head, 3);

    lst.printLL(); // 1 2 4 5

    return 0;
}
