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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

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
    ListNode *head2 = NULL;
    ListNode *head = NULL;
    solution s;

    head2 = s.insertEnd(head2, 4);
    head2 = s.insertEnd(head2, 5);
    head2 = s.insertEnd(head2, 9);
    head2 = s.insertEnd(head2, 9);

    cout << "Odd Even Linked List : " << endl;

    cout << "Original Linked List : " << endl;
    s.printList(head2);

    cout << "After Odd Even Linked List :  ";
    head = s.oddEvenList(head2);

    s.printList(head);
    return 0;
}