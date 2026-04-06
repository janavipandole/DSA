#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    int binaryToDecima(string nums)
    {
        int ans = 0;
        int n = nums.size() - 1;
        int pow = 1;
        for (int i = n; i >= 0; i--)
        {
            if (nums[i] == '1')ans += pow;
            pow *= 2;
        }
        return ans;
    }
    void preOrder(TreeNode *root, string nums, int &totalSum)
    {
        if (root == nullptr) return;

        nums += to_string(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            totalSum += binaryToDecima(nums);
            return;
        }

        preOrder(root->left, nums, totalSum);
        preOrder(root->right, nums, totalSum);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        int totalSum = 0;

        if (root == NULL) return totalSum;

        preOrder(root, "", totalSum);

        return totalSum;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution s;
    cout << "Sum of Root To Leaf Binary Numbers : " << s.sumRootToLeaf(root) << endl;

    return 0;
}