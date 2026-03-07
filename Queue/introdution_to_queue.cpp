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
class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int val)
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

    void pop()
    {
        if (head == nullptr)
        {
            cout << "empty Queue : " << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
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
    bool empty()
    {
        return head == nullptr;
    }
};
int main()
{
    cout << "Implementation of Queue using LL : " << endl;
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    cout << q.empty() << endl;

    return 0;
}