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
    ListNode *oddEvenListBrute(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp = head;
        vector<int> nums;
        while (temp != NULL && temp->next != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) nums.push_back(temp->val);


        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) nums.push_back(temp->val);

        temp = head;
        int i = 0;
        while (temp)
        {
            temp->val = nums[i++];
            temp = temp->next;
        }
        return head;
    }
    ListNode *oddEvenListOptimal(ListNode *head)
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
    ListNode *head = NULL;
    solution s;

    head = s.insertEnd(head, 1);
    head = s.insertEnd(head, 2);
    head = s.insertEnd(head, 3);
    head = s.insertEnd(head, 4);
    head = s.insertEnd(head, 5);
    head = s.insertEnd(head, 6);

    cout << "Odd Even Linked List : " << endl;

    cout << "Original Linked List : " << endl;
    s.printList(head);

    cout << "After Odd Even Linked List :  ";
    head = s.oddEvenListBrute(head);

    s.printList(head);
    return 0;
}