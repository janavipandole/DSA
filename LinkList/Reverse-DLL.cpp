#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;

    ListNode(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

struct ListNode *insertEnd(ListNode *head, int val)
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
    newNode->prev = temp;

    return head;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    printList(head);
    cout << "Reverse The Doubly Linked List : " << endl;
    head = reverse(head);
    printList(head);
    return 0;
}