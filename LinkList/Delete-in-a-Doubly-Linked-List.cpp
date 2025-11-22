#include <iostream>
using namespace std;
//  Structure of Node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    Node *delPos(Node *head, int x)
    {
        if (!head) return head; // Empty list → nothing to delete

        // Case 1: delete head node
        if (x == 1)
        {
            Node *temp = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return head;
        }

        Node *temp = head;
        int cnt = 1;

        // Move to the x-th node
        while (temp && cnt < x)
        {
            temp = temp->next;
            cnt++;
        }

        // If x is out of range (larger than length)
        if (!temp) return head;

        // Node to delete is temp
        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;

        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;

        delete temp;

        return head;
    }

    // Function to print DLL
    void printList(Node *head)
    {
        Node *temp = head;
        cout << "List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *insertEnd(Node *head, int val)
    {
        Node *newNode = new Node(val);

        if (!head)
            return newNode;

        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        return head;
    }
};
int main()
{
    Node *head = NULL;
    cout << "Delete in a Doubly Linked List : " << endl;
    Solution obj;
    head = obj.insertEnd(head, 1);
    head = obj.insertEnd(head, 2);
    head = obj.insertEnd(head, 3);
    head = obj.insertEnd(head, 4);
    head = obj.insertEnd(head, 5);
    head = obj.insertEnd(head, 6);
    head = obj.insertEnd(head, 7);
    head = obj.insertEnd(head, 8);
    cout << "Original DLL: ";
    obj.printList(head);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    head = obj.delPos(head, pos);

    cout << "After deletion: ";
    obj.printList(head);

    return 0;
}