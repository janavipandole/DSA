#include <iostream>
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
    vector<int> nextLargerNodes(Node *head)
    {
        vector<int> nums;

        if (head->next == NULL) return {0};

        Node *temp = head;

        while (temp)
        {
            nums.push_back(temp->data);
            temp = temp->next;
        }

        stack<int> s;
        vector<int> ans(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = s.top();
            }

            s.push(nums[i]);
        }

        return ans;
    }
};
int main()
{

    List lst;

    lst.push_front(5);
    lst.push_front(3);
    lst.push_front(4);
    lst.push_front(7);
    lst.push_front(2);

    lst.printLL();
    cout << "Next Greater Node In Linked List : " << endl;

    vector<int> ans = lst.nextLargerNodes(lst.head);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
