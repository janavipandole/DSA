#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *insertEnd(ListNode *head, int val)
    {
        ListNode *newNode = new ListNode(val);

        if (!head)
        {
            return newNode;
        }

        ListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        return head;
    }

    // Function to print DLL
    void printList(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    ListNode *head = NULL;
    solution s;

    head = s.insertEnd(head, 1);
    head = s.insertEnd(head, 2);
    head = s.insertEnd(head, 3);
    head = s.insertEnd(head, 4);
    head = s.insertEnd(head, 5);

    s.printList(head);
    cout << "Reverse The Linked List : " << endl;
    head = s.reverseList(head);
    s.printList(head);

    return 0;
}