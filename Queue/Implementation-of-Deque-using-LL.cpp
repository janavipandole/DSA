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
class Deque
{
    Node *head;
    Node *tail;

public:
    Deque()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "empty Queue : " << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head == nullptr) // last node delete hua
        {
            tail = nullptr;
        }

        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "emptyList";
            return;
        }

        if (head == tail) // only one node
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    int front()
    {
        if (head == nullptr)
        {
            cout << "empty Queue : " << endl;
            return -1;
        }
        return head->data;
    }

    int back()
    {
        if (head == nullptr)
        {
            cout << "empty Queue : " << endl;
            return -1;
        }
        return tail->data;
    }
    bool empty()
    {
        return head == nullptr;
    }
};
int main()
{
    cout << "Implementation of Deque using LL : " << endl;
    Deque Dq;

    Dq.push_back(1);
    Dq.push_back(2);
    Dq.push_back(3);
    Dq.push_back(4);
    Dq.push_back(5);

    while (!Dq.empty())
    {
        cout << Dq.front() << " ";
        Dq.pop_front();
    }

    cout << endl;

    return 0;
}