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
    ListNode *doubleIt(ListNode *head)
    {
        head = reverseList(head);

        int carry = 0;
        ListNode *current = head;
        ListNode *previous = nullptr;

        while (current)
        {
            int sum = carry + current->val * 2;
            current->val = sum % 10;
            carry = sum / 10;

            previous = current;
            current = current->next;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            previous->next = newNode;
        }

        return reverseList(head);
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

    head = s.insertEnd(head, 9);
    head = s.insertEnd(head, 9);
    head = s.insertEnd(head, 9);

    cout << "Double a Number Represented as a Linked List : " << endl;

    cout << "Original Linked List: " << endl;
    s.printList(head);

    cout << "After Add Two Numbers in Linked List: ";
    head = s.doubleIt(head);

    s.printList(head);

    return 0;
}