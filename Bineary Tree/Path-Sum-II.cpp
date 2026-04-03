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
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void preOrder(TreeNode *root, int targetSum, int sum, vector<int> &ans, vector<vector<int>> &result)
    {
        if (root == nullptr) return;

        sum += root->val;
        ans.push_back(root->val);

        if (isLeaf(root) && targetSum == sum)
        {
            result.push_back(ans);
        }
    
        preOrder(root->left, targetSum, sum, ans, result);
        preOrder(root->right, targetSum, sum, ans, result);

        ans.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        if (!root) return result;

        vector<int> ans;
        preOrder(root, targetSum, 0, ans, result);

        return result;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout << "Path Sum II: " << endl;
    vector<vector<int>> ans = s.pathSum(root, 22);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}