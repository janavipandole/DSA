#include <iostream>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;

        if (!root1 && !root2) return ans;

        inOrder(root1, ans);
        inOrder(root2, ans);

        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    struct TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(0);

    struct TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(0);

    Solution s;
    cout << "All Elements in Two Binary Search Trees : " << endl;
    vector<int> ans = s.getAllElements(root1, root2);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}