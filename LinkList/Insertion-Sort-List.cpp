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
    ListNode *insertionSortList(ListNode *head)
    {
        vector<int> nums;

        ListNode *temp = head;
        while (temp)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        sort(nums.begin(), nums.end());

        temp = head;
        int i = 0;

        while (temp)
        {
            temp->val = nums[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
    ListNode *insertEnd(ListNode *head, int val)
    {
        ListNode *newNode = new ListNode(val);

        if (!head)
            return newNode;

        ListNode *temp = head;
        while (temp->next)
            temp = temp->next;

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

    cout << "Insertion Sort Linked List : " << endl;

    cout << "Original Linked List: ";
    s.printList(head);

    cout << "After Insertion Sort List  ";
    head = s.insertionSortList(head);
    s.printList(head);

    return 0;
}