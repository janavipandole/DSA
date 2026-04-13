#include <iostream>
#include <algorithm>
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
    TreeNode *bulid(vector<int> &nums, int low, int high)
    {
        if (low > high) return NULL;

        int mid = low + (high - low) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = bulid(nums, low, mid - 1);
        root->right = bulid(nums, mid + 1, high);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return bulid(nums, 0, nums.size() - 1);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    cout << "Convert Sorted Array to Binary Search Tree : " << endl;
    TreeNode *root = s.sortedArrayToBST(nums);

    cout << root->val << endl;
    cout << root->left->val << endl;
    return 0;
}