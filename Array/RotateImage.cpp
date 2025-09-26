#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    void rotateImageBrute(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int ans[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][n - i - 1] = nums[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums[i][j] = ans[i][j];
            }
        }
        return;
    }

    void rotateImageOptimal(vector<vector<int>> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(nums[i][j], nums[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(nums[i].begin(), nums[i].end());
        }
        return;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotateImageOptimal(nums);
    for (auto val : nums)
    {
        for (auto num : val)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}