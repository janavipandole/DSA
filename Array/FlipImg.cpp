#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> flipImg(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            reverse(nums[i].begin(), nums[i].end());
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == 1)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    ans[i][j] = 1;
                }
            }
        }
        return ans;
    }

    int countNegativesBrute(vector<vector<int>> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        int m = nums[0].size();

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (nums[i][j] >= 0)
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int countNegativesOptimal(vector<vector<int>> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        int m = nums[0].size();

        for (int i = n - 1; i >= 0; i--)
        {
            int row = i;
            for (int j = 0; j < n; j++)
            {
                if (nums[row][j] >= 0)
                {
                    break;
                }
                else
                {
                    cnt += row - j + 1;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums1 = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << "count Negatives : " << s.countNegativesOptimal(nums1);
    cout << endl;

    vector<vector<int>> nums2 = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> ans = s.flipImg(nums2);

    for (auto values : ans)
    {
        for (auto val : values)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
