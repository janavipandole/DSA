#include <iostream>
#include <vector>
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
class MyCircularDeque
{
    Node *head;
    Node *tail;
    int count = 0;
    int dequeSize = 0;

public:
    MyCircularDeque(int k)
    {
        dequeSize = k;
        head = tail = NULL;
    }

    bool insertFront(int value)
    {
        if (dequeSize == count)
            return false;

        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
            count++;
            return true;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        count++;
        return true;
    }

    bool insertLast(int value)
    {
        if (dequeSize == count)
            return false;

        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            count++;
            return true;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        return true;
    }

    bool deleteFront()
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *temp = head;
        head = head->next;

        if (head == nullptr) // last node delete hua
        {
            tail = nullptr;
        }
        count--;
        delete temp;
        return true;
    }

    bool deleteLast()
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head == tail) // only one node
        {
            delete head;
            head = tail = nullptr;
            count--;
            return true;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
        count--;
        return true;
    }

    int getFront()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->data;
    }

    int getRear()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return tail->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    bool isFull()
    {
        return dequeSize == count;
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
    cout << "Design Circular Deque : " << endl;
    MyCircularDeque Dq(5);

    Dq.insertFront(1);
    Dq.insertFront(2);
    Dq.insertFront(3);
    Dq.insertFront(4);
    Dq.insertFront(5);

    while (!Dq.isEmpty())
    {
        cout << Dq.getFront() << " ";
        Dq.deleteFront();
    }

    cout << endl;
    return 0;
}