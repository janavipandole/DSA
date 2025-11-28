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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        int carry = 0;
        ListNode *temp = head;

        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
                sum += l1->val, l1 = l1->next;
            if (l2)
                sum += l2->val, l2 = l2->next;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
        }
        return head->next;
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

    head1 = s.insertEnd(head1, 3);
    head1 = s.insertEnd(head1, 5);

    head2 = s.insertEnd(head2, 4);
    head2 = s.insertEnd(head2, 5);
    head2 = s.insertEnd(head2, 9);
    head2 = s.insertEnd(head2, 9);

    cout << "Add Two Numbers in Linked List : " << endl;

    cout << "Original Linked List: " << endl;
    s.printList(head1);
    s.printList(head2);
    
    cout << "After Add Two Numbers in Linked List: ";
    head = s.addTwoNumbers(head1, head2);

    s.printList(head);
    return 0;
}