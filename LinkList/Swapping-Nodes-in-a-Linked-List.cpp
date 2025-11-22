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
    Node* swapNodes(Node* head, int k) {
    Node* first = head;
    for (int i = 1; i < k; i++) first = first->next;

    Node* fast = first;
    Node* second = head;

    while (fast->next) {
        fast = fast->next;
        second = second->next;
    }

    std::swap(first->data, second->data);

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
    cout << "Swapping Nodes in a Linked List : " << endl;
    lst.swapNodes(lst.head,2);

    lst.printLL(); // 1 2 4 5

    return 0;
}
