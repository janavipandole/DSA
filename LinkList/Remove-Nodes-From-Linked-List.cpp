#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
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

    ListNode *removeNodes(ListNode *head)
    {
        head = reverseList(head);
        int maxi = 0;

        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->val >= maxi)
            {
                maxi = temp->val;
                prev = temp;
                temp = temp->next;
            }
            else
            {
                prev->next = temp->next;
                temp = prev->next;
            }
        }
        return reverseList(head);
    }

    ListNode *insertEnd(ListNode *head, int val)
    {
        ListNode *newNode = new ListNode(val);

        if (!head) return newNode;

        ListNode *temp = head;
        while (temp->next) temp = temp->next;

        temp->next = newNode;

        return head;
    }

    // Function to print DLL
    void printList(ListNode *head)
    {
        ListNode *temp = head;
       
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    ListNode *head = NULL;
    solution s;

    head = s.insertEnd(head, 5);
    head = s.insertEnd(head, 2);
    head = s.insertEnd(head, 13);
    head = s.insertEnd(head, 3);
    head = s.insertEnd(head, 8);
    cout<<"Remove Nodes From Linked List : "<< endl;
    cout << "Original Linked List: ";
    s.printList(head);
    cout << "After remove Nodes From Linked List: ";
    head = s.removeNodes(head);
    s.printList(head);

    return 0;
}