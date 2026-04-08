#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    string serialize(Node *root)
    {
        string ans;
        if (root == NULL) return ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();

                if (node == NULL)
                {
                    ans += "#,";
                    continue;
                }

                ans += to_string(node->data) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    Node *deserialize(string data)
    {
        if (data.size() == 0)return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        queue<Node *> q;
        Node *root = new Node(stoi(str));
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") node->left = NULL;
            else
            {
                node->left = new Node(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if (str == "#") node->right = NULL;
            else
            {
                node->right = new Node(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution s;

    cout << "Serialize and Deserialize Binary Tree : " << endl;
    string str = s.serialize(root);
    cout << "Serialize : " << str << endl;

    cout << "Deserialize : " << endl;
    Node *temp = s.deserialize(str);
    cout << temp->data << endl;
    cout << temp->left->data << " ";
    cout << temp->right->data << endl;
    cout << temp->right->left->data << " ";
    cout << temp->right->right->data << endl;

    return 0;
}