#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    void postOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversalSol1(TreeNode *root)
    {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
    vector<int> postorderTraversalSol2(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st1;
        stack<int> st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();

            if (node->left != NULL)
                st1.push(node->left);
            if (node->right != NULL)
                st1.push(node->right);

            st2.push(node->val);
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top());
            st2.pop();
        }

        return ans;
    }

    vector<int> postorderTraversalSol3(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *current = root;

        while (current != NULL || !s.empty())
        {
            if (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            else
            {
                TreeNode *temp = s.top()->right;
                if (temp == NULL)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);

                    while (!s.empty() && temp == s.top()->right)
                    {
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    current = temp;
                }
            }
        }

        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    cout << "Binary Tree Postorder Traversal : " << endl;
    vector<int> ans = s.postorderTraversalSol3(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}