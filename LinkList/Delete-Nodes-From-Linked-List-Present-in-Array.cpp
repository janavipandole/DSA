#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *modifiedList(vector<int> &nums, Node *head)
    {
        unordered_set<int> remove(nums.begin(), nums.end());

        while (head && remove.count(head->data))
        {
            head = head->next;
        }

        Node *temp = head;
        while (temp && temp->next)
        {
            if (remove.count(temp->next->data))
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
int main()
{
    List lst;

    lst.push_front(5);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);

    lst.printLL();
    cout << "Delete Nodes From Linked List Present in Array : " << endl;

    vector<int> nums = {1, 2, 3};
    lst.head = lst.modifiedList(nums, lst.head);
    lst.printLL();

    return 0;
}
