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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *head = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val)/ 10;
        ListNode *temp = head;

        l1 = l1->next, l2 = l2->next;
        while (l1 && l2)
        {
            int sum = carry;
            sum = (sum + l1->val + l2->val);
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;

            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
        }

        while (l1)
        {
            int sum = carry;
            sum = sum + l1->val;

            l1 = l1->next;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
        }

        while (l2)
        {
            int sum = carry;
            sum = sum + l2->val;

            l2 = l2->next;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }
        head = reverseList(head);
        return head;
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
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head = NULL;
    solution s;

    head1 = s.insertEnd(head1, 5);

    head2 = s.insertEnd(head2, 5);

    cout << "Add Two Numbers II in Linked List : " << endl;

    cout << "Original Linked List: " << endl;
    s.printList(head1);
    s.printList(head2);
    cout << "After Add Two Numbers in Linked List: ";
    head = s.addTwoNumbers(head1, head2);

    s.printList(head);
    return 0;
}