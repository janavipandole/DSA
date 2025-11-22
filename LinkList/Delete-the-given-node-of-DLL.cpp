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
    Node *delNode(Node *head,Node *node)
    {
        if(head == node) return head;

        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;

        // free(node);
        delete node;

        return head;
    }

    // Function to print DLL
    void printList(Node *head)
    {
        Node *temp = head;
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

        if (!head)return newNode;

        Node *temp = head;
        while (temp->next) temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        return head;
    }
};
int main()
{
    Node *head = NULL;
    cout << "Delete the given node of Doubly Linked List : " << endl;
    Solution obj;
    head = obj.insertEnd(head, 1);
    head = obj.insertEnd(head, 2);
    // head = obj.insertEnd(head, 3);
    // head = obj.insertEnd(head, 4);
    // head = obj.insertEnd(head, 5);
    // head = obj.insertEnd(head, 6);
    // head = obj.insertEnd(head, 7);
    // head = obj.insertEnd(head, 8);
    cout << "Original DLL: ";
    obj.printList(head);

    head = obj.delNode(head, head->next);

    cout << "After deletion: ";
    obj.printList(head);

    return 0;
}