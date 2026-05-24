#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        if (root == nullptr) return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> nums;
        inOrder(root, nums);
        int ans = INT_MAX;

        for (int i = 1; i < nums.size(); i++)
        {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    cout << "Minimum Absolute Difference in BST : " << s.getMinimumDifference(root) << endl;

    return 0;
}